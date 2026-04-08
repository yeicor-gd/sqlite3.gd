# test_01_version_and_constants.gd
# Tests version queries, error-code constants, open-flag constants,
# type constants, and basic library-level functions.

var s := Sqlite3Wrapper.new()

# ---------------------------------------------------------------------------
# Cleanup
# ---------------------------------------------------------------------------

func _cleanup() -> void:
	s = null

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

func _ok() -> int:
	return s.ok()

func _assert_eq(label: String, got, expected) -> String:
	if got != expected:
		return "%s: expected %s, got %s" % [label, expected, got]
	return ""

func _assert_ne(label: String, got, unexpected) -> String:
	if got == unexpected:
		return "%s: expected value != %s, got %s" % [label, unexpected, got]
	return ""

func _assert_gt(label: String, got, threshold) -> String:
	if not (got > threshold):
		return "%s: expected > %s, got %s" % [label, threshold, got]
	return ""

func _assert_true(label: String, cond: bool) -> String:
	if not cond:
		return "%s: expected true, got false" % label
	return ""

# ---------------------------------------------------------------------------
# 1. Version string / number
# ---------------------------------------------------------------------------

func test_version_string_format() -> String:
	var v: String = s.version_string()
	if not v.is_valid_identifier() and v.count(".") < 2:
		# valid semver-like "X.Y.Z"
		pass
	if v == "":
		return "version_string() returned empty"
	var parts := v.split(".")
	if parts.size() < 3:
		return "version_string() not in X.Y.Z format: '%s'" % v
	for p in parts:
		if not p.is_valid_int():
			return "version_string() part '%s' is not an integer" % p
	return ""

func test_version_number_positive() -> String:
	var n: int = s.version_number()
	if n <= 0:
		return "version_number() returned non-positive: %d" % n
	# SQLite 3.x => at least 3_000_000
	if n < 3000000:
		return "version_number() suspiciously low: %d" % n
	return ""

func test_version_string_matches_number() -> String:
	var v: String = s.version_string()
	var n: int = s.version_number()
	var parts := v.split(".")
	var expected := parts[0].to_int() * 1000000 + parts[1].to_int() * 1000 + parts[2].to_int()
	return _assert_eq("version number from string", expected, n)

func test_libversion_equals_version_string() -> String:
	return _assert_eq("libversion == version_string", s.libversion(), s.version_string())

func test_libversion_number_equals_version_number() -> String:
	return _assert_eq("libversion_number == version_number", s.libversion_number(), s.version_number())

func test_sourceid_nonempty() -> String:
	return _assert_true("source_id non-empty", s.source_id() != "")

func test_sourceid_equals_libsourceid() -> String:
	return _assert_eq("source_id == sourceid", s.source_id(), s.sourceid())

# ---------------------------------------------------------------------------
# 2. Core result codes
# ---------------------------------------------------------------------------

func test_result_code_ok() -> String:
	return _assert_eq("SQLITE_OK", s.ok(), 0)

func test_result_code_error() -> String:
	return _assert_eq("SQLITE_ERROR", s.error(), 1)

func test_result_code_busy() -> String:
	return _assert_eq("SQLITE_BUSY", s.busy(), 5)

func test_result_code_row() -> String:
	return _assert_eq("SQLITE_ROW", s.row(), 100)

func test_result_code_done() -> String:
	return _assert_eq("SQLITE_DONE", s.done(), 101)

func test_result_code_nomem() -> String:
	return _assert_eq("SQLITE_NOMEM", s.nomem(), 7)

func test_result_code_readonly() -> String:
	return _assert_eq("SQLITE_READONLY", s.readonly(), 8)

func test_result_code_perm() -> String:
	return _assert_eq("SQLITE_PERM", s.perm(), 3)

func test_result_code_abort() -> String:
	return _assert_eq("SQLITE_ABORT", s.abort(), 4)

func test_result_code_locked() -> String:
	return _assert_eq("SQLITE_LOCKED", s.locked(), 6)

func test_result_code_ioerr() -> String:
	return _assert_eq("SQLITE_IOERR", s.ioerr(), 10)

func test_result_code_corrupt() -> String:
	return _assert_eq("SQLITE_CORRUPT", s.corrupt(), 11)

func test_result_code_notfound() -> String:
	return _assert_eq("SQLITE_NOTFOUND", s.notfound(), 12)

func test_result_code_full() -> String:
	return _assert_eq("SQLITE_FULL", s.full(), 13)

func test_result_code_cantopen() -> String:
	return _assert_eq("SQLITE_CANTOPEN", s.cantopen(), 14)

func test_result_code_constraint() -> String:
	return _assert_eq("SQLITE_CONSTRAINT", s.constraint(), 19)

func test_result_code_mismatch() -> String:
	return _assert_eq("SQLITE_MISMATCH", s.mismatch(), 20)

func test_result_code_misuse() -> String:
	return _assert_eq("SQLITE_MISUSE", s.misuse(), 21)

func test_result_code_range() -> String:
	return _assert_eq("SQLITE_RANGE", s.range(), 25)

func test_result_code_notadb() -> String:
	return _assert_eq("SQLITE_NOTADB", s.notadb(), 26)

func test_result_code_notice() -> String:
	return _assert_eq("SQLITE_NOTICE", s.notice(), 27)

func test_result_code_warning() -> String:
	return _assert_eq("SQLITE_WARNING", s.warning(), 28)

# ---------------------------------------------------------------------------
# 3. Extended error codes (spot-check derivation rules)
# ---------------------------------------------------------------------------

func test_extended_constraint_unique() -> String:
	var code := s.constraint_unique()
	# Must be non-zero and derived from SQLITE_CONSTRAINT (19)
	if code == 0:
		return "constraint_unique() returned 0"
	if (code & 0xFF) != s.constraint():
		return "constraint_unique low byte != SQLITE_CONSTRAINT"
	return ""

func test_extended_constraint_notnull() -> String:
	var code := s.constraint_notnull()
	if (code & 0xFF) != s.constraint():
		return "constraint_notnull low byte != SQLITE_CONSTRAINT"
	return ""

func test_extended_constraint_primarykey() -> String:
	var code := s.constraint_primarykey()
	if (code & 0xFF) != s.constraint():
		return "constraint_primarykey low byte != SQLITE_CONSTRAINT"
	return ""

func test_extended_constraint_foreignkey() -> String:
	var code := s.constraint_foreignkey()
	if (code & 0xFF) != s.constraint():
		return "constraint_foreignkey low byte != SQLITE_CONSTRAINT"
	return ""

func test_extended_readonly_rollback() -> String:
	var code := s.readonly_rollback()
	if (code & 0xFF) != s.readonly():
		return "readonly_rollback low byte != SQLITE_READONLY"
	return ""

func test_extended_ioerr_read() -> String:
	var code := s.ioerr_read()
	if (code & 0xFF) != s.ioerr():
		return "ioerr_read low byte != SQLITE_IOERR"
	return ""

func test_extended_busy_recovery() -> String:
	var code := s.busy_recovery()
	if (code & 0xFF) != s.busy():
		return "busy_recovery low byte != SQLITE_BUSY"
	return ""

func test_extended_error_retry() -> String:
	var code := s.error_retry()
	if (code & 0xFF) != s.error():
		return "error_retry low byte != SQLITE_ERROR"
	return ""

func test_extended_abort_rollback() -> String:
	var code := s.abort_rollback()
	if (code & 0xFF) != s.abort():
		return "abort_rollback low byte != SQLITE_ABORT"
	return ""

func test_extended_corrupt_vtab() -> String:
	var code := s.corrupt_vtab()
	if (code & 0xFF) != s.corrupt():
		return "corrupt_vtab low byte != SQLITE_CORRUPT"
	return ""

# ---------------------------------------------------------------------------
# 4. Open flags (all must be non-zero and distinct)
# ---------------------------------------------------------------------------

func test_open_flags_nonzero() -> String:
	var flags := {
		"open_readonly": s.open_readonly(),
		"open_readwrite": s.open_readwrite(),
		"open_create": s.open_create(),
		"open_uri": s.open_uri(),
		"open_memory": s.open_memory(),
		"open_nomutex": s.open_nomutex(),
		"open_fullmutex": s.open_fullmutex(),
		"open_sharedcache": s.open_sharedcache(),
		"open_privatecache": s.open_privatecache(),
		"open_nofollow": s.open_nofollow(),
		"open_exrescode": s.open_exrescode(),
	}
	for name in flags:
		if flags[name] == 0:
			return "%s is zero" % name
	return ""

func test_open_flags_distinct() -> String:
	var flags := {
		"open_readonly": s.open_readonly(),
		"open_readwrite": s.open_readwrite(),
		"open_create": s.open_create(),
		"open_uri": s.open_uri(),
		"open_memory": s.open_memory(),
	}
	var seen := {}
	for name in flags:
		var v: int = flags[name]
		if v in seen:
			return "%s and %s share value %d" % [name, seen[v], v]
		seen[v] = name
	return ""

func test_open_readonly_is_power_of_two() -> String:
	var v := s.open_readonly()
	return _assert_true("open_readonly is power-of-two", v > 0 and (v & (v - 1)) == 0)

func test_open_readwrite_is_power_of_two() -> String:
	var v := s.open_readwrite()
	return _assert_true("open_readwrite is power-of-two", v > 0 and (v & (v - 1)) == 0)

func test_open_create_is_power_of_two() -> String:
	var v := s.open_create()
	return _assert_true("open_create is power-of-two", v > 0 and (v & (v - 1)) == 0)

# ---------------------------------------------------------------------------
# 5. Data type codes
# ---------------------------------------------------------------------------

func test_type_integer_is_1() -> String:
	return _assert_eq("SQLITE_INTEGER", s.sqlite_integer(), 1)

func test_type_float_is_2() -> String:
	return _assert_eq("SQLITE_FLOAT", s.sqlite_float(), 2)

func test_type_text_is_3() -> String:
	return _assert_eq("SQLITE_TEXT", s.sqlite_text(), 3)

func test_type_blob_is_4() -> String:
	return _assert_eq("SQLITE_BLOB", s.sqlite_blob(), 4)

func test_type_null_is_5() -> String:
	return _assert_eq("SQLITE_NULL", s.sqlite_null(), 5)

func test_type_codes_distinct() -> String:
	var codes := [s.sqlite_integer(), s.sqlite_float(), s.sqlite_text(), s.sqlite_blob(), s.sqlite_null()]
	var seen := {}
	for c in codes:
		if c in seen:
			return "duplicate type code: %d" % c
		seen[c] = true
	return ""

# ---------------------------------------------------------------------------
# 6. Encoding constants
# ---------------------------------------------------------------------------

func test_sqlite_utf8_nonzero() -> String:
	return _assert_true("SQLITE_UTF8 non-zero", s.sqlite_utf8() != 0)

func test_sqlite_deterministic_nonzero() -> String:
	return _assert_true("SQLITE_DETERMINISTIC non-zero", s.sqlite_deterministic() != 0)

# ---------------------------------------------------------------------------
# 7. errstr – map known codes to non-empty descriptions
# ---------------------------------------------------------------------------

func test_errstr_ok() -> String:
	var msg := s.errstr(s.ok())
	return _assert_true("errstr(OK) non-empty", msg != "")

func test_errstr_error() -> String:
	var msg := s.errstr(s.error())
	return _assert_true("errstr(SQLITE_ERROR) non-empty", msg != "")

func test_errstr_nomem() -> String:
	var msg := s.errstr(s.nomem())
	return _assert_true("errstr(SQLITE_NOMEM) non-empty", msg != "")

func test_errstr_busy() -> String:
	var msg := s.errstr(s.busy())
	return _assert_true("errstr(SQLITE_BUSY) non-empty", msg != "")

# ---------------------------------------------------------------------------
# 8. compileoption_get / compileoption_used
# ---------------------------------------------------------------------------

func test_compileoption_get_index_0() -> String:
	# Index 0 should return either a non-empty option string or ""
	# (valid behaviour for both cases)
	var opt: String = s.compileoption_get(0)
	# As long as it doesn't crash and returns a String we're good
	return _assert_true("compileoption_get returns String", typeof(opt) == TYPE_STRING)

func test_compileoption_get_large_index_empty() -> String:
	var opt: String = s.compileoption_get(999999)
	return _assert_eq("out-of-range compileoption_get returns empty", opt, "")

func test_compileoption_used_threadsafe() -> String:
	# THREADSAFE is almost always enabled; result must be 0 or 1
	var r: int = s.compileoption_used("THREADSAFE")
	if r != 0 and r != 1:
		return "compileoption_used(THREADSAFE) returned unexpected value: %d" % r
	return ""

func test_compileoption_used_nonexistent() -> String:
	var r: int = s.compileoption_used("SQLITE_NONEXISTENT_OPTION_XYZ_999")
	return _assert_eq("unknown option returns 0", r, 0)

# ---------------------------------------------------------------------------
# 9. threadsafe()
# ---------------------------------------------------------------------------

func test_threadsafe_returns_int() -> String:
	var r = s.threadsafe()
	return _assert_true("threadsafe() returns int", typeof(r) == TYPE_INT)

# ---------------------------------------------------------------------------
# 10. complete() – SQL completeness check
# ---------------------------------------------------------------------------

func test_complete_full_statement() -> String:
	return _assert_eq("complete SELECT;", s.complete("SELECT 1;"), 1)

func test_complete_partial_statement() -> String:
	return _assert_eq("complete SELECT (no semicolon)", s.complete("SELECT"), 0)

func test_complete_empty_string() -> String:
	var r := s.complete("")
	# Empty string: not a complete statement (returns 0)
	return _assert_eq("complete empty string", r, 0)

func test_complete_multiline() -> String:
	return _assert_eq("complete CREATE TABLE;", s.complete("CREATE TABLE t (id INTEGER);"), 1)

func test_complete_string_literal_open() -> String:
	# Unclosed string literal → not complete
	return _assert_eq("incomplete string literal", s.complete("SELECT 'hello"), 0)

# ---------------------------------------------------------------------------
# 11. memory_used / memory_highwater
# ---------------------------------------------------------------------------

func test_memory_used_nonnegative() -> String:
	var m := s.memory_used()
	return _assert_true("memory_used() >= 0", m >= 0)

func test_memory_highwater_nonnegative() -> String:
	var h := s.memory_highwater(0)
	return _assert_true("memory_highwater(0) >= 0", h >= 0)

func test_memory_highwater_ge_used() -> String:
	var used := s.memory_used()
	var high := s.memory_highwater(0)
	return _assert_true("highwater >= used", high >= used)

# ---------------------------------------------------------------------------
# 12. randomness()
# ---------------------------------------------------------------------------

func test_randomness_correct_length() -> String:
	var buf: PackedByteArray = s.randomness(16)
	return _assert_eq("randomness(16) length", buf.size(), 16)

func test_randomness_zero_reseeds() -> String:
	# randomness(0) reseeds and returns empty array
	var buf: PackedByteArray = s.randomness(0)
	return _assert_eq("randomness(0) returns empty", buf.size(), 0)

func test_randomness_not_all_zero() -> String:
	var buf: PackedByteArray = s.randomness(32)
	var all_zero := true
	for b in buf:
		if b != 0:
			all_zero = false
			break
	return _assert_true("randomness(32) not all-zero", not all_zero)

func test_randomness_two_calls_differ() -> String:
	var a: PackedByteArray = s.randomness(16)
	var b: PackedByteArray = s.randomness(16)
	# Statistically virtually impossible to be equal
	return _assert_true("two randomness(16) calls differ", a != b)

# ---------------------------------------------------------------------------
# 13. mprintf() – basic format-string with no extra args
# ---------------------------------------------------------------------------

func test_mprintf_plain_string() -> String:
	var result: String = s.mprintf("hello world")
	return _assert_eq("mprintf plain", result, "hello world")

func test_mprintf_empty() -> String:
	var result: String = s.mprintf("")
	return _assert_eq("mprintf empty", result, "")

# ---------------------------------------------------------------------------
# 14. Keyword API
# ---------------------------------------------------------------------------

func test_keyword_count_positive() -> String:
	var n: int = s.keyword_count()
	return _assert_gt("keyword_count() > 0", n, 0)

func test_keyword_name_index_0() -> String:
	if s.keyword_count() == 0:
		return ""
	var res: Dictionary = s.keyword_name(0)
	var name: String = res.get("name", "")
	return _assert_true("keyword_name(0) non-empty", name != "")

func test_keyword_check_select() -> String:
	var r: int = s.keyword_check("SELECT", 6)
	return _assert_eq("SELECT is keyword", r, 1)

func test_keyword_check_not_keyword() -> String:
	var r: int = s.keyword_check("NOTAKEYWORDXYZ", 14)
	return _assert_eq("NOTAKEYWORD is not keyword", r, 0)

# ---------------------------------------------------------------------------
# 15. SCM / build metadata – just sanity-check types
# ---------------------------------------------------------------------------

func test_scm_branch_is_string() -> String:
	var v = s.scm_branch()
	return _assert_true("scm_branch() is String", typeof(v) == TYPE_STRING)

func test_scm_tags_is_string() -> String:
	var v = s.scm_tags()
	return _assert_true("scm_tags() is String", typeof(v) == TYPE_STRING)

func test_scm_datetime_is_string() -> String:
	var v = s.scm_datetime()
	return _assert_true("scm_datetime() is String", typeof(v) == TYPE_STRING)

# ---------------------------------------------------------------------------
# 16. sqlite3_text / sqlite3_text alias
# ---------------------------------------------------------------------------

func test_sqlite_text_equals_3() -> String:
	return _assert_eq("sqlite_text() == 3", s.sqlite_text(), 3)

func test_sqlite3_text_nonzero() -> String:
	return _assert_true("sqlite3_text() non-zero", s.sqlite3_text() != 0)

# ---------------------------------------------------------------------------
# 17. Sync / lock constants – spot-check
# ---------------------------------------------------------------------------

func test_sync_normal_nonzero() -> String:
	return _assert_true("sync_normal non-zero", s.sync_normal() != 0)

func test_sync_full_nonzero() -> String:
	return _assert_true("sync_full non-zero", s.sync_full() != 0)

func test_lock_none_is_0() -> String:
	return _assert_eq("lock_none == 0", s.lock_none(), 0)

func test_lock_exclusive_is_4() -> String:
	return _assert_eq("lock_exclusive == 4", s.lock_exclusive(), 4)

# ---------------------------------------------------------------------------
# 18. Static / transient destructor types
# ---------------------------------------------------------------------------

func test_static_destructor_type() -> String:
	return _assert_eq("static_destructor_type == 0", s.static_destructor_type(), 0)

func test_transient_destructor_type() -> String:
	return _assert_eq("transient_destructor_type == -1", s.transient_destructor_type(), -1)
