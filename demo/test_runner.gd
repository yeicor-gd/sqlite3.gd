extends Node
class_name TestRunner

# =========================================================
# 🎨 Colors
# =========================================================
const COLOR_SUCCESS := "#22c55e"
const COLOR_ERROR := "#ef4444"
const COLOR_INFO := "#3b82f6"
const COLOR_DEBUG := "#9ca3af"

# =========================================================
# 📁 Config
# =========================================================
const TEST_DIR := "res://tests"
const INDEX_FILE := "res://tests/index.gd"

# =========================================================
# 📊 State
# =========================================================
var log_label: RichTextLabel
var indent_level := 0

var total_passed := 0
var total_failed := 0

var is_headless := false
var TestIndexRef = null

static var ctx := TestContext.new()

# =========================================================
# 🧠 Context (unchanged API)
# =========================================================
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

# =========================================================
# 🚀 Entry
# =========================================================
func _ready() -> void:
	is_headless = DisplayServer.get_name() == "headless"

	if not is_headless:
		log_label = $ScrollContainer/LogLabel
		log_label.text = ""

	ctx.runner = self

	log_info("Starting test session")
	indent_level += 1

	var test_files := _get_test_files()
	if test_files.is_empty():
		log_error("No test files found")
		_finish_all_tests()
		return

	for path in test_files:
		var result := _run_suite(path)
		_report_suite(result)

	_finish_all_tests()

# =========================================================
# 🔍 Test discovery
# =========================================================
func _get_test_files() -> Array[String]:
	var scanned := _scan_tests()

	if scanned.is_empty():
		push_error("Could not scan tests directory %s" % TEST_DIR)
		return []

	var should_regen := true

	if FileAccess.file_exists(INDEX_FILE):
		var idx = load(INDEX_FILE)
		if idx and "TEST_FILES" in idx and idx.TEST_FILES == scanned:
			TestIndexRef = idx
			should_regen = false

	if should_regen:
		_write_index(scanned)
		var idx = load(INDEX_FILE)
		if idx and "TEST_FILES" in idx:
			TestIndexRef = idx
		else:
			TestIndexRef = _create_index_obj(scanned)

	return TestIndexRef.TEST_FILES if TestIndexRef else scanned


func _scan_tests() -> Array[String]:
	var dir := DirAccess.open(TEST_DIR)
	if dir == null:
		push_error("Could not open %s" % TEST_DIR)
		return []

	var files: Array[String] = []
	dir.list_dir_begin()

	var fname := dir.get_next()
	while fname != "":
		if not dir.current_is_dir() \
		and fname.begins_with("test_") \
		and fname.ends_with(".gd"):
			files.append("%s/%s" % [TEST_DIR, fname])
		fname = dir.get_next()

	dir.list_dir_end()
	files.sort()
	return files


func _write_index(files: Array[String]) -> void:
	var content := "# Auto-generated. Do not edit.\n"
	content += "class_name TestIndex\n"
	content += "const TEST_FILES: Array[String] = [\n"

	for f in files:
		content += "\t\"%s\",\n" % f

	content += "]\n"

	var file := FileAccess.open(INDEX_FILE, FileAccess.WRITE)
	if file:
		file.store_string(content)
		file.close()
	else:
		push_error("Could not write to %s" % INDEX_FILE)


func _create_index_obj(files: Array[String]) -> RefCounted:
	var idx := RefCounted.new()
	idx.set("TEST_FILES", files)
	return idx

# =========================================================
# 🧪 Suite execution
# =========================================================
func _run_suite(path: String) -> Dictionary:
	var out := {}

	# -------------------------
	# Load + compile
	# -------------------------
	var script := load(path)

	if script == null or not (script is GDScript):
		out.error = "Failed to load"
		out.name = path
		return out

	if script.reload() != OK:
		out.error = "Parse error"
		out.name = path
		return out

	if not script.can_instantiate():
		out.error = "Cannot instantiate"
		out.name = path
		return out

	var instance = script.new()
	if instance == null:
		out.error = "Instantiation failed"
		out.name = path
		return out

	# -------------------------
	# Discover tests
	# -------------------------
	var methods: Array[String] = []
	for m in script.get_script_method_list():
		if m["name"].begins_with("test_"):
			methods.append(m["name"])

	methods.sort()

	var suite_name := path.get_file().trim_suffix(".gd")
	var passed := 0
	var failed := 0
	var tests := []

	# -------------------------
	# Run tests
	# -------------------------
	for method in methods:
		ctx.current_test = method

		var start := Time.get_ticks_usec()
		var result := _run_test(instance, method)
		var duration := (Time.get_ticks_usec() - start) / 1000.0

		if result == "":
			passed += 1
		else:
			failed += 1

		tests.append({
			"name": method,
			"result": result,
			"time": duration
		})

	out.name = suite_name
	out.passed = passed
	out.failed = failed
	out.tests = tests

	return out


func _run_test(instance: Object, method: String) -> String:
	if not instance.has_method(method):
		return "Method not found"

	var result = instance.call(method)

	if result == null:
		return ""

	if typeof(result) != TYPE_STRING:
		return "Invalid return type (expected String)"

	return result

# =========================================================
# 🧾 Reporting
# =========================================================
func _report_suite(r: Dictionary) -> void:
	if r.has("error"):
		log_error("%s: %s" % [r.get("name", "?"), r.error])
		total_failed += 1

		if is_headless:
			log_error("Fatal error → aborting early")
			_finish_all_tests()
		return

	log_info("Suite: %s" % r.name)
	indent_level += 1

	for t in r.tests:
		if t.result == "":
			log_success("✓ %s (%.3f ms)" % [t.name, t.time])
		else:
			log_error("✗ %s: %s (%.3f ms)" % [t.name, t.result, t.time])

	log_info("Suite result: %s [%d/%d]" %
		[r.name, r.passed, r.passed + r.failed])

	indent_level -= 1

	total_passed += r.passed
	total_failed += r.failed


func _finish_all_tests() -> void:
	log_info("==============================")

	if total_failed > 0:
		log_error("FAILED: %d passed, %d failed" % [total_passed, total_failed])
	else:
		log_success("PASSED: %d tests total" % total_passed)

	quit_tests(1 if total_failed > 0 else 0)

# =========================================================
# 📝 Logging (unchanged)
# =========================================================
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
			if sc.get_v_scroll_bar():
				sc.scroll_vertical = int(sc.get_v_scroll_bar().max_value)


func quit_tests(code: int) -> void:
	await get_tree().process_frame
	if DisplayServer.get_name() != "headless" and code == 0:
		return
	get_tree().quit(code)
