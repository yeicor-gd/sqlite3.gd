class_name TestAutowrapper

static func run():
	var wrapper := Sqlite3Wrapper.new()
	for i in range(20):
		print(wrapper.compileoption_get(i))
	print("---")
	print(wrapper.libversion())

	var db := Sqlite3Handle.new()
	wrapper.open(":memory:", db)
	print("Valid: ", db.is_valid())

	var ret := wrapper.exec(db, "DROP TABLE IF EXISTS test;", func(): pass)
	print(ret)
	ret = wrapper.exec(db, "CREATE TABLE test(a int);", func(): pass)
	print(ret)
	ret = wrapper.exec(db, "INSERT INTO test VALUES (1);", func(): pass)
	print(ret)
	ret = wrapper.exec(db, "INSERT INTO test VALUES (2);", func(): pass)
	print(ret)
	ret = wrapper.exec(db, "INSERT INTO test VALUES (3);", func(): pass)
	print(ret)
	ret = wrapper.exec(db, "SELECT * FROM test;", func(values, names):
		print("Got: ", values, names)
		return 0)
	print(ret)

	ret = wrapper.prepare_v2(db, "SELECT * FROM test;", 99999)
	var stmt: Sqlite3StmtHandle = ret["statement"]
	print(ret)
	for i in range(3):
		var ret2 := wrapper.step(stmt)
		print(ret2, " - ", wrapper.errstr(ret2))
		var value := wrapper.column_int(stmt, 0)
		print("Got: ", value)
	var ret3 := wrapper.step(stmt)
	print(ret3, " - ", wrapper.errstr(ret3))

	wrapper.close(db)

	print("Autowrapper test completed.")
