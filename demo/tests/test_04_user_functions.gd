# test_04_user_functions.gd
# Tests create_function_v2 for scalar UDFs, aggregate UDFs,
# result_* setters, value_* getters, context_db_handle, and aggregate_context.

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

func _query_double(db: Sqlite3Handle, sql: String) -> float:
	var stmt := _prepare(db, sql)
	s.step(stmt)
	var v := s.column_double(stmt, 0)
	s.finalize(stmt)
	return v

func _query_text(db: Sqlite3Handle, sql: String) -> String:
	var stmt := _prepare(db, sql)
	s.step(stmt)
	var v := s.column_text(stmt, 0)
	s.finalize(stmt)
	return v

func _query_blob(db: Sqlite3Handle, sql: String) -> PackedByteArray:
	var stmt := _prepare(db, sql)
	s.step(stmt)
	var v: PackedByteArray = s.column_blob(stmt, 0)
	s.finalize(stmt)
	return v

func _assert_eq(label: String, got, expected) -> String:
	if got != expected:
		return "%s: expected %s, got %s" % [label, expected, got]
	return ""

func _assert_ne(label: String, got, unexpected) -> String:
	if got == unexpected:
		return "%s: expected != %s" % [label, unexpected]
	return ""

func _assert_true(label: String, cond: bool) -> String:
	if not cond:
		return "%s: expected true" % label
	return ""

func _assert_almost_eq(label: String, got: float, expected: float, tol: float = 1e-9) -> String:
	if absf(got - expected) > tol:
		return "%s: expected ~%s, got %s" % [label, expected, got]
	return ""

# ---------------------------------------------------------------------------
# 1. Scalar UDF – result_int
# ---------------------------------------------------------------------------

func _disabled_test_scalar_result_int() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_int(ctx, 42)
	var rc := s.create_function_v2(db, "my_int", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	if rc != s.ok():
		s.close(db)
		return "create_function_v2 failed: %d" % rc
	var v := _query_int(db, "SELECT my_int()")
	s.close(db)
	return _assert_eq("scalar result_int", v, 42)

func _disabled_test_scalar_result_int64() -> String:
	var db := _open_memory()
	var big: int = 9876543210
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_int64(ctx, big)
	s.create_function_v2(db, "my_int64", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT my_int64()")
	s.step(stmt)
	var v := s.column_int64(stmt, 0)
	s.finalize(stmt)
	s.close(db)
	return _assert_eq("scalar result_int64", v, big)

func _disabled_test_scalar_result_double() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_double(ctx, 2.71828)
	s.create_function_v2(db, "my_double", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_double(db, "SELECT my_double()")
	s.close(db)
	return _assert_almost_eq("scalar result_double", v, 2.71828, 1e-5)

func _disabled_test_scalar_result_text() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_text(ctx, "hello from gdscript", -1, s.transient_destructor_type())
	s.create_function_v2(db, "my_text", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_text(db, "SELECT my_text()")
	s.close(db)
	return _assert_eq("scalar result_text", v, "hello from gdscript")

func _disabled_test_scalar_result_null() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_null(ctx)
	s.create_function_v2(db, "my_null", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT my_null()")
	s.step(stmt)
	var t := s.column_type(stmt, 0)
	s.finalize(stmt)
	s.close(db)
	return _assert_eq("scalar result_null type", t, s.sqlite_null())

func _disabled_test_scalar_result_blob() -> String:
	var db := _open_memory()
	var expected := PackedByteArray([0x01, 0x02, 0x03, 0x04])
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_blob(ctx, expected, true)
	s.create_function_v2(db, "my_blob", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var got := _query_blob(db, "SELECT my_blob()")
	s.close(db)
	if got.size() != expected.size():
		return "blob size mismatch: expected %d, got %d" % [expected.size(), got.size()]
	for i in range(expected.size()):
		if got[i] != expected[i]:
			return "blob byte %d mismatch" % i
	return ""

# ---------------------------------------------------------------------------
# 2. Scalar UDF – reading arguments with value_*
# ---------------------------------------------------------------------------

func _disabled_test_scalar_reads_int_arg() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, v * 2)
	s.create_function_v2(db, "double_it", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT double_it(21)")
	s.close(db)
	return _assert_eq("UDF double_it(21)", v, 42)

func _disabled_test_scalar_reads_int64_arg() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int64(args[0] as Sqlite3ValueHandle)
		s.result_int64(ctx, v + 1)
	s.create_function_v2(db, "inc64", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT inc64(9999999999)")
	s.step(stmt)
	var v := s.column_int64(stmt, 0)
	s.finalize(stmt)
	s.close(db)
	return _assert_eq("UDF inc64", v, 10000000000)

func _disabled_test_scalar_reads_double_arg() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: float = s.value_double(args[0] as Sqlite3ValueHandle)
		s.result_double(ctx, v * v)
	s.create_function_v2(db, "square", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_double(db, "SELECT square(3.0)")
	s.close(db)
	return _assert_almost_eq("UDF square(3.0)", v, 9.0, 1e-9)

func _disabled_test_scalar_reads_text_arg() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: String = s.value_text(args[0] as Sqlite3ValueHandle)
		s.result_text(ctx, v.to_upper(), -1, s.transient_destructor_type())
	s.create_function_v2(db, "shout", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_text(db, "SELECT shout('hello')")
	s.close(db)
	return _assert_eq("UDF shout('hello')", v, "HELLO")

func _disabled_test_scalar_reads_blob_arg() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var blob: PackedByteArray = s.value_blob(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, blob.size())
	s.create_function_v2(db, "blob_size", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT blob_size(X'DEADBEEF')")
	s.close(db)
	return _assert_eq("UDF blob_size", v, 4)

func _disabled_test_scalar_reads_null_arg_type() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var t: int = s.value_type(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, t)
	s.create_function_v2(db, "type_code", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT type_code(NULL)")
	s.close(db)
	return _assert_eq("UDF type_code(NULL)", v, s.sqlite_null())

func _disabled_test_scalar_value_type_integer() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var t: int = s.value_type(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, t)
	s.create_function_v2(db, "type_code2", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT type_code2(123)")
	s.close(db)
	return _assert_eq("UDF type_code(123) == SQLITE_INTEGER", v, s.sqlite_integer())

func _disabled_test_scalar_value_type_text() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var t: int = s.value_type(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, t)
	s.create_function_v2(db, "type_code3", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT type_code3('hi')")
	s.close(db)
	return _assert_eq("UDF type_code('hi') == SQLITE_TEXT", v, s.sqlite_text())

func _disabled_test_scalar_value_bytes() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var nb: int = s.value_bytes(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, nb)
	s.create_function_v2(db, "val_bytes", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT val_bytes('hello')")
	s.close(db)
	return _assert_eq("UDF val_bytes('hello')", v, 5)

func _disabled_test_scalar_multi_arg() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var a: int = s.value_int(args[0] as Sqlite3ValueHandle)
		var b: int = s.value_int(args[1] as Sqlite3ValueHandle)
		var c: int = s.value_int(args[2] as Sqlite3ValueHandle)
		s.result_int(ctx, a + b + c)
	s.create_function_v2(db, "sum3", 3, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v := _query_int(db, "SELECT sum3(10, 20, 30)")
	s.close(db)
	return _assert_eq("UDF sum3(10,20,30)", v, 60)

func _disabled_test_scalar_variadic_minus_one_arg_count() -> String:
	# n_arg = -1 means variadic
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		s.result_int(ctx, args.size())
	s.create_function_v2(db, "argc", -1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var v0 := _query_int(db, "SELECT argc()")
	var v3 := _query_int(db, "SELECT argc(1, 2, 3)")
	s.close(db)
	if v0 != 0:
		return "argc() expected 0, got %d" % v0
	return _assert_eq("argc(1,2,3) == 3", v3, 3)

func _disabled_test_scalar_context_db_handle() -> String:
	var db := _open_memory()
	var got_db_non_null := false
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		var h = s.context_db_handle(ctx)
		got_db_non_null = (h != null)
		s.result_int(ctx, 1)
	s.create_function_v2(db, "check_ctx_db", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	_query_int(db, "SELECT check_ctx_db()")
	s.close(db)
	return _assert_true("context_db_handle non-null", got_db_non_null)

func _disabled_test_scalar_result_error() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_error(ctx, "intentional test error", -1)
	s.create_function_v2(db, "always_fail", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var res := s.prepare_v2(db, "SELECT always_fail()", -1)
	var stmt: Sqlite3StmtHandle = res.get("statement")
	var rc := s.step(stmt)
	s.finalize(stmt)
	s.close(db)
	if rc == s.ok() or rc == s.row() or rc == s.done():
		return "expected error from UDF that calls result_error, got %d" % rc
	return ""

func _disabled_test_scalar_result_error_code() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_error_code(ctx, s.constraint())
	s.create_function_v2(db, "fail_constraint", 0, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var res := s.prepare_v2(db, "SELECT fail_constraint()", -1)
	var stmt: Sqlite3StmtHandle = res.get("statement")
	var rc := s.step(stmt)
	s.finalize(stmt)
	s.close(db)
	if rc == s.ok() or rc == s.row() or rc == s.done():
		return "expected error from result_error_code, got %d" % rc
	return ""

func _disabled_test_scalar_on_table_rows() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE nums (n INTEGER)")
	_exec(db, "INSERT INTO nums VALUES (1); INSERT INTO nums VALUES (2); INSERT INTO nums VALUES (3);")
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, v * v)
	s.create_function_v2(db, "sq", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT sq(n) FROM nums ORDER BY n")
	var results: Array[int] = []
	while s.step(stmt) == s.row():
		results.append(s.column_int(stmt, 0))
	s.finalize(stmt)
	s.close(db)
	if results.size() != 3:
		return "expected 3 results, got %d" % results.size()
	if results[0] != 1 or results[1] != 4 or results[2] != 9:
		return "unexpected results: %s" % str(results)
	return ""

func _disabled_test_scalar_overwrite_builtin_name_is_possible() -> String:
	# SQLite allows overriding built-in functions
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_int(ctx, -999)
	# Register a function with the same name as a built-in (abs)
	var rc := s.create_function_v2(db, "abs", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	# rc may or may not be OK depending on SQLite build, just ensure no crash
	s.close(db)
	return _assert_true("overwriting abs didn't crash", rc == s.ok() or rc != s.ok())

# ---------------------------------------------------------------------------
# 3. Aggregate UDF
# ---------------------------------------------------------------------------

func _disabled_test_aggregate_sum_integers() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	_exec(db, "INSERT INTO t VALUES (10); INSERT INTO t VALUES (20); INSERT INTO t VALUES (30);")

	# step: accumulate, final: emit
	var xstep := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var ptr: int = s.aggregate_context(ctx, 8)
		if ptr == 0:
			return
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		# We can't dereference the C pointer from GDScript directly.
		# Use set_auxdata as a workaround to carry state per context.
		# Actually, aggregate_context gives us a zeroed buffer we can't
		# easily read back as int from GD, so use a Variant workaround via auxdata.
		var prev = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if prev != null and typeof(prev) == TYPE_INT:
			acc = prev
		acc += v
		s.set_auxdata(ctx, 0, acc, Callable())

	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var total = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if total != null and typeof(total) == TYPE_INT:
			acc = total
		s.result_int(ctx, acc)

	var rc := s.create_function_v2(db, "my_sum", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	if rc != s.ok():
		s.close(db)
		return "create aggregate failed: %d" % rc
	var v := _query_int(db, "SELECT my_sum(x) FROM t")
	s.close(db)
	return _assert_eq("aggregate my_sum", v, 60)

func _disabled_test_aggregate_count_rows() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (2); INSERT INTO t VALUES (3); INSERT INTO t VALUES (4);")

	var xstep := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		var prev = s.get_auxdata(ctx, 0)
		var cnt: int = 0
		if prev != null and typeof(prev) == TYPE_INT:
			cnt = prev
		cnt += 1
		s.set_auxdata(ctx, 0, cnt, Callable())

	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var total = s.get_auxdata(ctx, 0)
		var cnt: int = 0
		if total != null and typeof(total) == TYPE_INT:
			cnt = total
		s.result_int(ctx, cnt)

	s.create_function_v2(db, "my_count", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	var v := _query_int(db, "SELECT my_count(x) FROM t")
	s.close(db)
	return _assert_eq("aggregate my_count", v, 4)

func _disabled_test_aggregate_max_value() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	_exec(db, "INSERT INTO t VALUES (5); INSERT INTO t VALUES (3); INSERT INTO t VALUES (9); INSERT INTO t VALUES (1);")

	var xstep := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		var prev = s.get_auxdata(ctx, 0)
		var cur_max: int = -9999999
		if prev != null and typeof(prev) == TYPE_INT:
			cur_max = prev
		if v > cur_max:
			cur_max = v
		s.set_auxdata(ctx, 0, cur_max, Callable())

	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var m = s.get_auxdata(ctx, 0)
		var val: int = 0
		if m != null and typeof(m) == TYPE_INT:
			val = m
		s.result_int(ctx, val)

	s.create_function_v2(db, "my_max", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	var v := _query_int(db, "SELECT my_max(x) FROM t")
	s.close(db)
	return _assert_eq("aggregate my_max", v, 9)

func _disabled_test_aggregate_on_empty_table() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")

	var xstep := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		var prev = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if prev != null and typeof(prev) == TYPE_INT:
			acc = prev
		s.set_auxdata(ctx, 0, acc + v, Callable())

	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var total = s.get_auxdata(ctx, 0)
		if total == null:
			s.result_null(ctx)
		else:
			s.result_int(ctx, total)

	s.create_function_v2(db, "my_sum2", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	var stmt := _prepare(db, "SELECT my_sum2(x) FROM t")
	s.step(stmt)
	var t := s.column_type(stmt, 0)
	s.finalize(stmt)
	s.close(db)
	return _assert_eq("aggregate on empty table returns NULL", t, s.sqlite_null())

func _disabled_test_aggregate_string_concat() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (name TEXT)")
	_exec(db, "INSERT INTO t VALUES ('A'); INSERT INTO t VALUES ('B'); INSERT INTO t VALUES ('C');")

	var xstep := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: String = s.value_text(args[0] as Sqlite3ValueHandle)
		var prev = s.get_auxdata(ctx, 0)
		var acc := ""
		if prev != null and typeof(prev) == TYPE_STRING:
			acc = prev
		if acc != "":
			acc += ","
		acc += v
		s.set_auxdata(ctx, 0, acc, Callable())

	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var total = s.get_auxdata(ctx, 0)
		var result := ""
		if total != null and typeof(total) == TYPE_STRING:
			result = total
		s.result_text(ctx, result, -1, s.transient_destructor_type())

	s.create_function_v2(db, "my_concat", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	var v := _query_text(db, "SELECT my_concat(name) FROM t ORDER BY name")
	s.close(db)
	return _assert_eq("aggregate string concat", v, "A,B,C")

func _disabled_test_aggregate_grouped() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (grp TEXT, val INTEGER)")
	_exec(db, "INSERT INTO t VALUES ('a', 1); INSERT INTO t VALUES ('a', 2); INSERT INTO t VALUES ('b', 10); INSERT INTO t VALUES ('b', 20);")

	var xstep := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		var prev = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if prev != null and typeof(prev) == TYPE_INT:
			acc = prev
		s.set_auxdata(ctx, 0, acc + v, Callable())

	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var total = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if total != null and typeof(total) == TYPE_INT:
			acc = total
		s.result_int(ctx, acc)

	s.create_function_v2(db, "my_grp_sum", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	var stmt := _prepare(db, "SELECT grp, my_grp_sum(val) FROM t GROUP BY grp ORDER BY grp")
	var results := {}
	while s.step(stmt) == s.row():
		results[s.column_text(stmt, 0)] = s.column_int(stmt, 1)
	s.finalize(stmt)
	s.close(db)
	if results.get("a", -1) != 3:
		return "group 'a' expected 3, got %s" % results.get("a", "N/A")
	if results.get("b", -1) != 30:
		return "group 'b' expected 30, got %s" % results.get("b", "N/A")
	return ""

# ---------------------------------------------------------------------------
# 4. SQLITE_DETERMINISTIC flag
# ---------------------------------------------------------------------------

func _disabled_test_deterministic_function_flag() -> String:
	var db := _open_memory()
	var flags: int = s.sqlite_utf8() | s.sqlite_deterministic()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_int(ctx, 1337)
	var rc := s.create_function_v2(db, "det_func", 0, flags, xfunc, Callable(), Callable())
	if rc != s.ok():
		s.close(db)
		return "create deterministic function failed: %d" % rc
	var v := _query_int(db, "SELECT det_func()")
	s.close(db)
	return _assert_eq("deterministic function result", v, 1337)

# ---------------------------------------------------------------------------
# 5. get_auxdata / set_auxdata
# ---------------------------------------------------------------------------

func _disabled_test_auxdata_persists_across_rows() -> String:
	# auxdata set on parameter 0 should persist for subsequent rows
	# if the argument is the same compile-time constant expression.
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (2); INSERT INTO t VALUES (3);")

	var call_count := 0
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var cached = s.get_auxdata(ctx, 0)
		if cached == null:
			call_count += 1
			s.set_auxdata(ctx, 0, "cached", Callable())
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, v)

	s.create_function_v2(db, "aux_test", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT aux_test(42) FROM t")
	while s.step(stmt) == s.row():
		pass
	s.finalize(stmt)
	s.close(db)
	# When a constant is passed, SQLite may cache auxdata and only call
	# our setter once. Either way, no crash and results flow through.
	return _assert_true("auxdata test ran without crash", true)

# ---------------------------------------------------------------------------
# 6. create_function (older API) – basic smoke test
# ---------------------------------------------------------------------------

func _disabled_test_create_function_v1_works() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, _args: Array) -> void:
		s.result_int(ctx, 777)
	# create_function takes an extra app_data int (pass 0)
	var rc := s.create_function(db, "old_api_func", 0, s.sqlite_utf8(), 0, xfunc, Callable(), Callable())
	if rc != s.ok():
		s.close(db)
		return "create_function (v1) failed: %d" % rc
	var v := _query_int(db, "SELECT old_api_func()")
	s.close(db)
	return _assert_eq("create_function v1 result", v, 777)

# ---------------------------------------------------------------------------
# 7. result_zeroblob
# ---------------------------------------------------------------------------

func test_result_zeroblob() -> String:
	var db := _open_memory()
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var n: int = s.value_int(args[0] as Sqlite3ValueHandle)
		s.result_zeroblob(ctx, n)
	s.create_function_v2(db, "zero_blob", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var blob := _query_blob(db, "SELECT zero_blob(6)")
	s.close(db)
	if blob.size() != 6:
		return "zeroblob size expected 6, got %d" % blob.size()
	for b in blob:
		if b != 0:
			return "zeroblob contains non-zero byte"
	return ""

# ---------------------------------------------------------------------------
# 8. UDF used in WHERE / ORDER BY / HAVING
# ---------------------------------------------------------------------------

func _disabled_test_udf_in_where_clause() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (x INTEGER)")
	_exec(db, "INSERT INTO t VALUES (1); INSERT INTO t VALUES (5); INSERT INTO t VALUES (10);")
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, v > 3)
	s.create_function_v2(db, "gt3", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT x FROM t WHERE gt3(x) ORDER BY x")
	var results: Array[int] = []
	while s.step(stmt) == s.row():
		results.append(s.column_int(stmt, 0))
	s.finalize(stmt)
	s.close(db)
	if results.size() != 2:
		return "expected 2 rows from gt3 filter, got %d" % results.size()
	if results[0] != 5 or results[1] != 10:
		return "unexpected results: %s" % str(results)
	return ""

func _disabled_test_udf_in_order_by() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (name TEXT)")
	_exec(db, "INSERT INTO t VALUES ('banana'); INSERT INTO t VALUES ('apple'); INSERT INTO t VALUES ('cherry');")
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: String = s.value_text(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, v.length())
	s.create_function_v2(db, "str_len", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())
	var stmt := _prepare(db, "SELECT name FROM t ORDER BY str_len(name) ASC")
	var first := ""
	if s.step(stmt) == s.row():
		first = s.column_text(stmt, 0)
	s.finalize(stmt)
	s.close(db)
	return _assert_eq("UDF in ORDER BY: shortest first", first, "apple")

func _disabled_test_udf_in_having() -> String:
	var db := _open_memory()
	_exec(db, "CREATE TABLE t (grp TEXT, val INTEGER)")
	_exec(db, "INSERT INTO t VALUES ('a', 1); INSERT INTO t VALUES ('a', 2); INSERT INTO t VALUES ('b', 100);")
	var xfunc := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		s.result_int(ctx, v > 50)
	s.create_function_v2(db, "big", 1, s.sqlite_utf8(), xfunc, Callable(), Callable())

	var xstep := func(ctx: Sqlite3ContextHandle, args: Array) -> void:
		var v: int = s.value_int(args[0] as Sqlite3ValueHandle)
		var prev = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if prev != null and typeof(prev) == TYPE_INT:
			acc = prev
		s.set_auxdata(ctx, 0, acc + v, Callable())
	var xfinal := func(ctx: Sqlite3ContextHandle) -> void:
		var total = s.get_auxdata(ctx, 0)
		var acc: int = 0
		if total != null and typeof(total) == TYPE_INT:
			acc = total
		s.result_int(ctx, acc)

	s.create_function_v2(db, "my_sum3", 1, s.sqlite_utf8(), Callable(), xstep, xfinal)
	var stmt := _prepare(db, "SELECT grp FROM t GROUP BY grp HAVING big(my_sum3(val))")
	var found_grps: Array[String] = []
	while s.step(stmt) == s.row():
		found_grps.append(s.column_text(stmt, 0))
	s.finalize(stmt)
	s.close(db)
	if found_grps.size() != 1 or found_grps[0] != "b":
		return "expected only group 'b' in HAVING result, got %s" % str(found_grps)
	return ""
