@tool
extends EditorScript

const TEST_DIR := "res://tests"
const OUTPUT_FILE := "res://tests/index.gd"

func _run():
	print("Generating test index...")

	var dir := DirAccess.open(TEST_DIR)
	if dir == null:
		push_error("Could not open %s" % TEST_DIR)
		return

	var files: Array[String] = []
	dir.list_dir_begin()

	var fname := dir.get_next()
	while fname != "":
		if not dir.current_is_dir() \
		and fname.begins_with("test_") \
		and fname.ends_with(".gd"):
			files.append(fname)
		fname = dir.get_next()

	dir.list_dir_end()

	files.sort()

	# Build output content
	var content := "# Auto-generated. Do not edit.\n"
	content += "class_name TestIndex\n"
	content += "const TEST_FILES := [\n"

	for f in files:
		content += "\t\"%s/%s\",\n" % [TEST_DIR, f]

	content += "]\n"

	# Write file
	var file := FileAccess.open(OUTPUT_FILE, FileAccess.WRITE)
	if file == null:
		push_error("Could not write to %s" % OUTPUT_FILE)
		return

	file.store_string(content)
	file.close()

	print("Test index generated with %d files." % files.size())
