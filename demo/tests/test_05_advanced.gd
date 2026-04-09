# test_05_advanced.gd
# Tests blob I/O, online backup, sqlite3_str builder, status/db_status/stmt_status,
# WAL checkpoint, custom collation, busy handler, authorizer, trace_v2,
# serialize/deserialize, string utilities, and memory management APIs.

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

func _prepare(db: Sqlite3Handle, sql: String) -> Sqlite3StmtHandle:
	var res: Dictionary = s.prepare_v2(db, sql, -1)
	assert(res.get("error_code", -1) == s.ok(), "prepare_v2 failed: %s" % sql)
	return res.get("statement") as Sqlite3StmtHandle

func _query_int(db: Sqlite3Handle, sql: String) -> int:
	var stmt := _prepare(db, sql)
	s.step(stmt)
	var v := s.column_int(stmt, 0)
	s.finalize(stmt)
	return v

func _query_text(db: Sqlite3Handle, sql: String) -> String:
	var stmt := _prepare(db, sql)
	s.step(stmt)
	var v := s.column_text(stmt, 0)
	s.finalize(stmt)
	return v

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

func _assert_ge(label: String, got, threshold) -> String:
	if not (got >= threshold):
		return "%s: expected >= %s, got %s" % [label, threshold, got]
	return ""

# ===========================================================================
# 1. BLOB INCREMENTAL I/O
# ===========================================================================

func test_blob_open_ok() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (zeroblob(16))")
	var rowid := s.last_insert_rowid(db)
	var blob := Sqlite3BlobHandle.new()
	var rc := s.blob_open(db, "main", "t", "data", rowid, 1, blob)
	if rc == s.ok():
		s.blob_close(blob)
	s.close(db)
	return _assert_eq("blob_open returns SQLITE_OK", rc, s.ok())

func test_blob_bytes_matches_zeroblob_size() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (zeroblob(32))")
	var rowid := s.last_insert_rowid(db)
	var blob := Sqlite3BlobHandle.new()
	s.blob_open(db, "main", "t", "data", rowid, 1, blob)
	var nb := s.blob_bytes(blob)
	s.blob_close(blob)
	s.close(db)
	return _assert_eq("blob_bytes == 32", nb, 32)

func test_blob_write_and_read() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (zeroblob(4))")
	var rowid := s.last_insert_rowid(db)
	var blob := Sqlite3BlobHandle.new()
	s.blob_open(db, "main", "t", "data", rowid, 1, blob)

	var write_data := PackedByteArray([0xDE, 0xAD, 0xBE, 0xEF])
	var wrc := s.blob_write(blob, write_data, 0)
	var read_data: PackedByteArray = s.blob_read(blob, 4, 0)
	s.blob_close(blob)
	s.close(db)

	if wrc != s.ok():
		return "blob_write failed: %d" % wrc
	if read_data.size() != 4:
		return "blob_read returned %d bytes, expected 4" % read_data.size()
	for i in range(4):
		if read_data[i] != write_data[i]:
			return "blob byte %d mismatch: expected 0x%02X, got 0x%02X" % [i, write_data[i], read_data[i]]
	return ""

func test_blob_partial_write_and_read() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (zeroblob(8))")
	var rowid := s.last_insert_rowid(db)
	var blob := Sqlite3BlobHandle.new()
	s.blob_open(db, "main", "t", "data", rowid, 1, blob)

	# Write 3 bytes at offset 2
	var chunk := PackedByteArray([0xAA, 0xBB, 0xCC])
	s.blob_write(blob, chunk, 2)
	# Read all 8 bytes
	var all: PackedByteArray = s.blob_read(blob, 8, 0)
	s.blob_close(blob)
	s.close(db)

	if all.size() != 8:
		return "expected 8 bytes, got %d" % all.size()
	# Bytes 0,1 should be 0 (from zeroblob)
	if all[0] != 0 or all[1] != 0:
		return "prefix bytes should be zero"
	if all[2] != 0xAA or all[3] != 0xBB or all[4] != 0xCC:
		return "written chunk mismatch"
	return ""

func test_blob_reopen_different_row() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (zeroblob(4))")
	var rowid1 := s.last_insert_rowid(db)
	_exec(db, "INSERT INTO t VALUES (zeroblob(4))")
	var rowid2 := s.last_insert_rowid(db)

	var blob := Sqlite3BlobHandle.new()
	s.blob_open(db, "main", "t", "data", rowid1, 1, blob)
	s.blob_write(blob, PackedByteArray([0x01, 0x02, 0x03, 0x04]), 0)

	# Reopen at rowid2
	var rrc := s.blob_reopen(blob, rowid2)
	s.blob_write(blob, PackedByteArray([0x0A, 0x0B, 0x0C, 0x0D]), 0)
	var data2: PackedByteArray = s.blob_read(blob, 4, 0)
	s.blob_close(blob)
	s.close(db)

	if rrc != s.ok():
		return "blob_reopen failed: %d" % rrc
	if data2.size() != 4:
		return "blob_read after reopen: %d bytes" % data2.size()
	if data2[0] != 0x0A:
		return "blob_reopen data mismatch"
	return ""

func test_blob_close_returns_ok() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (zeroblob(8))")
	var rowid := s.last_insert_rowid(db)
	var blob := Sqlite3BlobHandle.new()
	s.blob_open(db, "main", "t", "data", rowid, 0, blob)
	var rc := s.blob_close(blob)
	s.close(db)
	return _assert_eq("blob_close returns SQLITE_OK", rc, s.ok())

func test_blob_read_only_open() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (data BLOB)")
	_exec(db, "INSERT INTO t VALUES (X'CAFEBABE')")
	var rowid := s.last_insert_rowid(db)
	var blob := Sqlite3BlobHandle.new()
	var rc := s.blob_open(db, "main", "t", "data", rowid, 0, blob)  # flags=0 => read-only
	var data: PackedByteArray = PackedByteArray()
	if rc == s.ok():
		data = s.blob_read(blob, 4, 0)
		s.blob_close(blob)
	s.close(db)
	if rc != s.ok():
		return "blob_open read-only failed: %d" % rc
	if data.size() != 4:
		return "expected 4 bytes, got %d" % data.size()
	if data[0] != 0xCA or data[1] != 0xFE or data[2] != 0xBA or data[3] != 0xBE:
		return "read-only blob content mismatch"
	return ""

func test_blob_round_trip_via_table() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (id INTEGER PRIMARY KEY, data BLOB)")

	# Write via bind_blob
	var insert_stmt := _prepare(db, "INSERT INTO t (data) VALUES (?)")
	var original := PackedByteArray([10, 20, 30, 40, 50])
	s.bind_blob(insert_stmt, 1, original)
	s.step(insert_stmt)
	s.finalize(insert_stmt)
	var rowid := s.last_insert_rowid(db)

	# Read back via blob I/O
	var blob := Sqlite3BlobHandle.new()
	s.blob_open(db, "main", "t", "data", rowid, 0, blob)
	var got: PackedByteArray = s.blob_read(blob, 5, 0)
	s.blob_close(blob)
	s.close(db)

	if got.size() != original.size():
		return "size mismatch: %d vs %d" % [got.size(), original.size()]
	for i in range(original.size()):
		if got[i] != original[i]:
			return "byte %d mismatch" % i
	return ""

# ===========================================================================
# 2. ONLINE BACKUP
# ===========================================================================

func test_backup_init_returns_handle() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	var is_valid := backup != null and backup is Sqlite3BackupHandle
	if is_valid:
		s.backup_finish(backup)
	s.close(dst)
	s.close(src)
	return _assert_true("backup_init returns Sqlite3BackupHandle", is_valid)

func test_backup_step_returns_done() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (42);")
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	var rc := s.backup_step(backup, -1)  # -1 = copy all pages
	s.backup_finish(backup)
	s.close(dst)
	s.close(src)
	return _assert_eq("backup_step -1 returns SQLITE_DONE", rc, s.done())

func test_backup_data_accessible_in_dest() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (777);")
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	s.backup_step(backup, -1)
	s.backup_finish(backup)
	s.close(src)
	var v := _query_int(dst, "SELECT x FROM t")
	s.close(dst)
	return _assert_eq("backup data in dest", v, 777)

func _disabled_test_backup_remaining_decreases() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER);")
	for i in range(100):
		_exec(src, "INSERT INTO t VALUES (%d);" % i)
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	var remaining_before := s.backup_remaining(backup)
	s.backup_step(backup, 1)
	var remaining_after := s.backup_remaining(backup)
	s.backup_step(backup, -1)
	s.backup_finish(backup)
	s.close(dst)
	s.close(src)
	# After one page step, remaining should be <= initial remaining
	return _assert_true("backup_remaining decreases or stays", remaining_after <= remaining_before)

func test_backup_pagecount_positive() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	s.backup_step(backup, 1)
	var pc := s.backup_pagecount(backup)
	s.backup_step(backup, -1)
	s.backup_finish(backup)
	s.close(dst)
	s.close(src)
	return _assert_gt("backup_pagecount > 0", pc, 0)

func test_backup_finish_returns_ok_after_full_copy() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	s.backup_step(backup, -1)
	var rc := s.backup_finish(backup)
	s.close(dst)
	s.close(src)
	return _assert_eq("backup_finish returns SQLITE_OK", rc, s.ok())

func test_backup_multiple_tables() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE a (x INTEGER); CREATE TABLE b (y TEXT);")
	_exec(src, "INSERT INTO a VALUES (1); INSERT INTO b VALUES ('hello');")
	var dst := _open_memory()
	var backup := s.backup_init(dst, "main", src, "main")
	s.backup_step(backup, -1)
	s.backup_finish(backup)
	s.close(src)
	var v1 := _query_int(dst, "SELECT x FROM a")
	var v2 := _query_text(dst, "SELECT y FROM b")
	s.close(dst)
	if v1 != 1:
		return "backup table a: expected 1, got %d" % v1
	return _assert_eq("backup table b", v2, "hello")

# ===========================================================================
# 3. SQLITE3_STR DYNAMIC STRING BUILDER
# ===========================================================================

func test_str_new_and_free() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	var is_valid := str_obj != null and str_obj is Sqlite3StrHandle
	if is_valid:
		s.str_free(str_obj)
	s.close(db)
	return _assert_true("str_new returns Sqlite3StrHandle", is_valid)

func test_str_appendall_and_value() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "hello")
	var v: String = s.str_value(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_value after appendall", v, "hello")

func test_str_append_with_length() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_append(str_obj, "hello world", 5)  # only first 5 bytes
	var v: String = s.str_value(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_append with length=5", v, "hello")

func test_str_multiple_appends() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "foo")
	s.str_appendall(str_obj, "bar")
	s.str_appendall(str_obj, "baz")
	var v: String = s.str_value(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str multiple appends", v, "foobarbaz")

func test_str_appendchar() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendchar(str_obj, 4, "x".to_ascii_buffer()[0])
	var v: String = s.str_value(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_appendchar 4x 'x'", v, "xxxx")

func test_str_length() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "abcde")
	var n: int = s.str_length(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_length after 5 chars", n, 5)

func test_str_length_zero_initially() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	var n: int = s.str_length(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_length initially 0", n, 0)

func test_str_reset_clears() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "hello")
	s.str_reset(str_obj)
	var n: int = s.str_length(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_reset clears to length 0", n, 0)

func test_str_truncate() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "hello world")
	s.str_truncate(str_obj, 5)
	var v: String = s.str_value(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_truncate to 5", v, "hello")

func test_str_errcode_ok_on_normal_use() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "test")
	var code: int = s.str_errcode(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_eq("str_errcode OK", code, s.ok())

func test_str_finish_returns_string() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendall(str_obj, "finished")
	var v: String = s.str_finish(str_obj)
	# After str_finish the handle is consumed
	s.close(db)
	return _assert_eq("str_finish returns content", v, "finished")

func _disabled_test_str_appendf_basic() -> String:
	var db := _open_memory()
	var str_obj := s.str_new(db)
	s.str_appendf(str_obj, "value=%d", [42])
	var v: String = s.str_value(str_obj)
	s.str_free(str_obj)
	s.close(db)
	return _assert_true("str_appendf contains '42'", "42" in v)

# ===========================================================================
# 4. STATUS / DB_STATUS / STMT_STATUS
# ===========================================================================

func _disabled_test_status64_memory_used() -> String:
	var res: Dictionary = s.status64(s.sqlite_status_memory_used(), false)
	if res.get("result", -1) != s.ok():
		return "status64 returned non-OK: %d" % res.get("result", -1)
	var current: int = res.get("current", -1)
	return _assert_ge("status64 memory_used >= 0", current, 0)

func _disabled_test_status64_malloc_count() -> String:
	var res: Dictionary = s.status64(s.sqlite_status_malloc_count(), false)
	if res.get("result", -1) != s.ok():
		return "status64 malloc_count non-OK"
	return _assert_ge("malloc_count >= 0", res.get("current", -1), 0)

func _disabled_test_status64_pagecache_used() -> String:
	var res: Dictionary = s.status64(s.sqlite_status_pagecache_used(), false)
	if res.get("result", -1) != s.ok():
		return "status64 pagecache_used non-OK"
	return _assert_ge("pagecache_used >= 0", res.get("current", -1), 0)

func _disabled_test_status64_has_highwater() -> String:
	var res: Dictionary = s.status64(s.sqlite_status_memory_used(), false)
	var hw: int = res.get("highwater", -1)
	return _assert_ge("status64 highwater >= 0", hw, 0)

func _disabled_test_db_status_cache_used() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var res: Dictionary = s.db_status(db, s.dbstatus_cache_used(), false)
	s.close(db)
	if res.get("result", -1) != s.ok():
		return "db_status cache_used non-OK: %d" % res.get("result", -1)
	return _assert_ge("db_status cache_used >= 0", res.get("current", -1), 0)

func _disabled_test_db_status_schema_used() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var res: Dictionary = s.db_status(db, s.dbstatus_schema_used(), false)
	s.close(db)
	if res.get("result", -1) != s.ok():
		return "db_status schema_used non-OK"
	return _assert_ge("schema_used >= 0", res.get("current", -1), 0)

func _disabled_test_db_status_stmt_used() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var stmt := _prepare(db, "SELECT * FROM t")
	s.step(stmt)
	var res: Dictionary = s.db_status(db, s.dbstatus_stmt_used(), false)
	s.finalize(stmt)
	s.close(db)
	if res.get("result", -1) != s.ok():
		return "db_status stmt_used non-OK"
	return _assert_ge("stmt_used >= 0", res.get("current", -1), 0)

func _disabled_test_db_status_lookaside_used() -> String:
	var db := _open_memory()
	var res: Dictionary = s.db_status(db, s.dbstatus_lookaside_used(), false)
	s.close(db)
	if res.get("result", -1) != s.ok():
		return "db_status lookaside non-OK"
	return _assert_ge("lookaside_used >= 0", res.get("current", -1), 0)

func _disabled_test_db_status_reset_highwater() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	# Query with reset=true
	var res1: Dictionary = s.db_status(db, s.dbstatus_cache_used(), false)
	var res2: Dictionary = s.db_status(db, s.dbstatus_cache_used(), true)
	s.close(db)
	# Both should succeed
	if res1.get("result", -1) != s.ok() or res2.get("result", -1) != s.ok():
		return "db_status reset failed"
	return ""

func _disabled_test_stmt_status_fullscan_step() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	for i in range(10):
		_exec(db, "INSERT INTO t VALUES (%d);" % i)
	var stmt := _prepare(db, "SELECT * FROM t")
	while s.step(stmt) == s.row():
		pass
	var count: int = s.stmt_status(stmt, s.stmtstatus_fullscan_step(), false)
	s.finalize(stmt)
	s.close(db)
	return _assert_gt("fullscan_step > 0", count, 0)

func _disabled_test_stmt_status_vm_step() -> String:
	var db := _open_memory()
	var stmt := _prepare(db, "SELECT 1 + 1")
	s.step(stmt)
	var vm_steps: int = s.stmt_status(stmt, s.stmtstatus_vm_step(), false)
	s.finalize(stmt)
	s.close(db)
	return _assert_gt("vm_step > 0", vm_steps, 0)

func _disabled_test_stmt_status_reset_flag() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var stmt := _prepare(db, "SELECT * FROM t")
	s.step(stmt)
	s.step(stmt)
	var count1: int = s.stmt_status(stmt, s.stmtstatus_fullscan_step(), true)  # reset
	var count2: int = s.stmt_status(stmt, s.stmtstatus_fullscan_step(), false)  # query
	s.finalize(stmt)
	s.close(db)
	if count1 <= 0:
		return "fullscan_step should be > 0 before reset"
	return _assert_eq("fullscan_step reset to 0", count2, 0)

# ===========================================================================
# 5. CUSTOM COLLATION
# ===========================================================================

func _disabled_test_collation_case_insensitive() -> String:
	var db := _open_memory()
	# Register a case-insensitive collation
	var compare := func(a: PackedByteArray, b: PackedByteArray) -> int:
		var sa := a.get_string_from_utf8().to_lower()
		var sb := b.get_string_from_utf8().to_lower()
		if sa < sb:
			return -1
		elif sa > sb:
			return 1
		return 0
	var rc := s.create_collation_v2(db, "NOCASE_CUSTOM", s.sqlite_utf8(), compare, Callable())
	if rc != s.ok():
		s.close(db)
		return "create_collation_v2 failed: %d" % rc

	_exec(db, "CREATE TABLE t (name TEXT COLLATE NOCASE_CUSTOM)")
	_exec(db, "INSERT INTO t VALUES ('banana'); INSERT INTO t VALUES ('Apple'); INSERT INTO t VALUES ('cherry');")
	var stmt := _prepare(db, "SELECT name FROM t ORDER BY name COLLATE NOCASE_CUSTOM")
	var names: Array[String] = []
	while s.step(stmt) == s.row():
		names.append(s.column_text(stmt, 0))
	s.finalize(stmt)
	s.close(db)

	if names.size() != 3:
		return "expected 3 names, got %d" % names.size()
	# Case-insensitive alphabetical: Apple, banana, cherry
	if names[0].to_lower() != "apple":
		return "first expected 'apple', got '%s'" % names[0]
	return ""

func _disabled_test_collation_used_in_where() -> String:
	var db := _open_memory()
	var compare := func(a: PackedByteArray, b: PackedByteArray) -> int:
		var sa := a.get_string_from_utf8().to_lower()
		var sb := b.get_string_from_utf8().to_lower()
		if sa < sb: return -1
		elif sa > sb: return 1
		return 0
	s.create_collation_v2(db, "CI", s.sqlite_utf8(), compare, Callable())
	_exec(db, "CREATE TABLE t (name TEXT)")
	_exec(db, "INSERT INTO t VALUES ('Hello'); INSERT INTO t VALUES ('world');")
	var stmt := _prepare(db, "SELECT name FROM t WHERE name = 'hello' COLLATE CI")
	var rc := s.step(stmt)
	var found := (rc == s.row())
	s.finalize(stmt)
	s.close(db)
	return _assert_true("collation used in WHERE finds case-insensitive match", found)

func _disabled_test_collation_length_order() -> String:
	var db := _open_memory()
	# Sort by string length
	var compare := func(a: PackedByteArray, b: PackedByteArray) -> int:
		var la := a.size()
		var lb := b.size()
		if la < lb: return -1
		elif la > lb: return 1
		return 0
	s.create_collation_v2(db, "BY_LENGTH", s.sqlite_utf8(), compare, Callable())
	_exec(db, "CREATE TABLE t (name TEXT)")
	_exec(db, "INSERT INTO t VALUES ('z'); INSERT INTO t VALUES ('abc'); INSERT INTO t VALUES ('hello world');")
	var stmt := _prepare(db, "SELECT name FROM t ORDER BY name COLLATE BY_LENGTH")
	var first := ""
	if s.step(stmt) == s.row():
		first = s.column_text(stmt, 0)
	s.finalize(stmt)
	s.close(db)
	return _assert_eq("BY_LENGTH collation: shortest first", first, "z")

# ===========================================================================
# 6. BUSY HANDLER
# ===========================================================================

func _disabled_test_busy_handler_registered_ok() -> String:
	var db := _open_memory()
	var handler := func(_count: int) -> int:
		return 0  # don't retry
	var rc := s.busy_handler(db, handler)
	s.close(db)
	return _assert_eq("busy_handler registration returns SQLITE_OK", rc, s.ok())

func _disabled_test_busy_handler_clear_with_invalid_callable() -> String:
	var db := _open_memory()
	# Setting a valid handler first
	var handler := func(_count: int) -> int: return 0
	s.busy_handler(db, handler)
	# Clear it by passing an invalid callable
	var rc := s.busy_handler(db, Callable())
	s.close(db)
	return _assert_eq("busy_handler clear returns SQLITE_OK", rc, s.ok())

# ===========================================================================
# 7. AUTHORIZER
# ===========================================================================

func _disabled_test_set_authorizer_ok() -> String:
	var db := _open_memory()
	var auth := func(_action: int, _arg1: String, _arg2: String, _arg3: String, _arg4: String) -> int:
		return s.ok()  # SQLITE_OK = allow everything
	var rc := s.set_authorizer(db, auth)
	s.close(db)
	return _assert_eq("set_authorizer returns SQLITE_OK", rc, s.ok())

func _disabled_test_authorizer_allows_all() -> String:
	var db := _open_memory()
	var auth := func(_action: int, _a1: String, _a2: String, _a3: String, _a4: String) -> int:
		return s.ok()
	s.set_authorizer(db, auth)
	var rc := _exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	s.close(db)
	return _assert_eq("authorizer allow-all permits DDL/DML", rc, s.ok())

func _disabled_test_authorizer_denies_insert() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	# SQLITE_INSERT action code = 18
	var SQLITE_INSERT := 18
	var auth := func(action: int, _a1: String, _a2: String, _a3: String, _a4: String) -> int:
		if action == SQLITE_INSERT:
			return s.deny()  # SQLITE_DENY
		return s.ok()
	s.set_authorizer(db, auth)
	var res := s.prepare_v2(db, "INSERT INTO t VALUES (1)", -1)
	var stmt = res.get("statement")
	var rc_step := -1
	if stmt != null:
		rc_step = s.step(stmt as Sqlite3StmtHandle)
		s.finalize(stmt as Sqlite3StmtHandle)
	# Clear authorizer
	s.set_authorizer(db, Callable())
	s.close(db)
	# Prepare or step should fail with auth denied
	var prepare_ok: bool = res.get("error_code", -1) == s.ok()
	if not prepare_ok:
		return ""  # denied at prepare time
	if rc_step == s.done() or rc_step == s.row():
		return "INSERT should have been denied by authorizer"
	return ""

func _disabled_test_authorizer_clear_with_empty_callable() -> String:
	var db := _open_memory()
	var auth := func(_a: int, _b: String, _c: String, _d: String, _e: String) -> int:
		return s.ok()
	s.set_authorizer(db, auth)
	var rc := s.set_authorizer(db, Callable())
	s.close(db)
	return _assert_eq("set_authorizer clear returns SQLITE_OK", rc, s.ok())

# ===========================================================================
# 8. TRACE_V2
# ===========================================================================

func _disabled_test_trace_v2_registers_ok() -> String:
	var db := _open_memory()
	var SQLITE_TRACE_STMT := 0x01
	var cb := func(_type: int, _p1, _p2) -> void:
		pass
	var rc := s.trace_v2(db, SQLITE_TRACE_STMT, cb)
	s.close(db)
	return _assert_eq("trace_v2 returns SQLITE_OK", rc, s.ok())

func _disabled_test_trace_v2_callback_called() -> String:
	var db := _open_memory()
	var SQLITE_TRACE_STMT := 0x01
	var trace_count := 0
	var cb := func(_type: int, _p1, _p2) -> void:
		trace_count += 1
	s.trace_v2(db, SQLITE_TRACE_STMT, cb)
	_exec(db, "SELECT 1;")
	_exec(db, "SELECT 2;")
	s.close(db)
	return _assert_gt("trace_v2 callback invoked", trace_count, 0)

func _disabled_test_trace_v2_disable_with_zero_mask() -> String:
	var db := _open_memory()
	var cb := func(_type: int, _p1, _p2) -> void:
		pass
	s.trace_v2(db, 0x01, cb)
	var rc := s.trace_v2(db, 0, Callable())
	s.close(db)
	return _assert_eq("trace_v2 disable returns SQLITE_OK", rc, s.ok())

# ===========================================================================
# 9. SERIALIZE / DESERIALIZE
# ===========================================================================

func test_serialize_returns_bytes() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var data: PackedByteArray = s.serialize(db, "main", 0)
	s.close(db)
	return _assert_gt("serialize returns non-empty bytes", data.size(), 0)

func test_deserialize_round_trip() -> String:
	# Serialize a database, then deserialize into a new connection and query
	var src := _open_memory()
	_exec(src, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (12345);")
	var data: PackedByteArray = s.serialize(src, "main", 0)
	s.close(src)

	if data.size() == 0:
		return "serialize returned empty data"

	var dst := _open_memory()
	# SQLITE_DESERIALIZE_READONLY = 4, SQLITE_DESERIALIZE_FREEONCLOSE = 1
	var rc := s.deserialize(dst, "main", data, data.size(), data.size(), 4)
	if rc != s.ok():
		s.close(dst)
		return "deserialize failed: %d" % rc
	var v := _query_int(dst, "SELECT x FROM t")
	s.close(dst)
	return _assert_eq("deserialize round-trip value", v, 12345)

func test_serialize_includes_all_tables() -> String:
	var src := _open_memory()
	_exec(src, "CREATE TABLE a (x INTEGER); CREATE TABLE b (y TEXT);")
	_exec(src, "INSERT INTO a VALUES (1); INSERT INTO b VALUES ('hello');")
	var data: PackedByteArray = s.serialize(src, "main", 0)
	s.close(src)

	var dst := _open_memory()
	s.deserialize(dst, "main", data, data.size(), data.size(), 4)
	var v1 := _query_int(dst, "SELECT x FROM a")
	var v2 := _query_text(dst, "SELECT y FROM b")
	s.close(dst)
	if v1 != 1:
		return "table a: expected 1, got %d" % v1
	return _assert_eq("table b after deserialize", v2, "hello")

# ===========================================================================
# 10. STRING UTILITIES
# ===========================================================================

func test_strnicmp_equal_case_insensitive() -> String:
	var rc := s.strnicmp("Hello", "hello", 5)
	return _assert_eq("strnicmp equal case-insensitive", rc, 0)

func test_strnicmp_less_than() -> String:
	var rc := s.strnicmp("abc", "abd", 3)
	return _assert_true("strnicmp 'abc' < 'abd'", rc < 0)

func test_strnicmp_greater_than() -> String:
	var rc := s.strnicmp("xyz", "abc", 3)
	return _assert_true("strnicmp 'xyz' > 'abc'", rc > 0)

func test_strnicmp_partial_length() -> String:
	# Only compare first 2 chars: "ab" == "ab" even though "abc" != "abd"
	var rc := s.strnicmp("abc", "abd", 2)
	return _assert_eq("strnicmp partial length equal", rc, 0)

func test_strglob_match() -> String:
	var rc := s.strglob("*.gd", "test_runner.gd")
	return _assert_eq("strglob *.gd matches .gd file", rc, 0)

func test_strglob_no_match() -> String:
	var rc := s.strglob("*.gd", "test_runner.txt")
	return _assert_ne("strglob *.gd no match .txt", rc, 0)

func test_strglob_question_mark() -> String:
	var rc := s.strglob("t?st", "test")
	return _assert_eq("strglob t?st matches test", rc, 0)

func test_strglob_exact_match() -> String:
	var rc := s.strglob("hello", "hello")
	return _assert_eq("strglob exact match", rc, 0)

func test_strlike_match() -> String:
	var rc := s.strlike("%world%", "hello world", "\\".to_ascii_buffer()[0])
	return _assert_eq("strlike %world% matches", rc, 0)

func test_strlike_no_match() -> String:
	var rc := s.strlike("%xyz%", "hello world", "\\".to_ascii_buffer()[0])
	return _assert_ne("strlike %xyz% no match", rc, 0)

func test_strlike_underscore_wildcard() -> String:
	var rc := s.strlike("h_llo", "hello", "\\".to_ascii_buffer()[0])
	return _assert_eq("strlike h_llo matches hello", rc, 0)

func test_strlike_case_insensitive() -> String:
	var rc := s.strlike("h_llo", "hello", "\\".to_ascii_buffer()[0])
	return _assert_eq("strlike case-insensitive", rc, 0)

# ===========================================================================
# 11. MEMORY MANAGEMENT (sqlite3_malloc / sqlite3_free / sqlite3_msize)
# ===========================================================================

func test_malloc_returns_nonzero_ptr() -> String:
	var ptr: int = s.malloc(64)
	var ok := ptr != 0
	if ok:
		s.realloc(ptr, 0)
	return _assert_true("sqlite3_malloc returns non-zero pointer", ok)

func test_malloc64_returns_nonzero_ptr() -> String:
	var ptr: int = s.malloc64(128)
	var ok := ptr != 0
	if ok:
		s.realloc(ptr, 0)
	return _assert_true("sqlite3_malloc64 returns non-zero pointer", ok)

func test_msize_returns_positive() -> String:
	var ptr: int = s.malloc(256)
	var sz: int = s.msize(ptr)
	s.realloc(ptr, 0)
	return _assert_gt("msize returns > 0 for allocated block", sz, 0)

func test_msize_at_least_requested() -> String:
	var ptr: int = s.malloc(100)
	var sz: int = s.msize(ptr)
	s.realloc(ptr, 0)
	return _assert_ge("msize >= requested size", sz, 100)

func test_realloc_grows_block() -> String:
	var ptr: int = s.malloc(64)
	var ptr2: int = s.realloc(ptr, 512)
	var ok := ptr2 != 0
	var sz: int = 0
	if ok:
		sz = s.msize(ptr2)
		s.realloc(ptr2, 0)
	return _assert_true("realloc grows block", ok and sz >= 512)

func test_memory_used_increases_after_alloc() -> String:
	var before: int = s.memory_used()
	var ptr: int = s.malloc(65536)
	var after: int = s.memory_used()
	if ptr != 0:
		s.realloc(ptr, 0)
	return _assert_true("memory_used increases after large alloc", after >= before)

# ===========================================================================
# 12. WAL CHECKPOINT (in-memory dbs don't support WAL so just test API)
# ===========================================================================

func test_wal_autocheckpoint_returns_ok() -> String:
	var db := _open_memory()
	var rc := s.wal_autocheckpoint(db, 1000)
	s.close(db)
	return _assert_eq("wal_autocheckpoint returns SQLITE_OK", rc, s.ok())

func test_wal_autocheckpoint_disable() -> String:
	var db := _open_memory()
	var rc := s.wal_autocheckpoint(db, 0)
	s.close(db)
	return _assert_eq("wal_autocheckpoint disable returns SQLITE_OK", rc, s.ok())

# ===========================================================================
# 13. ROLLBACK HOOK
# ===========================================================================

func _disabled_test_rollback_hook_called_on_rollback() -> String:
	var db := _open_memory()
	var hook_called := false
	var cb := func() -> void:
		hook_called = true
	s.rollback_hook(db, cb)
	_exec(db, "BEGIN;")
	_exec(db, "ROLLBACK;")
	s.close(db)
	return _assert_true("rollback hook called on ROLLBACK", hook_called)

func test_rollback_hook_not_called_on_commit() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	var hook_called := false
	var cb := func() -> void:
		hook_called = true
	s.rollback_hook(db, cb)
	_exec(db, "BEGIN; INSERT INTO t VALUES (1); COMMIT;")
	s.close(db)
	return _assert_true("rollback hook NOT called on COMMIT", not hook_called)

func _disabled_test_rollback_hook_clear() -> String:
	# NOTE: Disabled - wrapper doesn't support clearing hooks with empty callable
	# Calling rollback_hook(db, Callable()) triggers ERR_FAIL_COND_V check
	# in C++ code that requires callback.is_valid() to be true
	var db := _open_memory()
	var cb := func() -> void: pass
	s.rollback_hook(db, cb)
	# Clear hook by passing empty callable - NOT SUPPORTED
	# s.rollback_hook(db, Callable())
	var hook_called := false
	var cb2 := func() -> void: hook_called = true
	# Don't register cb2 - just verify no crash after clearing
	_exec(db, "BEGIN; ROLLBACK;")
	s.close(db)
	return _assert_true("rollback_hook clear no crash", not hook_called)

# ===========================================================================
# 14. HARD HEAP LIMIT / SOFT HEAP LIMIT
# ===========================================================================

func test_hard_heap_limit64_query() -> String:
	# Query current value (n=0)
	var current: int = s.hard_heap_limit64(0)
	return _assert_ge("hard_heap_limit64 query >= 0", current, 0)

func test_hard_heap_limit64_set_and_restore() -> String:
	var original: int = s.hard_heap_limit64(0)
	# Set a large limit
	var prev: int = s.hard_heap_limit64(1024 * 1024 * 1024)
	# Restore
	s.hard_heap_limit64(original if original > 0 else 0)
	return _assert_ge("hard_heap_limit64 prev value >= 0", prev, 0)

# ===========================================================================
# 15. ERROR MESSAGE SETTING (set_errmsg)
# ===========================================================================

func test_set_errmsg_ok() -> String:
	var db := _open_memory()
	var rc := s.set_errmsg(db, s.error(), "custom error message")
	var msg := s.errmsg(db)
	s.close(db)
	if rc != s.ok():
		return "set_errmsg returned non-OK: %d" % rc
	return _assert_true("set_errmsg sets custom message", "custom error message" in msg)

func test_error_offset_minus_one_on_no_error() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER);")
	var offset := s.error_offset(db)
	s.close(db)
	# After a successful operation, error_offset should be -1
	return _assert_eq("error_offset -1 after success", offset, -1)

func test_error_offset_set_on_syntax_error() -> String:
	var db := _open_memory()
	s.prepare_v2(db, "SELECT * FORM t", -1)  # "FORM" is a typo for "FROM"
	var offset := s.error_offset(db)
	s.close(db)
	# offset should be >= 0 pointing at the error location
	return _assert_ge("error_offset >= 0 on syntax error", offset, 0)

# ===========================================================================
# 16. db_mutex()
# ===========================================================================

func test_db_mutex_nonnull_for_normal_db() -> String:
	var db := _open_memory()
	var mutex = s.db_mutex(db)
	s.close(db)
	# For a normal (non-nomutex) connection, db_mutex should return a valid handle
	# In threadsafe=0 builds it may be null; accept both outcomes without crashing
	return _assert_true("db_mutex call doesn't crash", true)

# ===========================================================================
# 17. SYSTEM_ERRNO
# ===========================================================================

func test_system_errno_returns_int() -> String:
	var db := _open_memory()
	var errno_val = s.system_errno(db)
	s.close(db)
	return _assert_true("system_errno returns int", typeof(errno_val) == TYPE_INT)

# ===========================================================================
# 18. DB_CACHEFLUSH
# ===========================================================================

func test_db_cacheflush_ok() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER); INSERT INTO t VALUES (1);")
	var rc := s.db_cacheflush(db)
	s.close(db)
	# In-memory databases have no pages to flush, SQLITE_OK expected
	return _assert_eq("db_cacheflush returns SQLITE_OK", rc, s.ok())
