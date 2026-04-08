extends Node
class_name TestRunner

const COLOR_SUCCESS := "#22c55e"
const COLOR_ERROR := "#ef4444"
const COLOR_INFO := "#3b82f6"
const COLOR_DEBUG := "#9ca3af"

var log_label: RichTextLabel
var indent_level: int = 0
var total_passed: int = 0
var total_failed: int = 0
var is_headless := false

static var ctx := TestContext.new()


class TestContext:
	var runner: TestRunner = null
	var current_test: String = ""

	func log_info(msg: String) -> void:
		if runner:
			runner._log("[%s] %s" % [current_test, msg], COLOR_INFO)

	func log_debug(msg: String) -> void:
		if runner:
			runner._log("[%s] %s" % [current_test, msg], COLOR_DEBUG)

	func log_error(msg: String) -> void:
		if runner:
			runner._log("[%s] %s" % [current_test, msg], COLOR_ERROR)


func _ready() -> void:
	is_headless = DisplayServer.get_name() == "headless"

	if not is_headless:
		log_label = $ScrollContainer/LogLabel
		log_label.text = ""

	ctx.runner = self

	log_info("Starting test session")
	indent_level += 1

	var dir := DirAccess.open("res://tests")
	if dir == null:
		log_error("Could not open res://tests/")
		quit_tests(1)
		return

	var files: Array[String] = []
	dir.list_dir_begin()

	var fname := dir.get_next()
	while fname != "":
		if not dir.current_is_dir() and fname.begins_with("test_") and fname.ends_with(".gd"):
			files.append(fname)
		fname = dir.get_next()

	dir.list_dir_end()
	files.sort()

	var session_start := Time.get_ticks_usec()
	for file in files:
		_run_suite(file)
	var session_duration_ms := (Time.get_ticks_usec() - session_start) / 1000.0

	indent_level -= 1
	log_info("==============================")

	if total_failed > 0:
		log_error("FAILED: %d passed, %d failed (%.3f ms)" % [total_passed, total_failed, session_duration_ms])
	else:
		log_success("PASSED: %d tests total (%.3f ms)" % [total_passed, session_duration_ms])

	quit_tests(1 if total_failed > 0 else 0)


func _run_suite(file: String) -> void:
	var path := "res://tests/" + file
	var script := load(path)

	if script == null:
		log_error("Failed to load: %s" % path)
		total_failed += 1
		return

	var instance = script.new()
	if instance == null:
		log_error("Failed to instantiate: %s" % path)
		total_failed += 1
		script = null
		return

	var methods: Array[String] = []
	for m in script.get_script_method_list():
		if m["name"].begins_with("test_"):
			methods.append(m["name"])

	methods.sort()
	if methods.is_empty():
		instance = null
		script = null
		return

	var suite_name := file.trim_suffix(".gd")
	log_info("Suite: %s" % suite_name)
	indent_level += 1

	var suite_passed := 0
	var suite_failed := 0
	var suite_start := Time.get_ticks_usec()

	for method in methods:
		ctx.current_test = "%s.%s" % [suite_name, method]

		var start := Time.get_ticks_usec()
		var result := _run_test(instance, method)
		var duration_ms := (Time.get_ticks_usec() - start) / 1000.0

		if result == "":
			log_success("✓ %s (%.3f ms)" % [method, duration_ms])
			suite_passed += 1
		else:
			log_error("✗ %s: %s (%.3f ms)" % [method, result, duration_ms])
			suite_failed += 1

			var stack = get_stack()
			for frame in stack:
				if frame is Dictionary and frame.get("source", "").begins_with("res://tests"):
					log_debug("  at %s:%d" % [frame.get("source", "?"), frame.get("line", 0)])

	var suite_duration_ms := (Time.get_ticks_usec() - suite_start) / 1000.0

	indent_level -= 1
	log_info("Suite result: %s [%d/%d] (%.3f ms)" %
		[suite_name, suite_passed, suite_passed + suite_failed, suite_duration_ms])

	total_passed += suite_passed
	total_failed += suite_failed

	# Clear references to allow garbage collection
	instance = null
	script = null


func _run_test(script: Object, method: String) -> String:
	if not script.has_method(method):
		return "Method not found"

	var result = script.call(method)

	if result == null:
		return ""

	if typeof(result) != TYPE_STRING:
		return "Invalid return type: expected String"

	return result


func log_success(message: String) -> void:
	_log(message, COLOR_SUCCESS)

func log_error(message: String) -> void:
	_log(message, COLOR_ERROR)

func log_info(message: String) -> void:
	_log(message, COLOR_INFO)

func log_debug(message: String) -> void:
	_log(message, COLOR_DEBUG)


func _log(message: String, color: String) -> void:
	var indent := "  ".repeat(indent_level)
	var formatted := "[color=%s]%s%s[/color]" % [color, indent, message]

	print_rich(formatted)

	if not is_headless and log_label:
		log_label.text += ("\n" if log_label.text != "" else "") + formatted

		var sc := log_label.get_parent()
		if sc is ScrollContainer:
			await get_tree().process_frame
			sc.scroll_vertical = int(sc.get_v_scroll_bar().max_value)


func quit_tests(code: int) -> void:
	await get_tree().process_frame
	if DisplayServer.get_name() != "headless" and code == 0:
		return
	get_tree().quit(code)
