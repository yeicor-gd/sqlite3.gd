#ifndef SQLITE3WRAPPER_H
#define SQLITE3WRAPPER_H

#include <godot_cpp/classes/object.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/classes/ref.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/variant/callable.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/variant/array.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/variant/utility_functions.hpp> // NOLINT(misc-include-cleaner)
#include <cstdint> // NOLINT(misc-include-cleaner)
#include "sqlite3.h" // NOLINT(misc-include-cleaner)

using namespace godot;

class Sqlite3Handle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3Handle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3Handle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3Handle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3Handle::is_valid);
    }
public:
    sqlite3* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3FileHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3FileHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3FileHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3FileHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3FileHandle::is_valid);
    }
public:
    sqlite3_file* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_file*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3IoMethodsHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3IoMethodsHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3IoMethodsHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3IoMethodsHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3IoMethodsHandle::is_valid);
    }
public:
    sqlite3_io_methods* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_io_methods*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3MutexHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3MutexHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3MutexHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3MutexHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3MutexHandle::is_valid);
    }
public:
    sqlite3_mutex* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_mutex*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ApiRoutinesHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3ApiRoutinesHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3ApiRoutinesHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3ApiRoutinesHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3ApiRoutinesHandle::is_valid);
    }
public:
    sqlite3_api_routines* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_api_routines*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3VfsHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3VfsHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3VfsHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3VfsHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3VfsHandle::is_valid);
    }
public:
    sqlite3_vfs* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_vfs*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3MemMethodsHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3MemMethodsHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3MemMethodsHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3MemMethodsHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3MemMethodsHandle::is_valid);
    }
public:
    sqlite3_mem_methods* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_mem_methods*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3FilenameHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3FilenameHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3FilenameHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3FilenameHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3FilenameHandle::is_valid);
    }
public:
    sqlite3_filename* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_filename*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3StmtHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3StmtHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3StmtHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3StmtHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3StmtHandle::is_valid);
    }
public:
    sqlite3_stmt* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_stmt*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ContextHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3ContextHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3ContextHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3ContextHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3ContextHandle::is_valid);
    }
public:
    sqlite3_context* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_context*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ValueHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3ValueHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3ValueHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3ValueHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3ValueHandle::is_valid);
    }
public:
    sqlite3_value* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_value*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3VtabHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3VtabHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3VtabHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3VtabHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3VtabHandle::is_valid);
    }
public:
    sqlite3_vtab* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_vtab*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3IndexInfoHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3IndexInfoHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3IndexInfoHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3IndexInfoHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3IndexInfoHandle::is_valid);
    }
public:
    sqlite3_index_info* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_index_info*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3VtabCursorHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3VtabCursorHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3VtabCursorHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3VtabCursorHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3VtabCursorHandle::is_valid);
    }
public:
    sqlite3_vtab_cursor* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_vtab_cursor*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ModuleHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3ModuleHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3ModuleHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3ModuleHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3ModuleHandle::is_valid);
    }
public:
    sqlite3_module* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_module*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3BlobHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3BlobHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3BlobHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3BlobHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3BlobHandle::is_valid);
    }
public:
    sqlite3_blob* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_blob*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3StrHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3StrHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3StrHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3StrHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3StrHandle::is_valid);
    }
public:
    sqlite3_str* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_str*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcacheHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3PcacheHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3PcacheHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3PcacheHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3PcacheHandle::is_valid);
    }
public:
    sqlite3_pcache* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcachePageHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3PcachePageHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3PcachePageHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3PcachePageHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3PcachePageHandle::is_valid);
    }
public:
    sqlite3_pcache_page* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache_page*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcacheMethods2Handle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3PcacheMethods2Handle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3PcacheMethods2Handle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3PcacheMethods2Handle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3PcacheMethods2Handle::is_valid);
    }
public:
    sqlite3_pcache_methods2* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache_methods2*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3BackupHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3BackupHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3BackupHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3BackupHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3BackupHandle::is_valid);
    }
public:
    sqlite3_backup* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_backup*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3SnapshotHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3SnapshotHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3SnapshotHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3SnapshotHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3SnapshotHandle::is_valid);
    }
public:
    sqlite3_snapshot* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_snapshot*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3RtreeGeometryHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3RtreeGeometryHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3RtreeGeometryHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3RtreeGeometryHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3RtreeGeometryHandle::is_valid);
    }
public:
    sqlite3_rtree_geometry* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_rtree_geometry*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3RtreeQueryInfoHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3RtreeQueryInfoHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3RtreeQueryInfoHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3RtreeQueryInfoHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3RtreeQueryInfoHandle::is_valid);
    }
public:
    sqlite3_rtree_query_info* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_rtree_query_info*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3SessionHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3SessionHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3SessionHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3SessionHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3SessionHandle::is_valid);
    }
public:
    sqlite3_session* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_session*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ChangesetIterHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3ChangesetIterHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3ChangesetIterHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3ChangesetIterHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3ChangesetIterHandle::is_valid);
    }
public:
    sqlite3_changeset_iter* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_changeset_iter*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ChangegroupHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3ChangegroupHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3ChangegroupHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3ChangegroupHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3ChangegroupHandle::is_valid);
    }
public:
    sqlite3_changegroup* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_changegroup*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3RebaserHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3RebaserHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3RebaserHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3RebaserHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3RebaserHandle::is_valid);
    }
public:
    sqlite3_rebaser* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_rebaser*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5extensionapiHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5extensionapiHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5extensionapiHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5extensionapiHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5extensionapiHandle::is_valid);
    }
public:
    Fts5ExtensionApi* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5ExtensionApi*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5contextHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5contextHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5contextHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5contextHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5contextHandle::is_valid);
    }
public:
    Fts5Context* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5Context*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5phraseiterHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5phraseiterHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5phraseiterHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5phraseiterHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5phraseiterHandle::is_valid);
    }
public:
    Fts5PhraseIter* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5PhraseIter*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5TokenizerV2Handle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5TokenizerV2Handle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5TokenizerV2Handle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5TokenizerV2Handle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5TokenizerV2Handle::is_valid);
    }
public:
    fts5_tokenizer_v2* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<fts5_tokenizer_v2*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5ApiHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5ApiHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5ApiHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5ApiHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5ApiHandle::is_valid);
    }
public:
    fts5_api* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<fts5_api*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3MutexMethodsHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3MutexMethodsHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3MutexMethodsHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3MutexMethodsHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3MutexMethodsHandle::is_valid);
    }
public:
    sqlite3_mutex_methods* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_mutex_methods*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcacheMethodsHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Sqlite3PcacheMethodsHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Sqlite3PcacheMethodsHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Sqlite3PcacheMethodsHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Sqlite3PcacheMethodsHandle::is_valid);
    }
public:
    sqlite3_pcache_methods* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache_methods*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5TokenizerHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5TokenizerHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5TokenizerHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5TokenizerHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5TokenizerHandle::is_valid);
    }
public:
    fts5_tokenizer* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<fts5_tokenizer*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Fts5tokenizerHandle : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions)
    GDCLASS(Fts5tokenizerHandle, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &Fts5tokenizerHandle::set_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &Fts5tokenizerHandle::get_handle);
        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &Fts5tokenizerHandle::is_valid);
    }
public:
    Fts5Tokenizer* handle = nullptr; // NOLINT
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5Tokenizer*>(static_cast<uintptr_t>(_handle)); } // NOLINT
    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT
    [[nodiscard]] bool is_valid() const { return handle != nullptr; }
};

class Sqlite3Wrapper : public godot::RefCounted { // NOLINT(cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
    GDCLASS(Sqlite3Wrapper, godot::RefCounted) // NOLINT
protected:
    static void _bind_methods();
public:
    String version_string(void); // NOLINT(readability-convert-member-functions-to-static)
    int version_number(void); // NOLINT(readability-convert-member-functions-to-static)
    String source_id(void); // NOLINT(readability-convert-member-functions-to-static)
    String scm_branch(void); // NOLINT(readability-convert-member-functions-to-static)
    String scm_tags(void); // NOLINT(readability-convert-member-functions-to-static)
    String scm_datetime(void); // NOLINT(readability-convert-member-functions-to-static)
    String libversion(void); // NOLINT(readability-convert-member-functions-to-static)
    String sourceid(void); // NOLINT(readability-convert-member-functions-to-static)
    int libversion_number(void); // NOLINT(readability-convert-member-functions-to-static)
#ifndef SQLITE_OMIT_COMPILEOPTION_DIAGS
    int compileoption_used(const String& option_name); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_COMPILEOPTION_DIAGS
    String compileoption_get(int n); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int threadsafe(void); // NOLINT(readability-convert-member-functions-to-static)
    int close(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int ok(void); // NOLINT(readability-convert-member-functions-to-static)
    int error(void); // NOLINT(readability-convert-member-functions-to-static)
    int internal(void); // NOLINT(readability-convert-member-functions-to-static)
    int perm(void); // NOLINT(readability-convert-member-functions-to-static)
    int abort(void); // NOLINT(readability-convert-member-functions-to-static)
    int busy(void); // NOLINT(readability-convert-member-functions-to-static)
    int locked(void); // NOLINT(readability-convert-member-functions-to-static)
    int nomem(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly(void); // NOLINT(readability-convert-member-functions-to-static)
    int interrupt(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr(void); // NOLINT(readability-convert-member-functions-to-static)
    int corrupt(void); // NOLINT(readability-convert-member-functions-to-static)
    int notfound(void); // NOLINT(readability-convert-member-functions-to-static)
    int full(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen(void); // NOLINT(readability-convert-member-functions-to-static)
    int protocol(void); // NOLINT(readability-convert-member-functions-to-static)
    int empty(void); // NOLINT(readability-convert-member-functions-to-static)
    int schema(void); // NOLINT(readability-convert-member-functions-to-static)
    int toobig(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint(void); // NOLINT(readability-convert-member-functions-to-static)
    int mismatch(void); // NOLINT(readability-convert-member-functions-to-static)
    int misuse(void); // NOLINT(readability-convert-member-functions-to-static)
    int nolfs(void); // NOLINT(readability-convert-member-functions-to-static)
    int auth(void); // NOLINT(readability-convert-member-functions-to-static)
    int format(void); // NOLINT(readability-convert-member-functions-to-static)
    int range(void); // NOLINT(readability-convert-member-functions-to-static)
    int notadb(void); // NOLINT(readability-convert-member-functions-to-static)
    int notice(void); // NOLINT(readability-convert-member-functions-to-static)
    int warning(void); // NOLINT(readability-convert-member-functions-to-static)
    int row(void); // NOLINT(readability-convert-member-functions-to-static)
    int done(void); // NOLINT(readability-convert-member-functions-to-static)
    int error_missing_collseq(void); // NOLINT(readability-convert-member-functions-to-static)
    int error_retry(void); // NOLINT(readability-convert-member-functions-to-static)
    int error_snapshot(void); // NOLINT(readability-convert-member-functions-to-static)
    int error_reservesize(void); // NOLINT(readability-convert-member-functions-to-static)
    int error_key(void); // NOLINT(readability-convert-member-functions-to-static)
    int error_unable(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_read(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_short_read(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_fsync(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_dir_fsync(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_truncate(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_fstat(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_unlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_rdlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_delete(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_blocked(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_nomem(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_access(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_checkreservedlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_lock(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_close(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_dir_close(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_shmopen(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_shmsize(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_shmlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_shmmap(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_seek(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_delete_noent(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_mmap(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_gettemppath(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_convpath(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_vnode(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_auth(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_begin_atomic(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_commit_atomic(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_rollback_atomic(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_data(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_corruptfs(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_in_page(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_badkey(void); // NOLINT(readability-convert-member-functions-to-static)
    int ioerr_codec(void); // NOLINT(readability-convert-member-functions-to-static)
    int locked_sharedcache(void); // NOLINT(readability-convert-member-functions-to-static)
    int locked_vtab(void); // NOLINT(readability-convert-member-functions-to-static)
    int busy_recovery(void); // NOLINT(readability-convert-member-functions-to-static)
    int busy_snapshot(void); // NOLINT(readability-convert-member-functions-to-static)
    int busy_timeout(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen_notempdir(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen_isdir(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen_fullpath(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen_convpath(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen_dirtywal(void); // NOLINT(readability-convert-member-functions-to-static)
    int cantopen_symlink(void); // NOLINT(readability-convert-member-functions-to-static)
    int corrupt_vtab(void); // NOLINT(readability-convert-member-functions-to-static)
    int corrupt_sequence(void); // NOLINT(readability-convert-member-functions-to-static)
    int corrupt_index(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly_recovery(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly_cantlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly_rollback(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly_dbmoved(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly_cantinit(void); // NOLINT(readability-convert-member-functions-to-static)
    int readonly_directory(void); // NOLINT(readability-convert-member-functions-to-static)
    int abort_rollback(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_check(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_commithook(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_foreignkey(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_function(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_notnull(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_primarykey(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_trigger(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_unique(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_vtab(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_rowid(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_pinned(void); // NOLINT(readability-convert-member-functions-to-static)
    int constraint_datatype(void); // NOLINT(readability-convert-member-functions-to-static)
    int notice_recover_wal(void); // NOLINT(readability-convert-member-functions-to-static)
    int notice_recover_rollback(void); // NOLINT(readability-convert-member-functions-to-static)
    int notice_rbu(void); // NOLINT(readability-convert-member-functions-to-static)
    int warning_autoindex(void); // NOLINT(readability-convert-member-functions-to-static)
    int auth_user(void); // NOLINT(readability-convert-member-functions-to-static)
    int ok_load_permanently(void); // NOLINT(readability-convert-member-functions-to-static)
    int ok_symlink(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_readonly(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_readwrite(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_create(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_deleteonclose(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_exclusive(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_autoproxy(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_uri(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_memory(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_main_db(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_temp_db(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_transient_db(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_main_journal(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_temp_journal(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_subjournal(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_super_journal(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_nomutex(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_fullmutex(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_sharedcache(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_privatecache(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_wal(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_nofollow(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_exrescode(void); // NOLINT(readability-convert-member-functions-to-static)
    int open_master_journal(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic512(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic1k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic2k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic4k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic8k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic16k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic32k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_atomic64k(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_safe_append(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_sequential(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_undeletable_when_open(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_powersafe_overwrite(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_immutable(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_batch_atomic(void); // NOLINT(readability-convert-member-functions-to-static)
    int iocap_subpage_read(void); // NOLINT(readability-convert-member-functions-to-static)
    int lock_none(void); // NOLINT(readability-convert-member-functions-to-static)
    int lock_shared(void); // NOLINT(readability-convert-member-functions-to-static)
    int lock_reserved(void); // NOLINT(readability-convert-member-functions-to-static)
    int lock_pending(void); // NOLINT(readability-convert-member-functions-to-static)
    int lock_exclusive(void); // NOLINT(readability-convert-member-functions-to-static)
    int sync_normal(void); // NOLINT(readability-convert-member-functions-to-static)
    int sync_full(void); // NOLINT(readability-convert-member-functions-to-static)
    int sync_dataonly(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_lockstate(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_get_lockproxyfile(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_set_lockproxyfile(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_last_errno(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_size_hint(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_chunk_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_file_pointer(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_sync_omitted(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_win32_av_retry(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_persist_wal(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_overwrite(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_vfsname(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_powersafe_overwrite(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_pragma(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_busyhandler(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_tempfilename(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_mmap_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_trace(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_has_moved(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_sync(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_commit_phasetwo(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_win32_set_handle(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_wal_block(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_zipvfs(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_rbu(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_vfs_pointer(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_journal_pointer(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_win32_get_handle(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_pdb(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_begin_atomic_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_commit_atomic_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_rollback_atomic_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_lock_timeout(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_data_version(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_size_limit(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_ckpt_done(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_reserve_bytes(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_ckpt_start(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_external_reader(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_cksm_file(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_reset_cache(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_null_io(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_block_on_connect(void); // NOLINT(readability-convert-member-functions-to-static)
    int fcntl_filestat(void); // NOLINT(readability-convert-member-functions-to-static)
    int get_lockproxyfile(void); // NOLINT(readability-convert-member-functions-to-static)
    int set_lockproxyfile(void); // NOLINT(readability-convert-member-functions-to-static)
    int last_errno(void); // NOLINT(readability-convert-member-functions-to-static)
    int access_exists(void); // NOLINT(readability-convert-member-functions-to-static)
    int access_readwrite(void); // NOLINT(readability-convert-member-functions-to-static)
    int access_read(void); // NOLINT(readability-convert-member-functions-to-static)
    int shm_unlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int shm_lock(void); // NOLINT(readability-convert-member-functions-to-static)
    int shm_shared(void); // NOLINT(readability-convert-member-functions-to-static)
    int shm_exclusive(void); // NOLINT(readability-convert-member-functions-to-static)
    int shm_nlock(void); // NOLINT(readability-convert-member-functions-to-static)
    int initialize(void); // NOLINT(readability-convert-member-functions-to-static)
    int shutdown(void); // NOLINT(readability-convert-member-functions-to-static)
    int os_init(void); // NOLINT(readability-convert-member-functions-to-static)
    int os_end(void); // NOLINT(readability-convert-member-functions-to-static)
    int config(int64_t option); // NOLINT(readability-convert-member-functions-to-static)
    int db_config(const Ref<Sqlite3Handle>& db, int op, const Array& args); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_singlethread(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_multithread(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_serialized(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_malloc(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_getmalloc(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_scratch(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_pagecache(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_heap(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_memstatus(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_mutex(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_getmutex(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_lookaside(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_pcache(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_getpcache(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_log(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_uri(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_pcache2(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_getpcache2(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_covering_index_scan(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_sqllog(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_mmap_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_win32_heapsize(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_pcache_hdrsz(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_pmasz(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_stmtjrnl_spill(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_small_malloc(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_sorterref_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_memdb_maxsize(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_config_rowid_in_view(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_maindbname(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_lookaside(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_enable_fkey(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_enable_trigger(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_enable_fts3_tokenizer(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_enable_load_extension(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_no_ckpt_on_close(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_enable_qpsg(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_trigger_eqp(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_reset_database(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_defensive(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_writable_schema(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_legacy_alter_table(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbconfig_dqs_dml(void); // NOLINT(readability-convert-member-functions-to-static)
    int dqs_ddl(void); // NOLINT(readability-convert-member-functions-to-static)
    int enable_view(void); // NOLINT(readability-convert-member-functions-to-static)
    int legacy_file_format(void); // NOLINT(readability-convert-member-functions-to-static)
    int trusted_schema(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmt_scanstatus(void); // NOLINT(readability-convert-member-functions-to-static)
    int reverse_scanorder(void); // NOLINT(readability-convert-member-functions-to-static)
    int enable_attach_create(void); // NOLINT(readability-convert-member-functions-to-static)
    int enable_attach_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int enable_comments(void); // NOLINT(readability-convert-member-functions-to-static)
    int fp_digits(void); // NOLINT(readability-convert-member-functions-to-static)
    int max(void); // NOLINT(readability-convert-member-functions-to-static)
    int extended_result_codes(const Ref<Sqlite3Handle>& db, int onoff); // NOLINT(readability-convert-member-functions-to-static)
    int64_t changes64(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int total_changes64(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int is_interrupted(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int complete16(const String& sql); // NOLINT(readability-convert-member-functions-to-static)
    int busy_handler(const Ref<Sqlite3Handle>& db, Callable handler); // NOLINT(readability-convert-member-functions-to-static)
    void free_table(int64_t result_ptr); // NOLINT(readability-convert-member-functions-to-static)
    String mprintf(const String& format); // NOLINT(readability-convert-member-functions-to-static)
    String vmprintf(const String& format); // NOLINT(readability-convert-member-functions-to-static)
    int64_t malloc(int64_t n_bytes); // NOLINT(readability-convert-member-functions-to-static)
    int64_t malloc64(int64_t size); // NOLINT(readability-convert-member-functions-to-static)
    int64_t realloc(int64_t ptr, int size); // NOLINT(readability-convert-member-functions-to-static)
    int64_t realloc64(int64_t ptr, int64_t new_size); // NOLINT(readability-convert-member-functions-to-static)
    int64_t msize(int64_t ptr); // NOLINT(readability-convert-member-functions-to-static)
    int memory_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int64_t memory_highwater(int64_t reset_flag); // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray randomness(int64_t n); // NOLINT(readability-convert-member-functions-to-static)
    int set_authorizer(const Ref<Sqlite3Handle>& db, Callable x_auth); // NOLINT(readability-convert-member-functions-to-static)
    int64_t trace(const Ref<Sqlite3Handle>& db, Callable trace_callback); // NOLINT(readability-convert-member-functions-to-static)
    int trace_v2(const Ref<Sqlite3Handle>& db, int64_t mask, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
    String uri_parameter(const String& z, const String& z_param); // NOLINT(readability-convert-member-functions-to-static)
    int uri_boolean(const String& z, const String& z_param, int b_default); // NOLINT(readability-convert-member-functions-to-static)
    int64_t uri_int64(const String& filename, const String& param, int64_t default_value); // NOLINT(readability-convert-member-functions-to-static)
    String uri_key(const String& z, int index); // NOLINT(readability-convert-member-functions-to-static)
    String filename_database(const String& filename); // NOLINT(readability-convert-member-functions-to-static)
    String filename_journal(const String& filename); // NOLINT(readability-convert-member-functions-to-static)
    String filename_wal(const String& filename); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3FileHandle> database_file_object(const String& filename); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3FilenameHandle> create_filename(const String& database, const String& journal, const String& wal, int64_t n_param, PackedStringArray az_param); // NOLINT(readability-convert-member-functions-to-static)
    void free_filename(int64_t filename_ptr); // NOLINT(readability-convert-member-functions-to-static)
    int errcode(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int extended_errcode(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    String errmsg(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    String errstr(int error_code); // NOLINT(readability-convert-member-functions-to-static)
    int limit(const Ref<Sqlite3Handle>& db, int id, int new_value); // NOLINT(readability-convert-member-functions-to-static)
    String expanded_sql(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int bind_blob(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const PackedByteArray& data); // NOLINT(readability-convert-member-functions-to-static)
    int bind_blob64(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const PackedByteArray& blob, int64_t destructor); // NOLINT(readability-convert-member-functions-to-static)
    int bind_int64(const Ref<Sqlite3StmtHandle>& stmt, int index, int value); // NOLINT(readability-convert-member-functions-to-static)
    int bind_zeroblob(const Ref<Sqlite3StmtHandle>& stmt, int index, int n); // NOLINT(readability-convert-member-functions-to-static)
    String column_name16(const Ref<Sqlite3StmtHandle>& stmt, int n); // NOLINT(readability-convert-member-functions-to-static)
    String column_database_name16(const Ref<Sqlite3StmtHandle>& stmt, int col); // NOLINT(readability-convert-member-functions-to-static)
    String column_table_name(const Ref<Sqlite3StmtHandle>& stmt, int column); // NOLINT(readability-convert-member-functions-to-static)
    String column_decltype16(const Ref<Sqlite3StmtHandle>& stmt, int col); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_text(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite3_text(void); // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray column_blob(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    double column_double(const Ref<Sqlite3StmtHandle>& stmt, int64_t i_col); // NOLINT(readability-convert-member-functions-to-static)
    int column_int(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    int64_t column_int64(const Ref<Sqlite3StmtHandle>& stmt, int64_t i_col); // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray value_blob(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    double value_double(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_int(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int64_t value_int64(const Ref<Sqlite3ValueHandle>& db_value); // NOLINT(readability-convert-member-functions-to-static)
    int value_pointer(const Ref<Sqlite3ValueHandle>& value, const String& type_name); // NOLINT(readability-convert-member-functions-to-static)
    int value_bytes(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    void value_free(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    void set_auxdata(const Ref<Sqlite3ContextHandle>& context, int n, const Variant& auxdata, Callable destructor); // NOLINT(readability-convert-member-functions-to-static)
    int set_clientdata(const Ref<Sqlite3Handle>& db, const String& key, int64_t client_data_ptr, int64_t cleanup_callback_ptr); // NOLINT(readability-convert-member-functions-to-static)
    int64_t static_destructor_type(void); // NOLINT(readability-convert-member-functions-to-static)
    int64_t transient_destructor_type(void); // NOLINT(readability-convert-member-functions-to-static)
    void result_blob(const Ref<Sqlite3ContextHandle>& context, const PackedByteArray& data, bool is_transient); // NOLINT(readability-convert-member-functions-to-static)
    void result_blob64(const Ref<Sqlite3ContextHandle>& ctx, const PackedByteArray& blob, int64_t destructor); // NOLINT(readability-convert-member-functions-to-static)
    void result_double(const Ref<Sqlite3ContextHandle>& ctx, double value); // NOLINT(readability-convert-member-functions-to-static)
    void result_error16(const Ref<Sqlite3ContextHandle>& context, const String& error_message, int nbytes); // NOLINT(readability-convert-member-functions-to-static)
    void result_error_nomem(const Ref<Sqlite3ContextHandle>& ctx); // NOLINT(readability-convert-member-functions-to-static)
    void result_value(const Ref<Sqlite3ContextHandle>& context, const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int create_collation_v2(const Ref<Sqlite3Handle>& db, const String& name, int text_rep, Callable compare, Callable destroy); // NOLINT(readability-convert-member-functions-to-static)
    int collation_needed16(const Ref<Sqlite3Handle>& db, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
    String get_temp_directory(void); // NOLINT(readability-convert-member-functions-to-static)
    void set_temp_directory(const String& path); // NOLINT(readability-convert-member-functions-to-static)
    String get_data_directory(void); // NOLINT(readability-convert-member-functions-to-static)
    void set_data_directory(const String& dir); // NOLINT(readability-convert-member-functions-to-static)
#ifdef _WIN32
    int win32_set_directory(int64_t type, const String& z_value); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef _WIN32
    int sqlite3_win32_set_directory8(int64_t type, const String& z_value); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef _WIN32
    int win32_set_directory16(int type, const String& value); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef _WIN32
    int win32_data_directory_type(void); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef _WIN32
    int win32_temp_directory_type(void); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int get_autocommit(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3StmtHandle> next_stmt(const Ref<Sqlite3Handle>& db, const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    int64_t rollback_hook(const Ref<Sqlite3Handle>& db, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
    int release_memory(int n); // NOLINT(readability-convert-member-functions-to-static)
    int db_release_memory(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int hard_heap_limit64(int n); // NOLINT(readability-convert-member-functions-to-static)
    void soft_heap_limit(int n); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary load_extension(const Ref<Sqlite3Handle>& db, const String& file, const String& proc); // NOLINT(readability-convert-member-functions-to-static)
    int cancel_auto_extension(int64_t x_entry_point); // NOLINT(readability-convert-member-functions-to-static)
    void reset_auto_extension(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_scan_unique(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_scan_hex(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_eq(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_gt(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_le(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_lt(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_ge(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_match(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_like(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_glob(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_regexp(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_ne(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_isnot(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_isnotnull(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_isnull(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_is(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_limit(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_offset(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_index_constraint_function(void); // NOLINT(readability-convert-member-functions-to-static)
    int create_module(const Ref<Sqlite3Handle>& db, const String& z_name, const Ref<Sqlite3ModuleHandle>& module, int64_t client_data); // NOLINT(readability-convert-member-functions-to-static)
    int blob_open(const Ref<Sqlite3Handle>& db, const String& db_name, const String& table_name, const String& column_name, int64_t row, int flags, const Ref<Sqlite3BlobHandle>& out_blob); // NOLINT(readability-convert-member-functions-to-static)
    int vfs_register(const Ref<Sqlite3VfsHandle>& vfs, int make_dflt); // NOLINT(readability-convert-member-functions-to-static)
    int vfs_unregister(const Ref<Sqlite3VfsHandle>& vfs); // NOLINT(readability-convert-member-functions-to-static)
    void mutex_free(const Ref<Sqlite3MutexHandle>& mutex); // NOLINT(readability-convert-member-functions-to-static)
    void mutex_enter(const Ref<Sqlite3MutexHandle>& mutex); // NOLINT(readability-convert-member-functions-to-static)
    int mutex_try(const Ref<Sqlite3MutexHandle>& mutex); // NOLINT(readability-convert-member-functions-to-static)
    void mutex_leave(const Ref<Sqlite3MutexHandle>& mutex); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3MutexHandle> db_mutex(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_first(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_prng_save(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_prng_restore(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_prng_reset(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_fk_no_action(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_bitvec_test(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_fault_install(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_benign_malloc_hooks(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_pending_byte(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_assert(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_always(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_reserve(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_json_selfcheck(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_optimizations(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_iskeyword(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_getopt(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_scratchmalloc(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_internal_functions(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_localtime_fault(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_explain_stmt(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_once_reset_threshold(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_never_corrupt(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_vdbe_coverage(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_byteorder(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_isinit(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_sorter_mmap(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_imposter(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_parser_coverage(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_result_intreal(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_prng_seed(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_extra_schema_checks(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_seek_count(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_traceflags(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_tune(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_logest(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_uselongdouble(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_testctrl_last(void); // NOLINT(readability-convert-member-functions-to-static)
    int keyword_count(void); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary keyword_name(int index); // NOLINT(readability-convert-member-functions-to-static)
    int keyword_check(const String& word, int length); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3StrHandle> str_new(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    void str_free(const Ref<Sqlite3StrHandle>& str); // NOLINT(readability-convert-member-functions-to-static)
    void str_append(const Ref<Sqlite3StrHandle>& str, const String& in, int n); // NOLINT(readability-convert-member-functions-to-static)
    void str_appendall(const Ref<Sqlite3StrHandle>& str, const String& z_in); // NOLINT(readability-convert-member-functions-to-static)
    void str_appendchar(const Ref<Sqlite3StrHandle>& str, int n, int c); // NOLINT(readability-convert-member-functions-to-static)
    void str_reset(const Ref<Sqlite3StrHandle>& str); // NOLINT(readability-convert-member-functions-to-static)
    void str_truncate(const Ref<Sqlite3StrHandle>& str, int n); // NOLINT(readability-convert-member-functions-to-static)
    int str_length(const Ref<Sqlite3StrHandle>& str); // NOLINT(readability-convert-member-functions-to-static)
    String str_value(const Ref<Sqlite3StrHandle>& str); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary status64(int op, bool reset_highwater); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_memory_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_pagecache_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_pagecache_overflow(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_scratch_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_scratch_overflow(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_malloc_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_parser_stack(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_pagecache_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_scratch_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_status_malloc_count(void); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary db_status(const Ref<Sqlite3Handle>& db, int op, bool reset_flg); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary db_status64(const Ref<Sqlite3Handle>& db, int op, bool reset_highwater); // NOLINT(readability-convert-member-functions-to-static)
    int stmt_status(const Ref<Sqlite3StmtHandle>& stmt, int op, bool reset_flag); // NOLINT(readability-convert-member-functions-to-static)
    int backup_step(const Ref<Sqlite3BackupHandle>& db_backup, int n_page); // NOLINT(readability-convert-member-functions-to-static)
    int backup_finish(const Ref<Sqlite3BackupHandle>& p); // NOLINT(readability-convert-member-functions-to-static)
    int backup_remaining(const Ref<Sqlite3BackupHandle>& p); // NOLINT(readability-convert-member-functions-to-static)
    int strnicmp(const String& s1, const String& s2, int n); // NOLINT(readability-convert-member-functions-to-static)
    int strglob(const String& glob, const String& str); // NOLINT(readability-convert-member-functions-to-static)
    int strlike(const String& pattern, const String& input, int escape_char); // NOLINT(readability-convert-member-functions-to-static)
    void log(int64_t i_err_code, const String& format, const Array& args); // NOLINT(readability-convert-member-functions-to-static)
    int64_t wal_hook(const Ref<Sqlite3Handle>& db, Callable callback, const Variant& user_data); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_config(const Ref<Sqlite3Handle>& db, int op, const Array& args); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_on_conflict(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_in_next(const Ref<Sqlite3ValueHandle>& p_val, const Ref<Sqlite3ValueHandle>& out_pp_out); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    Dictionary stmt_scanstatus_int(const Ref<Sqlite3StmtHandle>& stmt, int64_t idx, int64_t scan_status_op); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    Dictionary stmt_scanstatus_double(const Ref<Sqlite3StmtHandle>& stmt, int64_t idx, int64_t scan_status_op); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    Dictionary stmt_scanstatus_string(const Ref<Sqlite3StmtHandle>& stmt, int64_t idx, int64_t scan_status_op); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int scanstat_complex(void); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_SNAPSHOT
    int snapshot_get(const Ref<Sqlite3Handle>& db, const String& schema, const Ref<Sqlite3SnapshotHandle>& out_snapshot); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef SQLITE_ENABLE_SNAPSHOT
    void snapshot_free(const Ref<Sqlite3SnapshotHandle>& snapshot); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_DESERIALIZE
    int deserialize(const Ref<Sqlite3Handle>& db, const String& schema, const PackedByteArray& p_data, int64_t sz_db, int64_t sz_buf, int64_t flags); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int carray_bind_v2(const Ref<Sqlite3StmtHandle>& stmt, int index, const PackedByteArray& data, int n_elements, int flags, int x_del, int p_del); // NOLINT(readability-convert-member-functions-to-static)
    int rtree_geometry_callback(const Ref<Sqlite3Handle>& db, const String& z_geom, Callable x_geom); // NOLINT(readability-convert-member-functions-to-static)
    int rtree_query_callback(const Ref<Sqlite3Handle>& db, const String& z_query_func, Callable x_query_func, const Variant& p_context, Callable x_destructor); // NOLINT(readability-convert-member-functions-to-static)
    int not_within(void); // NOLINT(readability-convert-member-functions-to-static)
    int partly_within(void); // NOLINT(readability-convert-member-functions-to-static)
    int fully_within(void); // NOLINT(readability-convert-member-functions-to-static)
    int session_create(const Ref<Sqlite3Handle>& db, const String& z_db, const Ref<Sqlite3SessionHandle>& out_session); // NOLINT(readability-convert-member-functions-to-static)
    int session_enable(const Ref<Sqlite3SessionHandle>& session, int enable); // NOLINT(readability-convert-member-functions-to-static)
    int64_t session_memory_used(const Ref<Sqlite3SessionHandle>& p_session); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_start_v2(const PackedByteArray& changeset, int64_t flags, const Ref<Sqlite3ChangesetIterHandle>& out_iter); // NOLINT(readability-convert-member-functions-to-static)
    int next(const Ref<Sqlite3ChangesetIterHandle>& p_iter); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_concat(const PackedByteArray& a, const PackedByteArray& b); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3ChangegroupHandle> create(void); // NOLINT(readability-convert-member-functions-to-static)
    void changegroup_delete(const Ref<Sqlite3ChangegroupHandle>& changegroup); // NOLINT(readability-convert-member-functions-to-static)
    int rebaser_create(const Ref<Sqlite3RebaserHandle>& out_handle); // NOLINT(readability-convert-member-functions-to-static)
    int configure(const Ref<Sqlite3RebaserHandle>& rebaser, const PackedByteArray& rebase_buffer); // NOLINT(readability-convert-member-functions-to-static)
    void rebaser_delete(const Ref<Sqlite3RebaserHandle>& p_rebaser); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_concat_strm(Callable x_input_a, const Variant& in_a, Callable x_input_b, const Variant& in_b, Callable x_output, const Variant& out); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_start_v2_strm(const Ref<Sqlite3ChangesetIterHandle>& out_iter, Callable x_input, int flags); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_strm(const Ref<Sqlite3SessionHandle>& session, Callable x_output); // NOLINT(readability-convert-member-functions-to-static)
    int patchset_strm(const Ref<Sqlite3SessionHandle>& session, Callable x_output, const Variant& p_out); // NOLINT(readability-convert-member-functions-to-static)
    int changegroup_add_strm(const Ref<Sqlite3ChangegroupHandle>& changegroup, Callable x_input); // NOLINT(readability-convert-member-functions-to-static)
    int session_config_strmsize(void); // NOLINT(readability-convert-member-functions-to-static)
    int close_v2(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary exec(const Ref<Sqlite3Handle>& db, const String& sql, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
    int64_t last_insert_rowid(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    void set_last_insert_rowid(const Ref<Sqlite3Handle>& db, int64_t rowid); // NOLINT(readability-convert-member-functions-to-static)
    int changes(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int total_changes(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int complete(const String& sql); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_SETLK_TIMEOUT
    int setlk_timeout(const Ref<Sqlite3Handle>& db, int ms, int flags); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int setlk_block_on_connect(void); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary get_table(const Ref<Sqlite3Handle>& db, const String& sql); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_deny(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_ignore(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_index(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_table(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_temp_index(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_temp_table(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_temp_trigger(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_temp_view(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_trigger(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_view(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_delete(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_index(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_table(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_temp_index(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_temp_table(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_temp_trigger(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_temp_view(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_trigger(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_view(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_insert(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_pragma(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_read(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_select(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_transaction(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_update(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_attach(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_detach(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_alter_table(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_reindex(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_analyze(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_create_vtable(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_drop_vtable(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_function(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_savepoint(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_copy(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_recursive(void); // NOLINT(readability-convert-member-functions-to-static)
    int64_t profile(const Ref<Sqlite3Handle>& db, Callable x_profile); // NOLINT(readability-convert-member-functions-to-static)
    int trace_stmt(void); // NOLINT(readability-convert-member-functions-to-static)
    int trace_profile(void); // NOLINT(readability-convert-member-functions-to-static)
    int trace_row(void); // NOLINT(readability-convert-member-functions-to-static)
    int trace_close(void); // NOLINT(readability-convert-member-functions-to-static)
    void progress_handler_disable(const Ref<Sqlite3Handle>& db, int n_instructions); // NOLINT(readability-convert-member-functions-to-static)
    int open(const String& filename, const Ref<Sqlite3Handle>& out_db); // NOLINT(readability-convert-member-functions-to-static)
    int open16(const String& filename, const Ref<Sqlite3Handle>& out_db); // NOLINT(readability-convert-member-functions-to-static)
    int open_v2(const String& filename, const Ref<Sqlite3Handle>& out_db, int flags, const String& z_vfs); // NOLINT(readability-convert-member-functions-to-static)
    String errmsg16(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int error_offset(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
    int set_errmsg(const Ref<Sqlite3Handle>& db, int errcode, const String& z_err_msg); // NOLINT(readability-convert-member-functions-to-static)
    int limit_length(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_sql_length(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_column(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_expr_depth(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_compound_select(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_vdbe_op(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_function_arg(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_attached(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_like_pattern_length(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_variable_number(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_trigger_depth(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_worker_threads(void); // NOLINT(readability-convert-member-functions-to-static)
    int limit_parser_depth(void); // NOLINT(readability-convert-member-functions-to-static)
    int prepare_persistent(void); // NOLINT(readability-convert-member-functions-to-static)
    int prepare_normalize(void); // NOLINT(readability-convert-member-functions-to-static)
    int prepare_no_vtab(void); // NOLINT(readability-convert-member-functions-to-static)
    int prepare_dont_log(void); // NOLINT(readability-convert-member-functions-to-static)
    int prepare_from_ddl(void); // NOLINT(readability-convert-member-functions-to-static)
    int prepare(const Ref<Sqlite3Handle>& db, const String& sql, int n_byte, const Ref<Sqlite3StmtHandle>& out_stmt); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary prepare_v2(const Ref<Sqlite3Handle>& db, const String& sql, int64_t n_byte); // NOLINT(readability-convert-member-functions-to-static)
    int prepare_v3(const Ref<Sqlite3Handle>& db, const String& sql, int64_t n_byte, int64_t prep_flags, const Ref<Sqlite3StmtHandle>& out_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int prepare16(const Ref<Sqlite3Handle>& db, const PackedByteArray& z_sql, int n_byte, const Ref<Sqlite3StmtHandle>& out_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int prepare16_v2(const Ref<Sqlite3Handle>& db, const PackedByteArray& sql_utf16, int64_t n_byte, const Ref<Sqlite3StmtHandle>& out_stmt); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary prepare16_v3(const Ref<Sqlite3Handle>& db, const String& sql, int n_byte, int prep_flags); // NOLINT(readability-convert-member-functions-to-static)
    String sql(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_NORMALIZE
    String normalized_sql(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int stmt_readonly(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    int stmt_isexplain(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int stmt_explain(const Ref<Sqlite3StmtHandle>& stmt, int e_mode); // NOLINT(readability-convert-member-functions-to-static)
    int stmt_busy(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    int bind_double(const Ref<Sqlite3StmtHandle>& stmt, int index, double value); // NOLINT(readability-convert-member-functions-to-static)
    int bind_int(const Ref<Sqlite3StmtHandle>& stmt, int index, int value); // NOLINT(readability-convert-member-functions-to-static)
    int bind_null(const Ref<Sqlite3StmtHandle>& stmt, int index); // NOLINT(readability-convert-member-functions-to-static)
    int bind_text(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const String& value, int64_t length, int64_t destructor_flag); // NOLINT(readability-convert-member-functions-to-static)
    int bind_text16(const Ref<Sqlite3StmtHandle>& stmt, int index, const String& value, int length); // NOLINT(readability-convert-member-functions-to-static)
    int bind_text64(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const String& text, int64_t nbytes, int64_t destructor, int64_t encoding); // NOLINT(readability-convert-member-functions-to-static)
    int bind_value(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int bind_pointer(const Ref<Sqlite3StmtHandle>& stmt, int index, int64_t pointer, const String& type); // NOLINT(readability-convert-member-functions-to-static)
    int bind_zeroblob64(const Ref<Sqlite3StmtHandle>& stmt, int64_t index, int64_t size); // NOLINT(readability-convert-member-functions-to-static)
    int bind_parameter_count(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    String bind_parameter_name(const Ref<Sqlite3StmtHandle>& stmt, int64_t index); // NOLINT(readability-convert-member-functions-to-static)
    int bind_parameter_index(const Ref<Sqlite3StmtHandle>& stmt, const String& name); // NOLINT(readability-convert-member-functions-to-static)
    int clear_bindings(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    int column_count(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
    String column_name(const Ref<Sqlite3StmtHandle>& stmt, int column); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_COLUMN_METADATA
    String column_database_name(const Ref<Sqlite3StmtHandle>& stmt, int column); // NOLINT(readability-convert-member-functions-to-static)
#endif
    String column_table_name16(const Ref<Sqlite3StmtHandle>& stmt, int col); // NOLINT(readability-convert-member-functions-to-static)
    String column_origin_name(const Ref<Sqlite3StmtHandle>& stmt, int col); // NOLINT(readability-convert-member-functions-to-static)
    String column_origin_name16(const Ref<Sqlite3StmtHandle>& stmt, int column); // NOLINT(readability-convert-member-functions-to-static)
    String column_decltype(const Ref<Sqlite3StmtHandle>& stmt, int i); // NOLINT(readability-convert-member-functions-to-static)
    int step(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    int data_count(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_integer(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_float(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_blob(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_null(void); // NOLINT(readability-convert-member-functions-to-static)
    String column_text(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    String column_text16(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3ValueHandle> column_value(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    int column_bytes(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    int column_bytes16(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    int column_type(const Ref<Sqlite3StmtHandle>& stmt, int i_col); // NOLINT(readability-convert-member-functions-to-static)
    int finalize(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int reset(const Ref<Sqlite3StmtHandle>& p_stmt); // NOLINT(readability-convert-member-functions-to-static)
    int create_function(const Ref<Sqlite3Handle>& db, const String& function_name, int64_t n_arg, int64_t text_rep, int64_t app_data, Callable x_func, Callable x_step, Callable x_final); // NOLINT(readability-convert-member-functions-to-static)
    int create_function16(const Ref<Sqlite3Handle>& db, const String& function_name, int n_arg, int e_text_rep, Callable x_func, Callable x_step, Callable x_final); // NOLINT(readability-convert-member-functions-to-static)
    int create_function_v2(const Ref<Sqlite3Handle>& db, const String& function_name, int64_t n_arg, int64_t e_text_rep, Callable x_func, Callable x_step, Callable x_final); // NOLINT(readability-convert-member-functions-to-static)
    int create_window_function(const Ref<Sqlite3Handle>& db, const String& function_name, int n_arg, int e_text_rep, Callable step, Callable final, Callable value, Callable inverse, Callable destroy); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_utf8(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_utf16le(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_utf16be(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_utf16(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_any(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_utf16_aligned(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_utf8_zt(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_deterministic(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_directonly(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_subtype(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_innocuous(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_result_subtype(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_selforder1(void); // NOLINT(readability-convert-member-functions-to-static)
#ifndef SQLITE_OMIT_DEPRECATED
    int aggregate_count(const Ref<Sqlite3ContextHandle>& ctx); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    int expired(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    int transfer_bindings(const Ref<Sqlite3StmtHandle>& from, const Ref<Sqlite3StmtHandle>& to); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    int global_recover(void); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    void thread_cleanup(void); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef SQLITE_OMIT_DEPRECATED
    int memory_alarm(Callable callback, int user_data, int threshold); // NOLINT(readability-convert-member-functions-to-static)
#endif
    String value_text(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    String value_text16(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int64_t value_text16le(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    String value_text16be(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_bytes16(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_type(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_numeric_type(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_nochange(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_frombind(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_encoding(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int value_subtype(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3ValueHandle> value_dup(const Ref<Sqlite3ValueHandle>& value); // NOLINT(readability-convert-member-functions-to-static)
    int aggregate_context(const Ref<Sqlite3ContextHandle>& ctx, int n_bytes); // NOLINT(readability-convert-member-functions-to-static)
    int64_t user_data(const Ref<Sqlite3ContextHandle>& ctx); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3Handle> context_db_handle(const Ref<Sqlite3ContextHandle>& ctx); // NOLINT(readability-convert-member-functions-to-static)
    int64_t get_auxdata(const Ref<Sqlite3ContextHandle>& context, int n); // NOLINT(readability-convert-member-functions-to-static)
    int64_t get_clientdata(const Ref<Sqlite3Handle>& db, const String& name); // NOLINT(readability-convert-member-functions-to-static)
    void result_error(const Ref<Sqlite3ContextHandle>& ctx, const String& error_message, int length); // NOLINT(readability-convert-member-functions-to-static)
    void result_error_toobig(const Ref<Sqlite3ContextHandle>& ctx); // NOLINT(readability-convert-member-functions-to-static)
    void result_error_code(const Ref<Sqlite3ContextHandle>& context, int error_code); // NOLINT(readability-convert-member-functions-to-static)
    void result_int(const Ref<Sqlite3ContextHandle>& context, int value); // NOLINT(readability-convert-member-functions-to-static)
    void result_int64(const Ref<Sqlite3ContextHandle>& ctx, int64_t value); // NOLINT(readability-convert-member-functions-to-static)
    void result_null(const Ref<Sqlite3ContextHandle>& ctx); // NOLINT(readability-convert-member-functions-to-static)
    void result_text(const Ref<Sqlite3ContextHandle>& context, const String& text, int64_t length, int64_t destructor); // NOLINT(readability-convert-member-functions-to-static)
    void result_text64(const Ref<Sqlite3ContextHandle>& ctx, const String& text, uint64_t n, int encoding); // NOLINT(readability-convert-member-functions-to-static)
    void result_text16(const Ref<Sqlite3ContextHandle>& ctx, const String& text, int length, int destructor); // NOLINT(readability-convert-member-functions-to-static)
    void result_text16le(const Ref<Sqlite3ContextHandle>& ctx, const PackedByteArray& data, int64_t destructor); // NOLINT(readability-convert-member-functions-to-static)
    void result_text16be(const Ref<Sqlite3ContextHandle>& context, const PackedByteArray& text, int length, int64_t destructor); // NOLINT(readability-convert-member-functions-to-static)
    void result_pointer(const Ref<Sqlite3ContextHandle>& ctx, int data_ptr, const String& type, int destructor_ptr); // NOLINT(readability-convert-member-functions-to-static)
    void result_zeroblob(const Ref<Sqlite3ContextHandle>& ctx, int n); // NOLINT(readability-convert-member-functions-to-static)
    int result_zeroblob64(const Ref<Sqlite3ContextHandle>& context, int64_t n); // NOLINT(readability-convert-member-functions-to-static)
    void result_subtype(const Ref<Sqlite3ContextHandle>& context, int64_t subtype); // NOLINT(readability-convert-member-functions-to-static)
    int create_collation(const Ref<Sqlite3Handle>& db, const String& name, int e_text_rep, const Variant& user_data, Callable compare); // NOLINT(readability-convert-member-functions-to-static)
    int create_collation16(const Ref<Sqlite3Handle>& db, const String& z_name, int e_text_rep, const Variant& user_data, Callable x_compare); // NOLINT(readability-convert-member-functions-to-static)
    int collation_needed(const Ref<Sqlite3Handle>& db, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_CEROD
    void activate_cerod(const String& pass_phrase); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int64_t sleep(int64_t milliseconds); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3Handle> db_handle(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
    String db_name(const Ref<Sqlite3Handle>& db, int N); // NOLINT(readability-convert-member-functions-to-static)
    String db_filename(const Ref<Sqlite3Handle>& db, const String& z_db_name); // NOLINT(readability-convert-member-functions-to-static)
    int db_readonly(const Ref<Sqlite3Handle>& db, const String& db_name); // NOLINT(readability-convert-member-functions-to-static)
    int txn_state(const Ref<Sqlite3Handle>& db, const String& z_schema); // NOLINT(readability-convert-member-functions-to-static)
    int txn_none(void); // NOLINT(readability-convert-member-functions-to-static)
    int txn_read(void); // NOLINT(readability-convert-member-functions-to-static)
    int txn_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int64_t commit_hook(const Ref<Sqlite3Handle>& db, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
    int autovacuum_pages(const Ref<Sqlite3Handle>& db, Callable on_autovacuum, Callable on_userdata_destroy); // NOLINT(readability-convert-member-functions-to-static)
    void update_hook(const Ref<Sqlite3Handle>& db, Callable callback); // NOLINT(readability-convert-member-functions-to-static)
#ifndef SQLITE_OMIT_SHARED_CACHE
    int enable_shared_cache(bool enable); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int64_t soft_heap_limit64(int64_t n); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary table_column_metadata(const Ref<Sqlite3Handle>& db, const String& db_name, const String& table_name, const String& column_name); // NOLINT(readability-convert-member-functions-to-static)
    int enable_load_extension(const Ref<Sqlite3Handle>& db, int onoff); // NOLINT(readability-convert-member-functions-to-static)
    int auto_extension(Callable x_entry_point); // NOLINT(readability-convert-member-functions-to-static)
    int overload_function(const Ref<Sqlite3Handle>& db, const String& func_name, int n_arg); // NOLINT(readability-convert-member-functions-to-static)
    int blob_reopen(const Ref<Sqlite3BlobHandle>& db_blob, int64_t rowid); // NOLINT(readability-convert-member-functions-to-static)
    int blob_close(const Ref<Sqlite3BlobHandle>& blob_handle); // NOLINT(readability-convert-member-functions-to-static)
    int blob_bytes(const Ref<Sqlite3BlobHandle>& blob); // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray blob_read(const Ref<Sqlite3BlobHandle>& blob, int64_t n, int64_t offset); // NOLINT(readability-convert-member-functions-to-static)
    int blob_write(const Ref<Sqlite3BlobHandle>& blob, const PackedByteArray& buffer, int64_t offset); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3VfsHandle> vfs_find(const String& vfs_name); // NOLINT(readability-convert-member-functions-to-static)
#ifndef NDEBUG
    int mutex_held(const Ref<Sqlite3MutexHandle>& handle); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifndef NDEBUG
    int mutex_notheld(const Ref<Sqlite3MutexHandle>& handle); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int sqlite_mutex_fast(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_recursive(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_main(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_mem(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_mem2(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_open(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_prng(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_lru(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_lru2(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_pmem(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_app1(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_app2(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_app3(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_vfs1(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_vfs2(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_vfs3(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_mutex_static_master(void); // NOLINT(readability-convert-member-functions-to-static)
    int file_control(const Ref<Sqlite3Handle>& db, const String& db_name, int op, int data); // NOLINT(readability-convert-member-functions-to-static)
    int test_control(int op, const Array& args); // NOLINT(readability-convert-member-functions-to-static)
    String str_finish(const Ref<Sqlite3StrHandle>& str_handle); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_lookaside_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_cache_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_schema_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_stmt_used(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_lookaside_hit(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_lookaside_miss_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_lookaside_miss_full(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_cache_hit(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_cache_miss(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_cache_write(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_deferred_fks(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_cache_used_shared(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_cache_spill(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_tempbuf_spill(void); // NOLINT(readability-convert-member-functions-to-static)
    int dbstatus_max(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_fullscan_step(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_sort(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_autoindex(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_vm_step(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_reprepare(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_run(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_filter_miss(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_filter_hit(void); // NOLINT(readability-convert-member-functions-to-static)
    int stmtstatus_memused(void); // NOLINT(readability-convert-member-functions-to-static)
    int backup_pagecount(const Ref<Sqlite3BackupHandle>& p); // NOLINT(readability-convert-member-functions-to-static)
    int stricmp(const String& a, const String& b); // NOLINT(readability-convert-member-functions-to-static)
    int wal_autocheckpoint(const Ref<Sqlite3Handle>& db, int N); // NOLINT(readability-convert-member-functions-to-static)
    int wal_checkpoint(const Ref<Sqlite3Handle>& db, const String& db_name); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary wal_checkpoint_v2(const Ref<Sqlite3Handle>& db, const String& z_db, int e_mode); // NOLINT(readability-convert-member-functions-to-static)
    int checkpoint_noop(void); // NOLINT(readability-convert-member-functions-to-static)
    int checkpoint_passive(void); // NOLINT(readability-convert-member-functions-to-static)
    int checkpoint_full(void); // NOLINT(readability-convert-member-functions-to-static)
    int checkpoint_restart(void); // NOLINT(readability-convert-member-functions-to-static)
    int checkpoint_truncate(void); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_constraint_support(void); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_innocuous(void); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_directonly(void); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_uses_all_schemas(void); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_nochange(const Ref<Sqlite3ContextHandle>& context); // NOLINT(readability-convert-member-functions-to-static)
    String vtab_collation(const Ref<Sqlite3IndexInfoHandle>& index_info, int idx); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_rhs_value(const Ref<Sqlite3IndexInfoHandle>& info, int idx, const Ref<Sqlite3ValueHandle>& out_val); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    Dictionary stmt_scanstatus_v2(const Ref<Sqlite3StmtHandle>& stmt, int idx, int scan_status_op, int flags); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef SQLITE_ENABLE_STMT_SCANSTATUS
    void stmt_scanstatus_reset(const Ref<Sqlite3StmtHandle>& stmt); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int db_cacheflush(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    int64_t preupdate_hook(const Ref<Sqlite3Handle>& db, Callable on_preupdate); // NOLINT(readability-convert-member-functions-to-static)
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    int preupdate_old(const Ref<Sqlite3Handle>& db, int64_t n, const Ref<Sqlite3ValueHandle>& out_value); // NOLINT(readability-convert-member-functions-to-static)
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    int preupdate_count(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    int preupdate_depth(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    int preupdate_new(const Ref<Sqlite3Handle>& db, int64_t n, const Ref<Sqlite3ValueHandle>& out_value); // NOLINT(readability-convert-member-functions-to-static)
#endif
#if defined(SQLITE_ENABLE_PREUPDATE_HOOK)
    int preupdate_blobwrite(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int system_errno(const Ref<Sqlite3Handle>& db); // NOLINT(readability-convert-member-functions-to-static)
#ifndef SQLITE_OMIT_DESERIALIZE
    PackedByteArray serialize(const Ref<Sqlite3Handle>& db, const String& schema, int64_t flags); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int serialize_nocopy(void); // NOLINT(readability-convert-member-functions-to-static)
    int deserialize_freeonclose(void); // NOLINT(readability-convert-member-functions-to-static)
    int deserialize_resizeable(void); // NOLINT(readability-convert-member-functions-to-static)
    int deserialize_readonly(void); // NOLINT(readability-convert-member-functions-to-static)
    int carray_bind(const Ref<Sqlite3StmtHandle>& stmt, int index, const PackedByteArray& data, int n_data, int flags); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_carray_int32(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_carray_int64(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_carray_double(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_carray_text(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_carray_blob(void); // NOLINT(readability-convert-member-functions-to-static)
    int carray_int32(void); // NOLINT(readability-convert-member-functions-to-static)
    int carray_int64(void); // NOLINT(readability-convert-member-functions-to-static)
    int carray_double(void); // NOLINT(readability-convert-member-functions-to-static)
    int carray_text(void); // NOLINT(readability-convert-member-functions-to-static)
    int carray_blob(void); // NOLINT(readability-convert-member-functions-to-static)
    void session_delete(const Ref<Sqlite3SessionHandle>& p_session); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3MutexHandle> mutex_alloc(int mutex_type); // NOLINT(readability-convert-member-functions-to-static)
    void str_appendf(const Ref<Sqlite3StrHandle>& str, const String& format, const Array& args); // NOLINT(readability-convert-member-functions-to-static)
    int str_errcode(const Ref<Sqlite3StrHandle>& x); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary status(int op, bool reset_flag); // NOLINT(readability-convert-member-functions-to-static)
    Ref<Sqlite3BackupHandle> backup_init(const Ref<Sqlite3Handle>& p_dest, const String& z_dest_name, const Ref<Sqlite3Handle>& p_source, const String& z_source_name); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_SNAPSHOT
    int snapshot_open(const Ref<Sqlite3Handle>& db, const String& schema, const Ref<Sqlite3SnapshotHandle>& snapshot); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef SQLITE_ENABLE_SNAPSHOT
    int snapshot_cmp(const Ref<Sqlite3SnapshotHandle>& p1, const Ref<Sqlite3SnapshotHandle>& p2); // NOLINT(readability-convert-member-functions-to-static)
#endif
#ifdef SQLITE_ENABLE_SNAPSHOT
    int snapshot_recover(const Ref<Sqlite3Handle>& db, const String& z_db); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int session_object_config(const Ref<Sqlite3SessionHandle>& session, int op, int p_arg); // NOLINT(readability-convert-member-functions-to-static)
    int session_objconfig_size(void); // NOLINT(readability-convert-member-functions-to-static)
    int session_objconfig_rowid(void); // NOLINT(readability-convert-member-functions-to-static)
    int session_indirect(const Ref<Sqlite3SessionHandle>& session, int b_indirect); // NOLINT(readability-convert-member-functions-to-static)
    int session_attach(const Ref<Sqlite3SessionHandle>& p_session, const String& z_tab); // NOLINT(readability-convert-member-functions-to-static)
    void session_table_filter(const Ref<Sqlite3SessionHandle>& session, Callable filter); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary session_changeset(const Ref<Sqlite3SessionHandle>& session); // NOLINT(readability-convert-member-functions-to-static)
    int64_t changeset_size(const Ref<Sqlite3SessionHandle>& session); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary session_diff(const Ref<Sqlite3SessionHandle>& p_session, const String& from_db, const String& table); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary session_patchset(const Ref<Sqlite3SessionHandle>& session); // NOLINT(readability-convert-member-functions-to-static)
    int is_empty(const Ref<Sqlite3SessionHandle>& p_session); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_start(const Ref<Sqlite3ChangesetIterHandle>& out_iter, const PackedByteArray& changeset_blob); // NOLINT(readability-convert-member-functions-to-static)
    int changesetstart_invert(void); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_op(const Ref<Sqlite3ChangesetIterHandle>& iter, bool request_indirect); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary pk(const Ref<Sqlite3ChangesetIterHandle>& iter); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_old(const Ref<Sqlite3ChangesetIterHandle>& p_iter, int i_val, const Ref<Sqlite3ValueHandle>& out_value); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_new(const Ref<Sqlite3ChangesetIterHandle>& p_iter, int i_val, const Ref<Sqlite3ValueHandle>& out_value); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_conflict(const Ref<Sqlite3ChangesetIterHandle>& p_iter, int i_val, const Ref<Sqlite3ValueHandle>& out_value); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary fk_conflicts(const Ref<Sqlite3ChangesetIterHandle>& iter); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_invert(const PackedByteArray& input); // NOLINT(readability-convert-member-functions-to-static)
    int changegroup_schema(const Ref<Sqlite3ChangegroupHandle>& changegroup, const Ref<Sqlite3Handle>& db, const String& db_name); // NOLINT(readability-convert-member-functions-to-static)
    int changegroup_add(const Ref<Sqlite3ChangegroupHandle>& changegroup, const PackedByteArray& data); // NOLINT(readability-convert-member-functions-to-static)
    int add_change(const Ref<Sqlite3ChangegroupHandle>& changegroup, const Ref<Sqlite3ChangesetIterHandle>& iter); // NOLINT(readability-convert-member-functions-to-static)
    PackedByteArray changegroup_output(const Ref<Sqlite3ChangegroupHandle>& group); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_apply(const Ref<Sqlite3Handle>& db, const PackedByteArray& changeset, Callable filter, Callable conflict); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_apply_v2(const Ref<Sqlite3Handle>& db, const PackedByteArray& changeset_blob, Callable x_filter, Callable x_conflict, int64_t flags); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_apply_v3(const Ref<Sqlite3Handle>& db, const PackedByteArray& changeset, Callable x_filter, Callable x_conflict, int flags); // NOLINT(readability-convert-member-functions-to-static)
    int changesetapply_nosavepoint_flag(void); // NOLINT(readability-convert-member-functions-to-static)
    int changesetapply_invert_flag(void); // NOLINT(readability-convert-member-functions-to-static)
    int changesetapply_ignorenoop_flag(void); // NOLINT(readability-convert-member-functions-to-static)
    int changesetapply_fknoaction_flag(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_data_type(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_notfound_type(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_conflict_type(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_constraint_type(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_foreign_key_type(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_omit_result(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_replace_result(void); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_abort_result(void); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary rebase(const Ref<Sqlite3RebaserHandle>& rebaser, const PackedByteArray& input); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_apply_strm(const Ref<Sqlite3Handle>& db, Callable x_input, const Variant& input_ctx, Callable x_filter, Callable x_conflict, const Variant& conflict_ctx); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_apply_v2_strm(const Ref<Sqlite3Handle>& db, Callable x_input, Callable x_filter, Callable x_conflict, int flags); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary changeset_apply_v3_strm(const Ref<Sqlite3Handle>& db, Callable x_input, Callable x_filter, Callable x_conflict, int flags); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_invert_strm(Callable x_input, Callable x_output); // NOLINT(readability-convert-member-functions-to-static)
    int changeset_start_strm(Callable x_input, const Ref<Sqlite3ChangesetIterHandle>& out_iter); // NOLINT(readability-convert-member-functions-to-static)
    int changegroup_output_strm(const Ref<Sqlite3ChangegroupHandle>& changegroup, Callable x_output); // NOLINT(readability-convert-member-functions-to-static)
    int rebase_strm(const Ref<Sqlite3RebaserHandle>& p_rebaser, Callable x_input, Callable x_output); // NOLINT(readability-convert-member-functions-to-static)
    Dictionary session_config(int64_t op, int64_t chunk_size); // NOLINT(readability-convert-member-functions-to-static)
    int tokenize_query(void); // NOLINT(readability-convert-member-functions-to-static)
    int tokenize_prefix(void); // NOLINT(readability-convert-member-functions-to-static)
    int tokenize_document(void); // NOLINT(readability-convert-member-functions-to-static)
    int tokenize_aux(void); // NOLINT(readability-convert-member-functions-to-static)
    int token_colocated(void); // NOLINT(readability-convert-member-functions-to-static)
    int create_module_v2(const Ref<Sqlite3Handle>& db, const String& z_name, const Ref<Sqlite3ModuleHandle>& module, const Variant& client_data, Callable on_destroy); // NOLINT(readability-convert-member-functions-to-static)
    int drop_modules(const Ref<Sqlite3Handle>& db, PackedStringArray keep_list); // NOLINT(readability-convert-member-functions-to-static)
    int declare_vtab(const Ref<Sqlite3Handle>& db, const String& z_sql); // NOLINT(readability-convert-member-functions-to-static)
#ifdef SQLITE_ENABLE_UNLOCK_NOTIFY
    int unlock_notify(const Ref<Sqlite3Handle>& blocked, Callable notify, const Variant& notify_arg); // NOLINT(readability-convert-member-functions-to-static)
#endif
    int vtab_distinct(const Ref<Sqlite3IndexInfoHandle>& info); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_in(const Ref<Sqlite3IndexInfoHandle>& index_info, int i_cons, int b_handle); // NOLINT(readability-convert-member-functions-to-static)
    int vtab_in_first(const Ref<Sqlite3ValueHandle>& p_val, const Ref<Sqlite3ValueHandle>& out_val); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_rollback(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_fail(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_replace(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_nloop(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_nvisit(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_est(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_name(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_explain(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_selectid(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_parentid(void); // NOLINT(readability-convert-member-functions-to-static)
    int sqlite_scanstat_ncycle(void); // NOLINT(readability-convert-member-functions-to-static)
};


#endif // SQLITE3WRAPPER_H
