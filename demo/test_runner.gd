extends Node
class_name TestRunner

const COLOR_SUCCESS := "#22c55e"
const COLOR_ERROR := "#ef4444"
const COLOR_INFO := "#3b82f6"
const COLOR_DEBUG := "#9ca3af"

const TEST_DIR := "res://tests"
const INDEX_FILE := "res://tests/index.gd"

const MAX_THREADS := 4 # ← thread pool size

var log_label: RichTextLabel
var indent_level: int = 0
var total_passed: int = 0
var total_failed: int = 0
var _pending_suites := 0
var _active_threads := 0
var _queue: Array[String] = []

var is_headless := false
var TestIndexRef = null

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

	var test_files := _get_test_files()
	_pending_suites = test_files.size()
	_queue = test_files.duplicate()

	_pump_queue()


# =========================================================
# 🧵 Thread pool
# =========================================================
func _pump_queue() -> void:
	while _active_threads < MAX_THREADS and not _queue.is_empty():
		var path = _queue.pop_front()
		_active_threads += 1

		var thread := Thread.new()
		thread.start(Callable(self, "_thread_run_suite").bind(path, thread))


# =========================================================
# 🔍 Test discovery
# =========================================================
func _get_test_files() -> Array[String]:
	if Engine.is_editor_hint():
		return _get_tests_editor()
	else:
		_ensure_index_loaded()
		return TestIndexRef.TEST_FILES


func _get_tests_editor() -> Array[String]:
	var scanned := _scan_tests()

	var should_regen := true

	if FileAccess.file_exists(INDEX_FILE):
		var existing = load(INDEX_FILE)
		if existing and "TEST_FILES" in existing:
			if existing.TEST_FILES == scanned:
				should_regen = false
				TestIndexRef = existing

	if should_regen:
		_write_index(scanned)
		TestIndexRef = load(INDEX_FILE)

	return scanned


func _ensure_index_loaded() -> void:
	if TestIndexRef != null:
		return

	if not FileAccess.file_exists(INDEX_FILE):
		push_error("Missing %s. Run tests in editor first." % INDEX_FILE)
		return

	TestIndexRef = load(INDEX_FILE)


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
	if file == null:
		push_error("Could not write to %s" % INDEX_FILE)
		return

	file.store_string(content)
	file.close()


# =========================================================
# 🧪 Thread worker
# =========================================================
func _thread_run_suite(path: String, thread: Thread) -> void:
	var out := {}

	var script := load(path)
	if script == null:
		out.error = "Failed to load"
		out.name = path
	else:
		var instance = script.new()
		if instance == null:
			out.error = "Failed to instantiate"
			out.name = path
		else:
			var methods: Array[String] = []
			for m in script.get_script_method_list():
				if m["name"].begins_with("test_"):
					methods.append(m["name"])

			methods.sort()

			var suite_name := path.get_file().trim_suffix(".gd")

			var suite_passed := 0
			var suite_failed := 0
			var tests := []

			for method in methods:
				var start := Time.get_ticks_usec()
				var result := _run_test(instance, method)
				var duration_ms := (Time.get_ticks_usec() - start) / 1000.0

				if result == "":
					suite_passed += 1
				else:
					suite_failed += 1

				tests.append({
					"name": method,
					"result": result,
					"time": duration_ms
				})

			out.name = suite_name
			out.passed = suite_passed
			out.failed = suite_failed
			out.tests = tests

	# return to main thread
	call_deferred("_on_suite_finished", out)

	thread.wait_to_finish() # ensure cleanup


func _run_test(script: Object, method: String) -> String:
	if not script.has_method(method):
		return "Method not found"

	var result = script.call(method)

	if result == null:
		return ""

	if typeof(result) != TYPE_STRING:
		return "Invalid return type: expected String"

	return result


# =========================================================
# 🧾 Results (main thread)
# =========================================================
func _on_suite_finished(r: Dictionary) -> void:
	_active_threads -= 1
	_pump_queue()

	if r.has("error"):
		log_error("%s: %s" % [r.get("name", "?"), r.error])
		total_failed += 1
	else:
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

	_pending_suites -= 1

	if _pending_suites == 0:
		_finish_all_tests()


func _finish_all_tests():
	log_info("==============================")

	if total_failed > 0:
		log_error("FAILED: %d passed, %d failed" % [total_passed, total_failed])
	else:
		log_success("PASSED: %d tests total" % total_passed)

	quit_tests(1 if total_failed > 0 else 0)


# =========================================================
# 📝 Logging
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
