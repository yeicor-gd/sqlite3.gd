class_name TestAutowrapper

static func run():
	var wrapper := SqliteWrapper.new()
	for i in range(20):
		print(wrapper.compileoption_get(i))
	print("---")
	print(wrapper.version())
	
	var db := Sqlite3Handle.new()
	wrapper.open(":memory:", db)
	print("Valid: ", db.is_valid())
	
	var ret := wrapper.exec(db, "DROP TABLE IF EXISTS test;", func(): pass)
	print(ret, " - ", wrapper.errstr(ret))
	ret = wrapper.exec(db, "CREATE TABLE test(a int);", func(): pass)
	print(ret, " - ", wrapper.errstr(ret))
	ret = wrapper.exec(db, "INSERT INTO test VALUES (1);", func(): pass)
	print(ret, " - ", wrapper.errstr(ret))
	ret = wrapper.exec(db, "INSERT INTO test VALUES (2);", func(): pass)
	print(ret, " - ", wrapper.errstr(ret))
	ret = wrapper.exec(db, "INSERT INTO test VALUES (3);", func(): pass)
	print(ret, " - ", wrapper.errstr(ret))
	ret = wrapper.exec(db, "SELECT * FROM test;", func(values, names): 
		print("Got: ", values, names)
		return 0)
	print(ret, " - ", wrapper.errstr(ret))
	
	var stmt := Sqlite3StmtHandle.new()
	ret = wrapper.prepare_v2(db, "SELECT * FROM test;", 99999, stmt, "")
	print(ret, " - ", wrapper.errstr(ret))
	for i in range(3):
		ret = wrapper.step(stmt)
		print(ret, " - ", wrapper.errstr(ret))
		var value := wrapper.column_int(stmt, 0)
		print("Got: ", value)
	ret = wrapper.step(stmt)
	print(ret, " - ", wrapper.errstr(ret))
	
	wrapper.close(db)
