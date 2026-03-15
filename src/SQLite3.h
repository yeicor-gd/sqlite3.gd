#ifndef SQLITE3_WRAPPER_H
#define SQLITE3_WRAPPER_H

#include <godot_cpp/classes/object.hpp>
#include <sqlite3.h>

namespace godot {

class SQLite3 : public Object {
    GDCLASS(SQLite3, Object);
protected:
    static void _bind_methods();
    static void _bind_methods_constants();
    static void _bind_methods_functions();
public:
    // --- Constants (as static getters)
    static int get_SQLITE_OK();
    static int get_SQLITE_ERROR();
    static int get_SQLITE_INTERNAL();
    static int get_SQLITE_PERM();
    static int get_SQLITE_ABORT();
    static int get_SQLITE_BUSY();
    static int get_SQLITE_LOCKED();
    static int get_SQLITE_NOMEM();
    static int get_SQLITE_IOERR();
    static int get_SQLITE_CORRUPT();
    static int get_SQLITE_NOTFOUND();
    static int get_SQLITE_FULL();
    static int get_SQLITE_CANTOPEN();
    static int get_SQLITE_PROTOCOL();
    static int get_SQLITE_EMPTY();
    static int get_SQLITE_SCHEMA();
    static int get_SQLITE_TOOBIG();
    static int get_SQLITE_CONSTRAINT();
    static int get_SQLITE_MISMATCH();
    static int get_SQLITE_MISUSE();
    static int get_SQLITE_NOLFS();
    static int get_SQLITE_AUTH();
    static int get_SQLITE_FORMAT();
    static int get_SQLITE_RANGE();
    static int get_SQLITE_NOTADB();
    static int get_SQLITE_NOTICE();
    static int get_SQLITE_WARNING();

    static int get_SQLITE_READONLY();
    static int get_SQLITE_INTERRUPT();
    static int get_SQLITE_ROW();
    static int get_SQLITE_DONE();
    static int get_SQLITE_ERROR_MISSING_COLLSEQ();
    static int get_SQLITE_ERROR_RETRY();
    static int get_SQLITE_IOERR_READ();
    static int get_SQLITE_IOERR_SHORT_READ();
    // ... (Add all constants here)

    // --- API Functions ---
    static int sqlite3_libversion_number();
    static String sqlite3_libversion();
    static String sqlite3_sourceid();
    static int sqlite3_threadsafe();
    static int sqlite3_close(int64_t db_ptr);
    static int sqlite3_close_v2(int64_t db_ptr);
    static int sqlite3_exec(int64_t db_ptr, String sql);
    // ... (Add all API functions here)
};

}

#endif // SQLITE3_WRAPPER_H
