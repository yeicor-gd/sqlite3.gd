# test_02_open_close_exec.gd
# Tests database open/close lifecycle, exec(), errmsg(), changes(),
# last_insert_rowid(), get_autocommit(), and basic error handling.

var s := Sqlite3Wrapper.new()

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

func _open_memory() -> Sqlite3Handle:
	var db := Sqlite3Handle.new()
	var flags := s.open_readwrite() | s.open_create() | s.open_memory()
	var rc := s.open_v2(":memory:", db, flags, "")
	assert(rc == s.ok(), "Failed to open in-memory DB: %d" % rc)
	return db

func _exec(db: Sqlite3Handle, sql: String) -> int:
	var res: Dictionary = s.exec(db, sql, Callable())
	return res.get("code", -1)

func _assert_eq(label: String, got, expected) -> String:
	if got != expected:
		return "%s: expected %s, got %s" % [label, expected, got]
	return ""

func _assert_ne(label: String, got, unexpected) -> String:
	if got == unexpected:
		return "%s: expected != %s, got %s" % [label, unexpected, got]
	return ""

func _assert_true(label: String, cond: bool) -> String:
	if not cond:
		return "%s: expected true" % label
	return ""

func _assert_gt(label: String, got, threshold) -> String:
	if not (got > threshold):
		return "%s: expected > %s, got %s" % [label, threshold, got]
	return ""

# ---------------------------------------------------------------------------
# 1. open_v2 – in-memory database
# ---------------------------------------------------------------------------

func test_open_memory_ok() -> String:
	var db := Sqlite3Handle.new()
	var flags := s.open_readwrite() | s.open_create() | s.open_memory()
	var rc := s.open_v2(":memory:", db, flags, "")
	var err := _assert_eq("open_v2 :memory:", rc, s.ok())
	if err != "":
		return err
	s.close(db)
	return ""

func test_open_memory_produces_valid_handle() -> String:
	var db := Sqlite3Handle.new()
	var flags := s.open_readwrite() | s.open_create() | s.open_memory()
	s.open_v2(":memory:", db, flags, "")
	# A valid db handle should report autocommit on (== 1)
	var ac := s.get_autocommit(db)
	s.close(db)
	return _assert_eq("autocommit after fresh open", ac, 1)

func test_open_readonly_nonexistent_fails() -> String:
	var db := Sqlite3Handle.new()
	var flags := s.open_readonly()
	var rc := s.open_v2("/nonexistent/path/that/cannot/exist/db.sqlite3", db, flags, "")
	if rc == s.ok():
		s.close(db)
		return "expected error opening nonexistent readonly DB, got SQLITE_OK"
	return ""

func test_open_with_empty_vfs_uses_default() -> String:
	var db := Sqlite3Handle.new()
	var flags := s.open_readwrite() | s.open_create() | s.open_memory()
	var rc := s.open_v2(":memory:", db, flags, "")
	var err := _assert_eq("open with empty VFS string", rc, s.ok())
	if err == "":
		s.close(db)
	return err

# ---------------------------------------------------------------------------
# 2. close()
# ---------------------------------------------------------------------------

func test_close_after_open_returns_ok() -> String:
	var db := _open_memory()
	var rc := s.close(db)
	return _assert_eq("close() returns SQLITE_OK", rc, s.ok())

func test_close_with_pending_stmt_returns_busy() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	# Prepare but do NOT finalize
	var res := s.prepare_v2(db, "SELECT * FROM t", -1)
	var stmt: Sqlite3StmtHandle = res.get("statement")
	var rc := s.close(db)
	# SQLITE_BUSY because statement is not finalized
	var err := _assert_eq("close with open stmt => SQLITE_BUSY", rc, s.busy())
	s.finalize(stmt)
	s.close(db)
	return err

# ---------------------------------------------------------------------------
# 3. exec() – basic DDL and DML
# ---------------------------------------------------------------------------

func test_exec_create_table() -> String:
	var db := _open_memory()
	var res: Dictionary = s.exec(db, "CREATE TABLE test (id INTEGER PRIMARY KEY, name TEXT);", Callable())
	s.close(db)
	return _assert_eq("exec CREATE TABLE code", res.get("code", -1), s.ok())

func test_exec_insert_row() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var res: Dictionary = s.exec(db, "INSERT INTO t VALUES (42);", Callable())
	s.close(db)
	return _assert_eq("exec INSERT code", res.get("code", -1), s.ok())

func test_exec_multiple_statements() -> String:
	var db := _open_memory()
	var res: Dictionary = s.exec(db,
		"CREATE TABLE a (x INTEGER); CREATE TABLE b (y TEXT); INSERT INTO a VALUES (1);",
		Callable())
	s.close(db)
	return _assert_eq("exec multiple statements", res.get("code", -1), s.ok())

func test_exec_invalid_sql_returns_error() -> String:
	var db := _open_memory()
	var res: Dictionary = s.exec(db, "THIS IS NOT VALID SQL !!!;", Callable())
	s.close(db)
	if res.get("code", s.ok()) == s.ok():
		return "exec invalid SQL unexpectedly returned SQLITE_OK"
	return ""

func _disabled_test_exec_callback_receives_rows() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (2); INSERT INTO t VALUES (3);")
	var row_count := 0
	# Callback signature: (values, column_names) -> int
	var cb := func(vals: PackedStringArray, _cols: PackedStringArray) -> int:
		row_count += 1
		return 0
	var res: Dictionary = s.exec(db, "SELECT * FROM t;", cb)
	s.close(db)
	return _assert_eq("exec callback row count", row_count, 3)

func _disabled_test_exec_callback_receives_correct_values() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (99);")
	var got_val := ""
	# Callback signature: (values, column_names) -> int
	var cb := func(vals: PackedStringArray, _cols: PackedStringArray) -> int:
		if vals.size() > 0:
			got_val = vals[0]
		return 0
	var res: Dictionary = s.exec(db, "SELECT x FROM t;", cb)
	s.close(db)
	return _assert_eq("exec callback value", got_val, "99")

func _disabled_test_exec_callback_abort_on_nonzero_return() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (2); INSERT INTO t VALUES (3);")
	var row_count := 0
	# Returning non-zero from the callback should abort exec
	# Callback signature: (values, column_names) -> int
	var cb := func(vals: PackedStringArray, _cols: PackedStringArray) -> int:
		row_count += 1
		return 1  # abort
	var res: Dictionary = s.exec(db, "SELECT * FROM t;", cb)
	s.close(db)
	# Exec should have been aborted (non-OK result code)
	if res.get("code", s.ok()) == s.ok():
		return "exec should not return OK when callback aborts"
	if row_count != 1:
		return "callback should have been called exactly once before abort, got %d" % row_count
	return ""

func test_exec_error_message_on_failure() -> String:
	var db := _open_memory()
	var res: Dictionary = s.exec(db, "SELECT * FROM no_such_table;", Callable())
	s.close(db)
	if res.get("code", s.ok()) == s.ok():
		return "expected error"
	var msg: String = res.get("error_message", "")
	return _assert_true("error_message non-empty on failure", msg != "")

func test_exec_no_error_message_on_success() -> String:
	var db := _open_memory()
	var res: Dictionary = s.exec(db, "SELECT 1;", Callable())
	s.close(db)
	if res.get("code", -1) != s.ok():
		return "exec SELECT 1 failed: %d" % res.get("code", -1)
	# error_message should be absent or empty on success
	var msg: String = res.get("error_message", "")
	return _assert_eq("no error_message on success", msg, "")

# ---------------------------------------------------------------------------
# 4. errmsg() / errcode() / extended_errcode()
# ---------------------------------------------------------------------------

func test_errmsg_ok_after_success() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var msg := s.errmsg(db)
	s.close(db)
	# After success the error message should indicate no error / "not an error"
	return _assert_true("errmsg after success is non-null String", typeof(msg) == TYPE_STRING)

func test_errcode_after_bad_sql() -> String:
	var db := _open_memory()
	_exec(db, "NOT VALID SQL;")
	var code := s.errcode(db)
	s.close(db)
	if code == s.ok():
		return "errcode should not be OK after bad SQL"
	return ""

func test_errmsg_nonempty_after_error() -> String:
	var db := _open_memory()
	_exec(db, "SELECT * FROM nonexistent_table;")
	var msg := s.errmsg(db)
	s.close(db)
	return _assert_true("errmsg non-empty after error", msg != "")

func test_extended_errcode_after_error() -> String:
	var db := _open_memory()
	s.extended_result_codes(db, 1)
	_exec(db, "SELECT * FROM nonexistent_table;")
	var code := s.extended_errcode(db)
	s.close(db)
	if code == s.ok():
		return "extended_errcode should not be OK after error"
	return ""

func test_errcode_ok_after_clean_exec() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var code := s.errcode(db)
	s.close(db)
	return _assert_eq("errcode OK after clean exec", code, s.ok())

# ---------------------------------------------------------------------------
# 5. changes() / total_changes() / last_insert_rowid()
# ---------------------------------------------------------------------------

func test_changes_after_insert() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1);")
	var c := s.changes(db)
	s.close(db)
	return _assert_eq("changes() after single INSERT", c, 1)

func test_changes_after_multi_insert() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (2); INSERT INTO t VALUES (3);")
	var c := s.changes(db)
	s.close(db)
	# changes() reflects only the last statement — should be 1
	return _assert_eq("changes() after last INSERT in batch", c, 1)

func test_total_changes_accumulates() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1);")
	_exec(db, "INSERT INTO t VALUES (2);")
	_exec(db, "INSERT INTO t VALUES (3);")
	var tc := s.total_changes(db)
	s.close(db)
	return _assert_true("total_changes() >= 3", tc >= 3)

func test_changes64_after_insert() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (7);")
	var c := s.changes64(db)
	s.close(db)
	return _assert_eq("changes64() after INSERT", c, 1)

func test_total_changes64_nonnegative() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var tc := s.total_changes64(db)
	s.close(db)
	return _assert_true("total_changes64() >= 0", tc >= 0)

func test_last_insert_rowid_after_insert() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER PRIMARY KEY, v TEXT);")
	_exec(db, "INSERT INTO t (v) VALUES ('hello');")
	var rowid := s.last_insert_rowid(db)
	s.close(db)
	return _assert_gt("last_insert_rowid > 0", rowid, 0)

func test_last_insert_rowid_zero_before_insert() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER PRIMARY KEY, v TEXT);")
	var rowid := s.last_insert_rowid(db)
	s.close(db)
	return _assert_eq("last_insert_rowid == 0 before any insert", rowid, 0)

func test_last_insert_rowid_increments() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER PRIMARY KEY, v TEXT);")
	_exec(db, "INSERT INTO t (v) VALUES ('a');")
	var r1 := s.last_insert_rowid(db)
	_exec(db, "INSERT INTO t (v) VALUES ('b');")
	var r2 := s.last_insert_rowid(db)
	s.close(db)
	return _assert_true("rowid increments", r2 > r1)

func test_changes_after_update() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER PRIMARY KEY, v INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1, 10); INSERT INTO t VALUES (2, 20); INSERT INTO t VALUES (3, 30);")
	_exec(db, "UPDATE t SET v = 99 WHERE id IN (1, 2);")
	var c := s.changes(db)
	s.close(db)
	return _assert_eq("changes() after UPDATE 2 rows", c, 2)

func test_changes_after_delete() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (2); INSERT INTO t VALUES (3);")
	_exec(db, "DELETE FROM t WHERE x <= 2;")
	var c := s.changes(db)
	s.close(db)
	return _assert_eq("changes() after DELETE 2 rows", c, 2)

func test_changes_zero_after_noop() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "DELETE FROM t;")  # table is empty, nothing deleted
	var c := s.changes(db)
	s.close(db)
	return _assert_eq("changes() == 0 after no-op DELETE", c, 0)

# ---------------------------------------------------------------------------
# 6. get_autocommit()
# ---------------------------------------------------------------------------

func test_autocommit_on_by_default() -> String:
	var db := _open_memory()
	var ac := s.get_autocommit(db)
	s.close(db)
	return _assert_ne("autocommit on by default", ac, 0)

func test_autocommit_off_inside_transaction() -> String:
	var db := _open_memory()
	_exec(db, "BEGIN;")
	var ac := s.get_autocommit(db)
	_exec(db, "ROLLBACK;")
	s.close(db)
	return _assert_eq("autocommit off inside transaction", ac, 0)

func test_autocommit_restored_after_commit() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "BEGIN; INSERT INTO t VALUES (1); COMMIT;")
	var ac := s.get_autocommit(db)
	s.close(db)
	return _assert_ne("autocommit restored after COMMIT", ac, 0)

func test_autocommit_restored_after_rollback() -> String:
	var db := _open_memory()
	_exec(db, "BEGIN;")
	_exec(db, "ROLLBACK;")
	var ac := s.get_autocommit(db)
	s.close(db)
	return _assert_ne("autocommit restored after ROLLBACK", ac, 0)

# ---------------------------------------------------------------------------
# 7. extended_result_codes()
# ---------------------------------------------------------------------------

func test_extended_result_codes_enable() -> String:
	var db := _open_memory()
	var rc := s.extended_result_codes(db, 1)
	s.close(db)
	return _assert_eq("extended_result_codes enable", rc, s.ok())

func test_extended_result_codes_disable() -> String:
	var db := _open_memory()
	s.extended_result_codes(db, 1)
	var rc := s.extended_result_codes(db, 0)
	s.close(db)
	return _assert_eq("extended_result_codes disable", rc, s.ok())

func test_extended_errcode_after_constraint() -> String:
	var db := _open_memory()
	s.extended_result_codes(db, 1)
	_exec(db, "CREATE TABLE t (x INTEGER UNIQUE);")
	_exec(db, "INSERT INTO t VALUES (1);")
	_exec(db, "INSERT INTO t VALUES (1);")  # UNIQUE violation
	var code := s.extended_errcode(db)
	s.close(db)
	# Should be SQLITE_CONSTRAINT_UNIQUE (2067)
	if code == s.ok():
		return "expected extended constraint error code"
	# Extended UNIQUE code low byte must equal SQLITE_CONSTRAINT
	if (code & 0xFF) != s.constraint():
		return "extended errcode low byte != SQLITE_CONSTRAINT, got %d" % code
	return ""

# ---------------------------------------------------------------------------
# 8. get_table() – legacy table interface
# ---------------------------------------------------------------------------

func test_get_table_basic() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER, name TEXT);")
	_exec(db, "INSERT INTO t VALUES (1, 'Alice'); INSERT INTO t VALUES (2, 'Bob');")
	var res: Dictionary = s.get_table(db, "SELECT id, name FROM t ORDER BY id;")
	s.close(db)
	if res.get("code", -1) != s.ok():
		return "get_table failed: %d" % res.get("code", -1)
	if res.get("row_count", -1) != 2:
		return "get_table expected 2 rows, got %s" % res.get("row_count", -1)
	if res.get("column_count", -1) != 2:
		return "get_table expected 2 columns, got %s" % res.get("column_count", -1)
	return ""

func test_get_table_column_names_in_result() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER, name TEXT);")
	_exec(db, "INSERT INTO t VALUES (1, 'Alice');")
	var res: Dictionary = s.get_table(db, "SELECT id, name FROM t;")
	s.close(db)
	if res.get("code", -1) != s.ok():
		return "get_table failed"
	var table: PackedStringArray = res.get("result", PackedStringArray())
	# First row of flat array is column names: ["id", "name"]
	if table.size() < 2:
		return "table too small: %d" % table.size()
	if table[0] != "id":
		return "expected first column 'id', got '%s'" % table[0]
	if table[1] != "name":
		return "expected second column 'name', got '%s'" % table[1]
	return ""

func test_get_table_data_values() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER, name TEXT);")
	_exec(db, "INSERT INTO t VALUES (42, 'Godot');")
	var res: Dictionary = s.get_table(db, "SELECT id, name FROM t;")
	s.close(db)
	var table: PackedStringArray = res.get("result", PackedStringArray())
	# table[0]="id", table[1]="name", table[2]="42", table[3]="Godot"
	if table.size() < 4:
		return "expected 4 entries in flat table, got %d" % table.size()
	if table[2] != "42":
		return "expected '42', got '%s'" % table[2]
	if table[3] != "Godot":
		return "expected 'Godot', got '%s'" % table[3]
	return ""

func test_get_table_empty_result() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var res: Dictionary = s.get_table(db, "SELECT * FROM t;")
	s.close(db)
	if res.get("code", -1) != s.ok():
		return "get_table failed: %d" % res.get("code", -1)
	return _assert_eq("get_table empty rows", res.get("row_count", -1), 0)

func test_get_table_invalid_sql() -> String:
	var db := _open_memory()
	var res: Dictionary = s.get_table(db, "NOT VALID SQL;")
	s.close(db)
	if res.get("code", s.ok()) == s.ok():
		return "get_table invalid SQL unexpectedly returned SQLITE_OK"
	return ""

# ---------------------------------------------------------------------------
# 9. db_release_memory() / release_memory()
# ---------------------------------------------------------------------------

func test_db_release_memory_returns_ok() -> String:
	var db := _open_memory()
	var rc := s.db_release_memory(db)
	s.close(db)
	return _assert_eq("db_release_memory returns SQLITE_OK", rc, s.ok())

func test_release_memory_nonnegative() -> String:
	var freed := s.release_memory(1024)
	return _assert_true("release_memory returns >= 0", freed >= 0)

# ---------------------------------------------------------------------------
# 10. limit()
# ---------------------------------------------------------------------------

func test_limit_query_returns_positive() -> String:
	var db := _open_memory()
	var limit_id := s.limit_length()
	var current := s.limit(db, limit_id, -1)
	s.close(db)
	return _assert_gt("SQLITE_LIMIT_LENGTH > 0", current, 0)

func test_limit_set_and_retrieve() -> String:
	var db := _open_memory()
	var limit_id := s.limit_variable_number()
	var original := s.limit(db, limit_id, -1)
	var new_limit := 100
	var prev := s.limit(db, limit_id, new_limit)
	var after := s.limit(db, limit_id, -1)
	# Restore
	s.limit(db, limit_id, original)
	s.close(db)
	if prev != original:
		return "limit() should return previous value, got %d expected %d" % [prev, original]
	return _assert_eq("limit after set", after, new_limit)

# ---------------------------------------------------------------------------
# 11. Transactions and rollback
# ---------------------------------------------------------------------------

func test_transaction_commit_persists() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "BEGIN;")
	_exec(db, "INSERT INTO t VALUES (1);")
	_exec(db, "COMMIT;")
	var res: Dictionary = s.get_table(db, "SELECT COUNT(*) FROM t;")
	s.close(db)
	var table: PackedStringArray = res.get("result", PackedStringArray())
	if table.size() < 2:
		return "unexpected table size"
	return _assert_eq("row count after commit", table[1], "1")

func test_transaction_rollback_discards() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "BEGIN;")
	_exec(db, "INSERT INTO t VALUES (1);")
	_exec(db, "ROLLBACK;")
	var res: Dictionary = s.get_table(db, "SELECT COUNT(*) FROM t;")
	s.close(db)
	var table: PackedStringArray = res.get("result", PackedStringArray())
	if table.size() < 2:
		return "unexpected table size"
	return _assert_eq("row count after rollback", table[1], "0")

func test_savepoint_release() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "SAVEPOINT sp1;")
	_exec(db, "INSERT INTO t VALUES (42);")
	_exec(db, "RELEASE sp1;")
	var c := s.changes(db)
	s.close(db)
	return _assert_eq("changes after RELEASE savepoint", c, 1)

func test_savepoint_rollback_to() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	_exec(db, "SAVEPOINT sp1;")
	_exec(db, "INSERT INTO t VALUES (99);")
	_exec(db, "ROLLBACK TO sp1;")
	_exec(db, "RELEASE sp1;")
	var res: Dictionary = s.get_table(db, "SELECT COUNT(*) FROM t;")
	s.close(db)
	var table: PackedStringArray = res.get("result", PackedStringArray())
	if table.size() < 2:
		return "unexpected table size"
	return _assert_eq("row count after rollback to savepoint", table[1], "0")

# ---------------------------------------------------------------------------
# 12. next_stmt()
# ---------------------------------------------------------------------------

func test_next_stmt_null_when_no_statements() -> String:
	var db := _open_memory()
	var stmt = s.next_stmt(db, null)
	s.close(db)
	# With no prepared statements, next_stmt returns null
	return _assert_eq("next_stmt null when no stmts", stmt, null)

func test_next_stmt_finds_prepared_statement() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var res := s.prepare_v2(db, "SELECT * FROM t", -1)
	var stmt: Sqlite3StmtHandle = res.get("statement")
	var found = s.next_stmt(db, null)
	s.finalize(stmt)
	s.close(db)
	return _assert_ne("next_stmt finds prepared statement", found, null)
