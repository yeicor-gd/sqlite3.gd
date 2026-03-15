extends RefCounted

func run_test(db: SQLite3Database, log_func: Callable):
	log_func.call("Starting Generated Bindings Test", "TEST_START")

	# Run new test for SQLite3Version binding
	var sqlv = SQLite3Version.new()
	assert(sqlv.get_version() == "3.51.2")
	assert(sqlv.get_version_number() == 3051002)
	assert(sqlv.libversion() == "3.51.2")
	assert(sqlv.libversion_number() == 3051002)
	assert(sqlv.sourceid() == sqlv.get_source_id())

	# Add more tests here or in helper functions

	# Test new SQLite3 constant bindings
	assert(SQLite3.get_SQLITE_ROW() == 100)
	assert(SQLite3.get_SQLITE_DONE() == 101)
	assert(SQLite3.get_SQLITE_ERROR_MISSING_COLLSEQ() == (SQLite3.get_SQLITE_ERROR() | (1<<8)))
	assert(SQLite3.get_SQLITE_ERROR_RETRY() == (SQLite3.get_SQLITE_ERROR() | (2<<8)))
	# IOERR tests use their real values
	assert(SQLite3.get_SQLITE_IOERR_READ() == (SQLite3.get_SQLITE_IOERR() | (1<<8)))
	assert(SQLite3.get_SQLITE_IOERR_SHORT_READ() == (SQLite3.get_SQLITE_IOERR() | (2<<8)))
	# API method signatures presence
	assert(typeof(SQLite3.sqlite3_close) == TYPE_FUNCTION)
	assert(typeof(SQLite3.sqlite3_exec) == TYPE_FUNCTION)

	assert(SQLite3.get_SQLITE_NOMEM() == 7)
	assert(SQLite3.get_SQLITE_READONLY() == 8)
	assert(SQLite3.get_SQLITE_INTERRUPT() == 9)

	assert(SQLite3.get_SQLITE_IOERR() == 10)
	assert(SQLite3.get_SQLITE_CORRUPT() == 11)
	assert(SQLite3.get_SQLITE_NOTFOUND() == 12)
	assert(SQLite3.get_SQLITE_FULL() == 13)
	assert(SQLite3.get_SQLITE_CANTOPEN() == 14)
	assert(SQLite3.get_SQLITE_PROTOCOL() == 15)
	assert(SQLite3.get_SQLITE_EMPTY() == 16)
	assert(SQLite3.get_SQLITE_SCHEMA() == 17)
	assert(SQLite3.get_SQLITE_TOOBIG() == 18)
	assert(SQLite3.get_SQLITE_CONSTRAINT() == 19)
	assert(SQLite3.get_SQLITE_MISMATCH() == 20)
	assert(SQLite3.get_SQLITE_MISUSE() == 21)
	assert(SQLite3.get_SQLITE_NOLFS() == 22)
	assert(SQLite3.get_SQLITE_AUTH() == 23)
	assert(SQLite3.get_SQLITE_FORMAT() == 24)
	assert(SQLite3.get_SQLITE_RANGE() == 25)
	assert(SQLite3.get_SQLITE_NOTADB() == 26)
	assert(SQLite3.get_SQLITE_NOTICE() == 27)
	assert(SQLite3.get_SQLITE_WARNING() == 28)

	log_func.call("Generated Bindings Test completed", "TEST_END")
