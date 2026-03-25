#pragma once

#include "sqlite3.h"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

class Sqlite3Handle : public RefCounted {
    GDCLASS(Sqlite3Handle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3Handle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3Handle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3Handle::is_valid);
    }
public:
    sqlite3* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3FileHandle : public RefCounted {
    GDCLASS(Sqlite3FileHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3FileHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3FileHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3FileHandle::is_valid);
    }
public:
    sqlite3_file* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_file*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3IoMethodsHandle : public RefCounted {
    GDCLASS(Sqlite3IoMethodsHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3IoMethodsHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3IoMethodsHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3IoMethodsHandle::is_valid);
    }
public:
    sqlite3_io_methods* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_io_methods*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3MutexHandle : public RefCounted {
    GDCLASS(Sqlite3MutexHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3MutexHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3MutexHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3MutexHandle::is_valid);
    }
public:
    sqlite3_mutex* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_mutex*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ApiRoutinesHandle : public RefCounted {
    GDCLASS(Sqlite3ApiRoutinesHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3ApiRoutinesHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3ApiRoutinesHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3ApiRoutinesHandle::is_valid);
    }
public:
    sqlite3_api_routines* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_api_routines*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3VfsHandle : public RefCounted {
    GDCLASS(Sqlite3VfsHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3VfsHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3VfsHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3VfsHandle::is_valid);
    }
public:
    sqlite3_vfs* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_vfs*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ContextHandle : public RefCounted {
    GDCLASS(Sqlite3ContextHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3ContextHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3ContextHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3ContextHandle::is_valid);
    }
public:
    sqlite3_context* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_context*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3VtabHandle : public RefCounted {
    GDCLASS(Sqlite3VtabHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3VtabHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3VtabHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3VtabHandle::is_valid);
    }
public:
    sqlite3_vtab* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_vtab*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3IndexInfoHandle : public RefCounted {
    GDCLASS(Sqlite3IndexInfoHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3IndexInfoHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3IndexInfoHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3IndexInfoHandle::is_valid);
    }
public:
    sqlite3_index_info* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_index_info*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3VtabCursorHandle : public RefCounted {
    GDCLASS(Sqlite3VtabCursorHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3VtabCursorHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3VtabCursorHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3VtabCursorHandle::is_valid);
    }
public:
    sqlite3_vtab_cursor* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_vtab_cursor*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ModuleHandle : public RefCounted {
    GDCLASS(Sqlite3ModuleHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3ModuleHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3ModuleHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3ModuleHandle::is_valid);
    }
public:
    sqlite3_module* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_module*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3MutexMethodsHandle : public RefCounted {
    GDCLASS(Sqlite3MutexMethodsHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3MutexMethodsHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3MutexMethodsHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3MutexMethodsHandle::is_valid);
    }
public:
    sqlite3_mutex_methods* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_mutex_methods*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3StrHandle : public RefCounted {
    GDCLASS(Sqlite3StrHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3StrHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3StrHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3StrHandle::is_valid);
    }
public:
    sqlite3_str* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_str*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3StmtHandle : public RefCounted {
    GDCLASS(Sqlite3StmtHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3StmtHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3StmtHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3StmtHandle::is_valid);
    }
public:
    sqlite3_stmt* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_stmt*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcacheHandle : public RefCounted {
    GDCLASS(Sqlite3PcacheHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3PcacheHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3PcacheHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3PcacheHandle::is_valid);
    }
public:
    sqlite3_pcache* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcachePageHandle : public RefCounted {
    GDCLASS(Sqlite3PcachePageHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3PcachePageHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3PcachePageHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3PcachePageHandle::is_valid);
    }
public:
    sqlite3_pcache_page* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache_page*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcacheMethods2Handle : public RefCounted {
    GDCLASS(Sqlite3PcacheMethods2Handle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3PcacheMethods2Handle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3PcacheMethods2Handle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3PcacheMethods2Handle::is_valid);
    }
public:
    sqlite3_pcache_methods2* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache_methods2*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3RtreeGeometryHandle : public RefCounted {
    GDCLASS(Sqlite3RtreeGeometryHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3RtreeGeometryHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3RtreeGeometryHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3RtreeGeometryHandle::is_valid);
    }
public:
    sqlite3_rtree_geometry* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_rtree_geometry*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3RtreeQueryInfoHandle : public RefCounted {
    GDCLASS(Sqlite3RtreeQueryInfoHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3RtreeQueryInfoHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3RtreeQueryInfoHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3RtreeQueryInfoHandle::is_valid);
    }
public:
    sqlite3_rtree_query_info* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_rtree_query_info*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3SessionHandle : public RefCounted {
    GDCLASS(Sqlite3SessionHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3SessionHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3SessionHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3SessionHandle::is_valid);
    }
public:
    sqlite3_session* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_session*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ChangesetIterHandle : public RefCounted {
    GDCLASS(Sqlite3ChangesetIterHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3ChangesetIterHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3ChangesetIterHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3ChangesetIterHandle::is_valid);
    }
public:
    sqlite3_changeset_iter* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_changeset_iter*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ChangegroupHandle : public RefCounted {
    GDCLASS(Sqlite3ChangegroupHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3ChangegroupHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3ChangegroupHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3ChangegroupHandle::is_valid);
    }
public:
    sqlite3_changegroup* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_changegroup*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3RebaserHandle : public RefCounted {
    GDCLASS(Sqlite3RebaserHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3RebaserHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3RebaserHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3RebaserHandle::is_valid);
    }
public:
    sqlite3_rebaser* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_rebaser*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Fts5extensionapiHandle : public RefCounted {
    GDCLASS(Fts5extensionapiHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Fts5extensionapiHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Fts5extensionapiHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Fts5extensionapiHandle::is_valid);
    }
public:
    Fts5ExtensionApi* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5ExtensionApi*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Fts5contextHandle : public RefCounted {
    GDCLASS(Fts5contextHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Fts5contextHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Fts5contextHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Fts5contextHandle::is_valid);
    }
public:
    Fts5Context* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5Context*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Fts5phraseiterHandle : public RefCounted {
    GDCLASS(Fts5phraseiterHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Fts5phraseiterHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Fts5phraseiterHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Fts5phraseiterHandle::is_valid);
    }
public:
    Fts5PhraseIter* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5PhraseIter*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Fts5TokenizerV2Handle : public RefCounted {
    GDCLASS(Fts5TokenizerV2Handle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Fts5TokenizerV2Handle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Fts5TokenizerV2Handle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Fts5TokenizerV2Handle::is_valid);
    }
public:
    fts5_tokenizer_v2* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<fts5_tokenizer_v2*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Fts5ApiHandle : public RefCounted {
    GDCLASS(Fts5ApiHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Fts5ApiHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Fts5ApiHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Fts5ApiHandle::is_valid);
    }
public:
    fts5_api* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<fts5_api*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3MemMethodsHandle : public RefCounted {
    GDCLASS(Sqlite3MemMethodsHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3MemMethodsHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3MemMethodsHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3MemMethodsHandle::is_valid);
    }
public:
    sqlite3_mem_methods* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_mem_methods*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3ValueHandle : public RefCounted {
    GDCLASS(Sqlite3ValueHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3ValueHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3ValueHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3ValueHandle::is_valid);
    }
public:
    sqlite3_value* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_value*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3BlobHandle : public RefCounted {
    GDCLASS(Sqlite3BlobHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3BlobHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3BlobHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3BlobHandle::is_valid);
    }
public:
    sqlite3_blob* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_blob*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3SnapshotHandle : public RefCounted {
    GDCLASS(Sqlite3SnapshotHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3SnapshotHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3SnapshotHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3SnapshotHandle::is_valid);
    }
public:
    sqlite3_snapshot* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_snapshot*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3PcacheMethodsHandle : public RefCounted {
    GDCLASS(Sqlite3PcacheMethodsHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3PcacheMethodsHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3PcacheMethodsHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3PcacheMethodsHandle::is_valid);
    }
public:
    sqlite3_pcache_methods* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_pcache_methods*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Sqlite3BackupHandle : public RefCounted {
    GDCLASS(Sqlite3BackupHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Sqlite3BackupHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Sqlite3BackupHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Sqlite3BackupHandle::is_valid);
    }
public:
    sqlite3_backup* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<sqlite3_backup*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class Fts5tokenizerHandle : public RefCounted {
    GDCLASS(Fts5tokenizerHandle, RefCounted);
protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("set_handle", "handle"), &Fts5tokenizerHandle::set_handle);
        ClassDB::bind_method(D_METHOD("get_handle"), &Fts5tokenizerHandle::get_handle);
        ClassDB::bind_method(D_METHOD("is_valid"), &Fts5tokenizerHandle::is_valid);
    }
public:
    Fts5Tokenizer* handle = nullptr;
    void set_handle(int64_t _handle) { handle = reinterpret_cast<Fts5Tokenizer*>(_handle); }
    int64_t get_handle() const { return reinterpret_cast<int64_t>(handle); }
    bool is_valid() const { return handle != nullptr; }
};

class SqliteWrapper : public RefCounted {
    GDCLASS(SqliteWrapper, RefCounted);
protected:
    static void _bind_methods();
public:
    int version_number(void);
    String version(void);
    String get_sqlite3_version(void);
    String sqlite3_libversion(void);
    String sqlite3_sourceid(void);
    int sqlite3_libversion_number(void);
    int compileoption_used(String option_name);
    String compileoption_get(int index);
    int sqlite3_threadsafe(void);
    int close(Ref<Sqlite3Handle> db);
    int ok(void);
    int error(void);
    int internal(void);
    int perm(void);
    int abort(void);
    int busy(void);
    int locked(void);
    int nomem(void);
    int readonly(void);
    int interrupt(void);
    int ioerr(void);
    int corrupt(void);
    int notfound(void);
    int full(void);
    int cantopen(void);
    int protocol(void);
    int empty(void);
    int schema(void);
    int toobig(void);
    int constraint(void);
    int mismatch(void);
    int misuse(void);
    int nolfs(void);
    int auth(void);
    int format(void);
    int range(void);
    int notadb(void);
    int notice(void);
    int warning(void);
    int row(void);
    int done(void);
    int open_readonly(void);
    int open_readwrite(void);
    int open_create(void);
    int open_memory(void);
    int open_uri(void);
    int open_nomutex(void);
    int open_fullmutex(void);
    int open_sharedcache(void);
    int open_privatecache(void);
    int open_nofollow(void);
    int fcntl_lockstate(void);
    int fcntl_get_lockproxyfile(void);
    int fcntl_set_lockproxyfile(void);
    int fcntl_last_errno(void);
    int fcntl_size_hint(void);
    int fcntl_chunk_size(void);
    int fcntl_file_pointer(void);
    int fcntl_sync_omitted(void);
    int fcntl_win32_av_retry(void);
    int fcntl_persist_wal(void);
    int fcntl_overwrite(void);
    int fcntl_vfsname(void);
    int fcntl_powersafe_overwrite(void);
    int fcntl_pragma(void);
    int fcntl_busyhandler(void);
    int fcntl_tempfilename(void);
    int fcntl_mmap_size(void);
    int fcntl_trace(void);
    int fcntl_has_moved(void);
    int fcntl_sync(void);
    int fcntl_commit_phasetwo(void);
    int fcntl_win32_set_handle(void);
    int fcntl_wal_block(void);
    int fcntl_zipvfs(void);
    int fcntl_rbu(void);
    int fcntl_vfs_pointer(void);
    int fcntl_journal_pointer(void);
    int fcntl_win32_get_handle(void);
    int fcntl_pdb(void);
    int fcntl_begin_atomic_write(void);
    int fcntl_commit_atomic_write(void);
    int fcntl_rollback_atomic_write(void);
    int fcntl_lock_timeout(void);
    int fcntl_data_version(void);
    int fcntl_size_limit(void);
    int fcntl_ckpt_done(void);
    int fcntl_reserve_bytes(void);
    int fcntl_ckpt_start(void);
    int fcntl_external_reader(void);
    int fcntl_cks_file(void);
    int fcntl_reset_cache(void);
    int fcntl_null_io(void);
    int fcntl_block_on_connect(void);
    int fcntl_filestat(void);
    int initialize(void);
    int shutdown(void);
    int os_init(void);
    int os_end(void);
    int access_exists(void);
    int access_readwrite(void);
    int access_read(void);
    int shm_unlock(void);
    int shm_lock(void);
    int shm_shared(void);
    int shm_exclusive(void);
    int shm_nlock(void);
    int64_t total_changes64(Ref<Sqlite3Handle> db);
    int config_singlethread(void);
    int config_multithread(void);
    int config_serialized(void);
    int config_malloc(void);
    int config_getmalloc(void);
    int config_scratch(void);
    int config_pagecache(void);
    int config_heap(void);
    int config_memstatus(void);
    int config_mutex(void);
    int config_getmutex(void);
    int config_lookaside(void);
    int config_pcache(void);
    int config_getpcache(void);
    int config_log(void);
    int config_uri(void);
    int config_pcache2(void);
    int config_getpcache2(void);
    int config_covering_index_scan(void);
    int config_sqllog(void);
    int config_mmap_size(void);
    int config_win32_heapsize(void);
    int config_pcache_hdrsz(void);
    int config_pmasz(void);
    int config_stmtjrnl_spill(void);
    int config_small_malloc(void);
    int config_sorterref_size(void);
    int config_memdb_maxsize(void);
    int config_rowid_in_view(void);
    int dbconfig_maindbname(void);
    int dbconfig_lookaside(void);
    int dbconfig_enable_fkey(void);
    int dbconfig_enable_trigger(void);
    int dbconfig_enable_fts3_tokenizer(void);
    int dbconfig_enable_load_extension(void);
    int dbconfig_no_ckpt_on_close(void);
    int dbconfig_enable_qpsg(void);
    int dbconfig_trigger_eqp(void);
    int dbconfig_reset_database(void);
    int dbconfig_defensive(void);
    int dbconfig_writable_schema(void);
    int dbconfig_legacy_alter_table(void);
    int dbconfig_dqs_dml(void);
    int dbconfig_dqs_ddl(void);
    int dbconfig_enable_view(void);
    int dbconfig_legacy_file_format(void);
    int dbconfig_trusted_schema(void);
    int dbconfig_stmt_scanstatus(void);
    int dbconfig_reverse_scanorder(void);
    int dbconfig_enable_attach_create(void);
    int dbconfig_enable_attach_write(void);
    int dbconfig_enable_comments(void);
    int dbconfig_fp_digits(void);
    int dbconfig_max(void);
    int extended_result_codes(Ref<Sqlite3Handle> db, bool onoff);
    int64_t changes64(Ref<Sqlite3Handle> db);
    int complete16(String sql);
    int64_t malloc64(uint64_t size);
    int busy_handler(Ref<Sqlite3Handle> db, Callable on_busy);
    void free_table(intptr_t result_ptr);
    bool is_interrupted(Ref<Sqlite3Handle> db);
    void free_ptr(int64_t ptr);
    int64_t memory_highwater(bool reset);
    int64_t realloc(int64_t ptr, int size);
    int64_t realloc64(int64_t ptr, uint64_t size);
    intptr_t malloc(int size);
    int64_t memory_used(void);
    uint64_t msize(int64_t ptr);
    void randomness(int length, int64_t buffer_ptr);
    int64_t trace(Ref<Sqlite3Handle> db, Callable callback);
    int set_authorizer(Ref<Sqlite3Handle> db, Callable callback);
    int trace_v2(Ref<Sqlite3Handle> db, unsigned int mask, Callable callback, int64_t context);
    String uri_parameter(String filename, String param);
    bool uri_boolean(String filename, String param, bool default_value);
    int64_t uri_int64(String filename, String param, int64_t default_value);
    String uri_key(String filename, int index);
    String filename_database(String filename);
    String errmsg(Ref<Sqlite3Handle> db);
    String filename_wal(String filename);
    intptr_t database_file_object(String filename);
    intptr_t create_filename(String database, String journal, String wal, int param_count, Array params);
    void free_filename(intptr_t filename_ptr);
    String filename_journal(String filename);
    int extended_errcode(Ref<Sqlite3Handle> db);
    int errcode(Ref<Sqlite3Handle> db);
    String errstr(int result_code);
    int limit(Ref<Sqlite3Handle> db, int id, int new_value);
    String get_expanded_sql(Ref<Sqlite3StmtHandle> stmt);
    int bind_blob(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data);
    int bind_blob64(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data);
    int bind_int64(Ref<Sqlite3StmtHandle> stmt, int index, int64_t value);
    int bind_zeroblob(Ref<Sqlite3StmtHandle> stmt, int index, int length);
    String column_name16(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_database_name16(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_table_name(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_decltype16(Ref<Sqlite3StmtHandle> stmt, int index);
    int constant_text(void);
    PackedByteArray column_blob(Ref<Sqlite3StmtHandle> stmt, int index);
    double column_double(Ref<Sqlite3StmtHandle> stmt, int index);
    int column_int(Ref<Sqlite3StmtHandle> stmt, int index);
    int64_t column_int64(Ref<Sqlite3StmtHandle> stmt, int index);
    PackedByteArray value_blob(Ref<Sqlite3ValueHandle> value);
    double value_double(Ref<Sqlite3ValueHandle> value);
    int value_int(Ref<Sqlite3ValueHandle> value);
    int64_t value_int64(Ref<Sqlite3ValueHandle> value);
    intptr_t value_pointer(Ref<Sqlite3ValueHandle> value, String type_name);
    int value_bytes(Ref<Sqlite3ValueHandle> value);
    void value_free(Ref<Sqlite3ValueHandle> value);
    void set_auxdata(Ref<Sqlite3ContextHandle> context, int n, uint64_t data);
    int set_clientdata(Ref<Sqlite3Handle> db, String name, uint64_t data);
    int constant_sqlite_static(void);
    int constant_sqlite_transient(void);
    void result_blob(Ref<Sqlite3ContextHandle> context, PackedByteArray value);
    void result_blob64(Ref<Sqlite3ContextHandle> context, PackedByteArray value);
    void result_double(Ref<Sqlite3ContextHandle> context, double value);
    void result_error16(Ref<Sqlite3ContextHandle> context, String message);
    void result_error_nomem(Ref<Sqlite3ContextHandle> context);
    void result_value(Ref<Sqlite3ContextHandle> context, Ref<Sqlite3ValueHandle> value);
    int create_collation_v2(Ref<Sqlite3Handle> db, String name, int text_rep, Callable compare_func);
    int collation_needed16(Ref<Sqlite3Handle> db, Callable callback);
    void set_temp_directory(String path);
    String get_temp_directory(void);
    void set_data_directory(String path);
    String get_data_directory(void);
    int win32_set_directory(uint32_t type, String value);
    int win32_set_directory8(uint32_t type, String value);
    int win32_set_directory16(uint32_t type, String value);
    int constant_win32_data_directory_type(void);
    int constant_win32_temp_directory_type(void);
    bool get_autocommit(Ref<Sqlite3Handle> db);
    Ref<Sqlite3StmtHandle> next_stmt(Ref<Sqlite3Handle> db, Ref<Sqlite3StmtHandle> stmt);
    uint64_t rollback_hook(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data);
    int release_memory(int bytes);
    int64_t hard_heap_limit(int64_t limit);
    void soft_heap_limit(int limit);
    int load_extension(Ref<Sqlite3Handle> db, String file, String entry_point);
    int cancel_auto_extension(Callable entry_point);
    void reset_auto_extension(void);
    int index_scan_unique(void);
    int index_scan_hex(void);
    int index_constraint_eq(void);
    int index_constraint_gt(void);
    int index_constraint_le(void);
    int index_constraint_lt(void);
    int index_constraint_ge(void);
    int index_constraint_match(void);
    int index_constraint_like(void);
    int index_constraint_glob(void);
    int index_constraint_regexp(void);
    int index_constraint_ne(void);
    int index_constraint_isnot(void);
    int index_constraint_isnotnull(void);
    int index_constraint_isnull(void);
    int index_constraint_is(void);
    int index_constraint_limit(void);
    int index_constraint_offset(void);
    int index_constraint_function(void);
    int create_module(Ref<Sqlite3Handle> db, String name, Ref<Sqlite3ModuleHandle> module, uint64_t client_data);
    int blob_open(Ref<Sqlite3Handle> db, String db_name, String table_name, String column_name, int64_t row_id, int flags, Ref<Sqlite3BlobHandle> out_blob);
    int vfs_register(Ref<Sqlite3VfsHandle> vfs, bool make_default);
    int vfs_unregister(Ref<Sqlite3VfsHandle> vfs);
    void mutex_free(Ref<Sqlite3MutexHandle> mutex);
    void mutex_enter(Ref<Sqlite3MutexHandle> mutex);
    int mutex_try(Ref<Sqlite3MutexHandle> mutex);
    void mutex_leave(Ref<Sqlite3MutexHandle> mutex);
    Ref<Sqlite3MutexHandle> db_mutex(Ref<Sqlite3Handle> db);
    int test_control_first(void);
    int test_control_prng_save(void);
    int test_control_prng_restore(void);
    int test_control_prng_reset(void);
    int test_control_fk_no_action(void);
    int test_control_bitvec_test(void);
    int test_control_fault_install(void);
    int test_control_benign_malloc_hooks(void);
    int test_control_pending_byte(void);
    int test_control_assert(void);
    int test_control_always(void);
    int test_control_reserve(void);
    int test_control_json_selfcheck(void);
    int test_control_optimizations(void);
    int test_control_iskeyword(void);
    int test_control_getopt(void);
    int test_control_scratchmalloc(void);
    int test_control_internal_functions(void);
    int test_control_localtime_fault(void);
    int test_control_explain_stmt(void);
    int test_control_once_reset_threshold(void);
    int test_control_never_corrupt(void);
    int test_control_vdbe_coverage(void);
    int test_control_byteorder(void);
    int test_control_isinit(void);
    int test_control_sorter_mmap(void);
    int test_control_imposter(void);
    int test_control_parser_coverage(void);
    int test_control_result_intreal(void);
    int test_control_prng_seed(void);
    int test_control_extra_schema_checks(void);
    int test_control_seek_count(void);
    int test_control_traceflags(void);
    int test_control_tune(void);
    int test_control_logest(void);
    int test_control_uselongdouble(void);
    int test_control_last(void);
    int keyword_count(void);
    String keyword_name(int index);
    bool is_keyword(String identifier);
    Ref<Sqlite3StrHandle> str_new(Ref<Sqlite3Handle> db);
    void str_free(Ref<Sqlite3StrHandle> str);
    void str_vappendf(Ref<Sqlite3StrHandle> str, String format, PackedStringArray args);
    void str_append(Ref<Sqlite3StrHandle> str, String text, int length);
    void str_appendall(Ref<Sqlite3StrHandle> str, String text);
    void str_appendchar(Ref<Sqlite3StrHandle> str, int count, int character);
    void str_reset(Ref<Sqlite3StrHandle> str);
    void str_truncate(Ref<Sqlite3StrHandle> str, int length);
    int str_length(Ref<Sqlite3StrHandle> str);
    String str_value(Ref<Sqlite3StrHandle> str);
    Dictionary status64(int op, int reset_flag);
    int status_memory_used(void);
    int status_pagecache_used(void);
    int status_pagecache_overflow(void);
    int status_malloc_size(void);
    int status_parser_stack(void);
    int status_pagecache_size(void);
    int status_malloc_count(void);
    Dictionary db_status(Ref<Sqlite3Handle> db, int op, int reset_flag);
    Dictionary db_status64(Ref<Sqlite3Handle> db, int op, int reset_flag);
    int stmt_status(Ref<Sqlite3StmtHandle> stmt, int op, bool reset_flag);
    int backup_step(Ref<Sqlite3BackupHandle> backup, int n_page);
    int backup_finish(Ref<Sqlite3BackupHandle> backup);
    int backup_remaining(Ref<Sqlite3BackupHandle> backup);
    int str_nicmp(String a, String b, int n);
    int str_glob(String pattern, String str);
    int str_like(String pattern, String str, int escape);
    void log(int error_code, String format);
    int64_t wal_hook(Ref<Sqlite3Handle> db, Callable callback, int64_t user_data);
    int vtab_config(Ref<Sqlite3Handle> db, int op, Variant args);
    int vtab_on_conflict(Ref<Sqlite3Handle> db);
    int vtab_in_next(Ref<Sqlite3ValueHandle> pVal, Ref<Sqlite3ValueHandle> out_value);
    int stmt_scanstatus(Ref<Sqlite3StmtHandle> stmt, int idx, int scan_status_op, Variant out_value);
    int stmt_scanstat_complex(void);
    int snapshot_get(Ref<Sqlite3Handle> db, String schema, Ref<Sqlite3SnapshotHandle> out_snapshot);
    void snapshot_free(Ref<Sqlite3SnapshotHandle> snapshot);
    int deserialize(Ref<Sqlite3Handle> db, String schema, PackedByteArray data, int64_t sz_db, int64_t sz_buf, int flags);
    int carray_bind_v2(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data, int n_data, int flags);
    int rtree_query_callback(Ref<Sqlite3Handle> db, String query_func, Callable on_query);
    int not_within(void);
    int partly_within(void);
    int fully_within(void);
    int session_create(Ref<Sqlite3Handle> db, String z_db, Ref<Sqlite3SessionHandle> out_session);
    int session_enable(Ref<Sqlite3SessionHandle> session, int b_enable);
    int64_t session_memory_used(Ref<Sqlite3SessionHandle> session);
    int changeset_start_v2(Ref<Sqlite3ChangesetIterHandle> out_iter, PackedByteArray changeset, int flags);
    int changeset_next(Ref<Sqlite3ChangesetIterHandle> iter);
    Array changeset_concat(PackedByteArray input_a, PackedByteArray input_b);
    int changegroup_new(Ref<Sqlite3ChangegroupHandle> out_handle);
    Ref<Sqlite3RebaserHandle> rebaser_create(void);
    int rebaser_configure(Ref<Sqlite3RebaserHandle> rebaser, PackedByteArray rebase_data);
    void rebaser_destroy(Ref<Sqlite3RebaserHandle> rebaser);
    PackedByteArray changeset_concat_stream(PackedByteArray changeset_a, PackedByteArray changeset_b);
    Ref<Sqlite3ChangesetIterHandle> changeset_start_v2_stream(PackedByteArray changeset, int flags);
    PackedByteArray session_changeset_stream(Ref<Sqlite3SessionHandle> session);
    PackedByteArray session_patchset_stream(Ref<Sqlite3SessionHandle> session);
    int changegroup_add_stream(Ref<Sqlite3ChangegroupHandle> changegroup, PackedByteArray data);
    int session_config_strmsize(void);
    int close_v2(Ref<Sqlite3Handle> db);
    int exec(Ref<Sqlite3Handle> db, String sql, Callable callback);
    int64_t last_insert_rowid(Ref<Sqlite3Handle> db);
    void set_last_insert_rowid(Ref<Sqlite3Handle> db, int64_t rowid);
    int changes(Ref<Sqlite3Handle> db);
    int total_changes(Ref<Sqlite3Handle> db);
    int complete(String sql);
    int busy_timeout(Ref<Sqlite3Handle> db, int ms);
    int setlk_timeout(Ref<Sqlite3Handle> db, int ms, int flags);
    int setlk_block_on_connect_flag(void);
    int get_table(Ref<Sqlite3Handle> db, String sql, Array out_result, int out_rows, int out_columns, String out_error);
    int deny_code(void);
    int ignore_code(void);
    int create_index_action(void);
    int create_table_action(void);
    int create_temp_index_action(void);
    int create_temp_table_action(void);
    int create_temp_trigger_action(void);
    int create_temp_view_action(void);
    int create_trigger_action(void);
    int create_view_action(void);
    int delete_action(void);
    int drop_index_action(void);
    int drop_table_action(void);
    int drop_temp_index_action(void);
    int drop_temp_table_action(void);
    int drop_temp_trigger_action(void);
    int drop_temp_view_action(void);
    int drop_trigger_action(void);
    int drop_view_action(void);
    int insert_action(void);
    int pragma_action(void);
    int read_action(void);
    int select_action(void);
    int transaction_action(void);
    int update_action(void);
    int attach_action(void);
    int detach_action(void);
    int alter_table_action(void);
    int reindex_action(void);
    int analyze_action(void);
    int create_vtable_action(void);
    int drop_vtable_action(void);
    int function_action(void);
    int savepoint_action(void);
    int copy_action(void);
    int recursive_action(void);
    int64_t profile(Ref<Sqlite3Handle> db, Callable callback);
    int trace_stmt_mask(void);
    int trace_profile_mask(void);
    int trace_row_mask(void);
    int trace_close_mask(void);
    void progress_handler(Ref<Sqlite3Handle> db, int n, Callable callback);
    int open(String filename, Ref<Sqlite3Handle> out_db);
    int open16(String filename, Ref<Sqlite3Handle> out_db);
    int open_v2(String filename, Ref<Sqlite3Handle> out_db, int flags, String vfs);
    String errmsg16(Ref<Sqlite3Handle> db);
    int error_offset(Ref<Sqlite3Handle> db);
    int set_errmsg(Ref<Sqlite3Handle> db, int errcode, String errmsg);
    int limit_length(void);
    int limit_sql_length(void);
    int limit_column(void);
    int limit_expr_depth(void);
    int limit_compound_select(void);
    int limit_vdbe_op(void);
    int limit_function_arg(void);
    int limit_attached(void);
    int limit_like_pattern_length(void);
    int limit_variable_number(void);
    int limit_trigger_depth(void);
    int limit_worker_threads(void);
    int limit_parser_depth(void);
    int prepare_persistent_flag(void);
    int prepare_normalize_flag(void);
    int prepare_no_vtab_flag(void);
    int prepare_dont_log_flag(void);
    int prepare_from_ddl_flag(void);
    int prepare(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail);
    int prepare_v2(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail);
    int prepare_v3(Ref<Sqlite3Handle> db, String sql, int max_bytes, unsigned int prep_flags, Ref<Sqlite3StmtHandle> out_stmt, String out_tail);
    int prepare16(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail);
    int prepare16_v2(Ref<Sqlite3Handle> db, String sql, int max_bytes, Ref<Sqlite3StmtHandle> out_stmt, String out_tail);
    int prepare16_v3(Ref<Sqlite3Handle> db, String sql, int max_bytes, unsigned int prep_flags, Ref<Sqlite3StmtHandle> out_stmt, String out_tail);
    String get_sql(Ref<Sqlite3StmtHandle> stmt);
    String get_normalized_sql(Ref<Sqlite3StmtHandle> stmt);
    bool is_read_only(Ref<Sqlite3StmtHandle> stmt);
    int is_explain(Ref<Sqlite3StmtHandle> stmt);
    int set_explain_mode(Ref<Sqlite3StmtHandle> stmt, int mode);
    bool is_busy(Ref<Sqlite3StmtHandle> stmt);
    int bind_double(Ref<Sqlite3StmtHandle> stmt, int index, double value);
    int bind_int(Ref<Sqlite3StmtHandle> stmt, int index, int value);
    int bind_null(Ref<Sqlite3StmtHandle> stmt, int index);
    int bind_text(Ref<Sqlite3StmtHandle> stmt, int index, String text);
    int bind_text16(Ref<Sqlite3StmtHandle> stmt, int index, String text);
    int bind_text64(Ref<Sqlite3StmtHandle> stmt, int index, String text);
    int bind_value(Ref<Sqlite3StmtHandle> stmt, int index, Ref<Sqlite3ValueHandle> value);
    int bind_pointer(Ref<Sqlite3StmtHandle> stmt, int index, int64_t pointer, String type);
    int bind_zeroblob64(Ref<Sqlite3StmtHandle> stmt, int index, uint64_t length);
    int bind_parameter_count(Ref<Sqlite3StmtHandle> stmt);
    String bind_parameter_name(Ref<Sqlite3StmtHandle> stmt, int index);
    int bind_parameter_index(Ref<Sqlite3StmtHandle> stmt, String name);
    int clear_bindings(Ref<Sqlite3StmtHandle> stmt);
    int column_count(Ref<Sqlite3StmtHandle> stmt);
    String column_name(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_database_name(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_table_name16(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_origin_name(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_origin_name16(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_decltype(Ref<Sqlite3StmtHandle> stmt, int index);
    int step(Ref<Sqlite3StmtHandle> stmt);
    int data_count(Ref<Sqlite3StmtHandle> stmt);
    int constant_integer(void);
    int constant_float(void);
    int constant_blob(void);
    int constant_null(void);
    String column_text(Ref<Sqlite3StmtHandle> stmt, int index);
    String column_text16(Ref<Sqlite3StmtHandle> stmt, int index);
    Ref<Sqlite3ValueHandle> column_value(Ref<Sqlite3StmtHandle> stmt, int index);
    int column_bytes(Ref<Sqlite3StmtHandle> stmt, int index);
    int column_bytes16(Ref<Sqlite3StmtHandle> stmt, int index);
    int column_type(Ref<Sqlite3StmtHandle> stmt, int index);
    int finalize(Ref<Sqlite3StmtHandle> stmt);
    int reset(Ref<Sqlite3StmtHandle> stmt);
    int create_function(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func);
    int create_function16(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func);
    int create_function_v2(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func);
    int create_window_function(Ref<Sqlite3Handle> db, String function_name, int n_arg, int text_rep, Callable func);
    int constant_utf8(void);
    int constant_utf16le(void);
    int constant_utf16be(void);
    int constant_utf16(void);
    int constant_any(void);
    int constant_utf16_aligned(void);
    int constant_utf8_zt(void);
    int constant_deterministic(void);
    int constant_directonly(void);
    int constant_subtype(void);
    int constant_innocuous(void);
    int constant_result_subtype(void);
    int constant_selforder1(void);
    int aggregate_count(Ref<Sqlite3ContextHandle> context);
    int expired(Ref<Sqlite3StmtHandle> stmt);
    int transfer_bindings(Ref<Sqlite3StmtHandle> from_stmt, Ref<Sqlite3StmtHandle> to_stmt);
    int global_recover(void);
    void thread_cleanup(void);
    int memory_alarm(Callable callback, int64_t threshold);
    String value_text(Ref<Sqlite3ValueHandle> value);
    String value_text16(Ref<Sqlite3ValueHandle> value);
    String value_text16le(Ref<Sqlite3ValueHandle> value);
    String value_text16be(Ref<Sqlite3ValueHandle> value);
    int value_bytes16(Ref<Sqlite3ValueHandle> value);
    int value_type(Ref<Sqlite3ValueHandle> value);
    int value_numeric_type(Ref<Sqlite3ValueHandle> value);
    int value_nochange(Ref<Sqlite3ValueHandle> value);
    int value_frombind(Ref<Sqlite3ValueHandle> value);
    int value_encoding(Ref<Sqlite3ValueHandle> value);
    uint32_t value_subtype(Ref<Sqlite3ValueHandle> value);
    Ref<Sqlite3ValueHandle> value_dup(Ref<Sqlite3ValueHandle> value);
    uint64_t aggregate_context(Ref<Sqlite3ContextHandle> context, int n_bytes);
    uint64_t user_data(Ref<Sqlite3ContextHandle> context);
    Ref<Sqlite3Handle> context_db_handle(Ref<Sqlite3ContextHandle> context);
    uint64_t get_auxdata(Ref<Sqlite3ContextHandle> context, int n);
    uint64_t get_clientdata(Ref<Sqlite3Handle> db, String name);
    void result_error(Ref<Sqlite3ContextHandle> context, String message);
    void result_error_toobig(Ref<Sqlite3ContextHandle> context);
    void result_error_code(Ref<Sqlite3ContextHandle> context, int error_code);
    void result_int(Ref<Sqlite3ContextHandle> context, int value);
    void result_int64(Ref<Sqlite3ContextHandle> context, int64_t value);
    void result_null(Ref<Sqlite3ContextHandle> context);
    void result_text(Ref<Sqlite3ContextHandle> context, String value);
    void result_text64(Ref<Sqlite3ContextHandle> context, String value, int encoding);
    void result_text16(Ref<Sqlite3ContextHandle> context, String value);
    void result_text16le(Ref<Sqlite3ContextHandle> context, String value);
    void result_text16be(Ref<Sqlite3ContextHandle> context, String value);
    void result_pointer(Ref<Sqlite3ContextHandle> context, uint64_t value, String type_name);
    void result_zeroblob(Ref<Sqlite3ContextHandle> context, int n);
    int result_zeroblob64(Ref<Sqlite3ContextHandle> context, uint64_t n);
    void result_subtype(Ref<Sqlite3ContextHandle> context, uint32_t subtype);
    int create_collation(Ref<Sqlite3Handle> db, String name, int text_rep, Callable compare_func);
    int create_collation16(Ref<Sqlite3Handle> db, String name, int text_rep, Callable compare_func);
    int collation_needed(Ref<Sqlite3Handle> db, Callable callback);
    void activate_cerod(String passphrase);
    int sleep(int milliseconds);
    Ref<Sqlite3Handle> db_handle(Ref<Sqlite3StmtHandle> stmt);
    String db_name(Ref<Sqlite3Handle> db, int n);
    String db_filename(Ref<Sqlite3Handle> db, String db_name);
    int db_readonly(Ref<Sqlite3Handle> db, String db_name);
    int txn_state(Ref<Sqlite3Handle> db, String schema);
    int constant_txn_none(void);
    int constant_txn_read(void);
    int constant_txn_write(void);
    uint64_t commit_hook(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data);
    int autovacuum_pages(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data);
    uint64_t update_hook(Ref<Sqlite3Handle> db, Callable callback, uint64_t user_data);
    int enable_shared_cache(bool enable);
    Dictionary table_column_metadata(Ref<Sqlite3Handle> db, String database_name, String table_name, String column_name);
    int enable_load_extension(Ref<Sqlite3Handle> db, bool enable);
    int auto_extension(Callable entry_point);
    int overload_function(Ref<Sqlite3Handle> db, String func_name, int n_arg);
    int blob_reopen(Ref<Sqlite3BlobHandle> blob, int64_t row_id);
    int blob_close(Ref<Sqlite3BlobHandle> blob);
    int blob_bytes(Ref<Sqlite3BlobHandle> blob);
    PackedByteArray blob_read(Ref<Sqlite3BlobHandle> blob, int size, int offset);
    int blob_write(Ref<Sqlite3BlobHandle> blob, PackedByteArray data, int offset);
    Ref<Sqlite3VfsHandle> vfs_find(String vfs_name);
    bool mutex_held(Ref<Sqlite3MutexHandle> mutex);
    bool mutex_notheld(Ref<Sqlite3MutexHandle> mutex);
    int mutex_fast(void);
    int mutex_recursive(void);
    int mutex_static_main(void);
    int mutex_static_mem(void);
    int mutex_static_mem2(void);
    int mutex_static_open(void);
    int mutex_static_prng(void);
    int mutex_static_lru(void);
    int mutex_static_lru2(void);
    int mutex_static_pmem(void);
    int mutex_static_app1(void);
    int mutex_static_app2(void);
    int mutex_static_app3(void);
    int mutex_static_vfs1(void);
    int mutex_static_vfs2(void);
    int mutex_static_vfs3(void);
    int mutex_static_master(void);
    int file_control(Ref<Sqlite3Handle> db, String db_name, int op, int64_t arg);
    int test_control(int op);
    String str_finish(Ref<Sqlite3StrHandle> str);
    int db_status_lookaside_used(void);
    int db_status_cache_used(void);
    int db_status_schema_used(void);
    int db_status_stmt_used(void);
    int db_status_lookaside_hit(void);
    int db_status_lookaside_miss_size(void);
    int db_status_lookaside_miss_full(void);
    int db_status_cache_hit(void);
    int db_status_cache_miss(void);
    int db_status_cache_write(void);
    int db_status_deferred_fks(void);
    int db_status_cache_used_shared(void);
    int db_status_cache_spill(void);
    int db_status_tempbuf_spill(void);
    int stmtstatus_fullscan_step(void);
    int stmtstatus_sort(void);
    int stmtstatus_autoindex(void);
    int stmtstatus_vm_step(void);
    int stmtstatus_reprepare(void);
    int stmtstatus_run(void);
    int stmtstatus_filter_miss(void);
    int stmtstatus_filter_hit(void);
    int stmtstatus_memused(void);
    int backup_pagecount(Ref<Sqlite3BackupHandle> backup);
    int str_icmp(String a, String b);
    int wal_autocheckpoint(Ref<Sqlite3Handle> db, int threshold);
    int wal_checkpoint(Ref<Sqlite3Handle> db, String database_name);
    Array wal_checkpoint_v2(Ref<Sqlite3Handle> db, String database_name, int mode);
    int checkpoint_noop(void);
    int checkpoint_passive(void);
    int checkpoint_full(void);
    int checkpoint_restart(void);
    int checkpoint_truncate(void);
    int vtab_constraint_support(void);
    int vtab_innocuous(void);
    int vtab_directonly(void);
    int vtab_uses_all_schemas(void);
    bool vtab_nochange(Ref<Sqlite3ContextHandle> context);
    String vtab_collation(Ref<Sqlite3IndexInfoHandle> info, int idx);
    int vtab_rhs_value(Ref<Sqlite3IndexInfoHandle> info, int idx, Ref<Sqlite3ValueHandle> out_value);
    int stmt_scanstatus_v2(Ref<Sqlite3StmtHandle> stmt, int idx, int scan_status_op, int flags, Variant out_value);
    void stmt_scanstatus_reset(Ref<Sqlite3StmtHandle> stmt);
    int db_cacheflush(Ref<Sqlite3Handle> db);
    Variant preupdate_hook(Ref<Sqlite3Handle> db, Callable callback);
    int preupdate_count(Ref<Sqlite3Handle> db);
    int preupdate_depth(Ref<Sqlite3Handle> db);
    Variant preupdate_old(Ref<Sqlite3Handle> db, int column_index);
    Variant preupdate_new(Ref<Sqlite3Handle> db, int column_index);
    int preupdate_blobwrite(Ref<Sqlite3Handle> db);
    int system_errno(Ref<Sqlite3Handle> db);
    PackedByteArray serialize(Ref<Sqlite3Handle> db, String schema, int flags);
    int serialize_flag_nocopy(void);
    int deserialize_flag_freeonclose(void);
    int deserialize_flag_resizeable(void);
    int deserialize_flag_readonly(void);
    int carray_bind(Ref<Sqlite3StmtHandle> stmt, int index, PackedByteArray data, int n_data, int flags);
    int carray_type_int32(void);
    int carray_type_int64(void);
    int carray_type_double(void);
    int carray_type_text(void);
    int carray_type_blob(void);
    void session_delete(Ref<Sqlite3SessionHandle> session);
    Ref<Sqlite3MutexHandle> mutex_alloc(int type);
    void str_appendf(Ref<Sqlite3StrHandle> str, String format);
    int str_errcode(Ref<Sqlite3StrHandle> str);
    Dictionary status(int op, int reset_flag);
    int snapshot_open(Ref<Sqlite3Handle> db, String schema, Ref<Sqlite3SnapshotHandle> snapshot);
    int snapshot_cmp(Ref<Sqlite3SnapshotHandle> p1, Ref<Sqlite3SnapshotHandle> p2);
    int snapshot_recover(Ref<Sqlite3Handle> db, String schema);
    int session_object_config(Ref<Sqlite3SessionHandle> session, int op, int64_t p_arg);
    int session_objconfig_size(void);
    int session_objconfig_rowid(void);
    int session_indirect(Ref<Sqlite3SessionHandle> session, int b_indirect);
    int session_attach(Ref<Sqlite3SessionHandle> session, String z_tab);
    void session_table_filter(Ref<Sqlite3SessionHandle> session, Callable filter);
    int session_changeset(Ref<Sqlite3SessionHandle> session, PackedByteArray out_changeset, int out_size);
    int64_t session_changeset_size(Ref<Sqlite3SessionHandle> session);
    int session_diff(Ref<Sqlite3SessionHandle> session, String z_from_db, String z_tbl, String out_error);
    int session_patchset(Ref<Sqlite3SessionHandle> session, PackedByteArray out_patchset, int out_size);
    bool session_isempty(Ref<Sqlite3SessionHandle> session);
    int changeset_start(Ref<Sqlite3ChangesetIterHandle> out_iter, PackedByteArray changeset);
    int changeset_start_invert_flag(void);
    int changeset_op(Ref<Sqlite3ChangesetIterHandle> iter, String out_table, int out_col_count, int out_op, bool out_indirect);
    int changeset_pk(Ref<Sqlite3ChangesetIterHandle> iter, PackedByteArray out_pk, int out_col_count);
    int changeset_old(Ref<Sqlite3ChangesetIterHandle> iter, int i_val, Ref<Sqlite3ValueHandle> out_value);
    int changeset_new(Ref<Sqlite3ChangesetIterHandle> iter, int i_val, Ref<Sqlite3ValueHandle> out_value);
    int changeset_conflict(Ref<Sqlite3ChangesetIterHandle> iter, int i_val, Ref<Sqlite3ValueHandle> out_value);
    Array changeset_fk_conflicts(Ref<Sqlite3ChangesetIterHandle> iter);
    int changeset_finalize(Ref<Sqlite3ChangesetIterHandle> iter);
    Array changeset_invert(PackedByteArray input);
    int changegroup_schema(Ref<Sqlite3ChangegroupHandle> changegroup, Ref<Sqlite3Handle> db, String db_name);
    int changegroup_add(Ref<Sqlite3ChangegroupHandle> changegroup, PackedByteArray input);
    int changegroup_add_change(Ref<Sqlite3ChangegroupHandle> changegroup, Ref<Sqlite3ChangesetIterHandle> iter);
    Array changegroup_output(Ref<Sqlite3ChangegroupHandle> changegroup);
    int changeset_apply(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback);
    int changeset_apply_v2(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags);
    int changeset_apply_v3(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags);
    int changeset_apply_flag_no_savepoint(void);
    int changeset_apply_flag_invert(void);
    int changeset_apply_flag_ignore_noop(void);
    int changeset_apply_flag_fk_no_action(void);
    int changeset_conflict_type_data(void);
    int changeset_conflict_type_not_found(void);
    int changeset_conflict_type_conflict(void);
    int changeset_conflict_type_constraint(void);
    int changeset_conflict_type_foreign_key(void);
    int changeset_conflict_result_omit(void);
    int changeset_conflict_result_replace(void);
    int changeset_conflict_result_abort(void);
    PackedByteArray rebaser_rebase(Ref<Sqlite3RebaserHandle> rebaser, PackedByteArray changeset);
    PackedByteArray changegroup_output_stream(Ref<Sqlite3ChangegroupHandle> changegroup);
    int changeset_apply_stream(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback);
    int changeset_apply_v2_stream(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags);
    int changeset_apply_v3_stream(Ref<Sqlite3Handle> db, PackedByteArray changeset, Callable filter_callback, Callable conflict_callback, PackedByteArray rebase_data, int flags);
    PackedByteArray changeset_invert_stream(PackedByteArray changeset);
    Ref<Sqlite3ChangesetIterHandle> changeset_start_stream(PackedByteArray changeset);
    int session_config_stream_size(int new_size);
    PackedByteArray rebaser_rebase_stream(Ref<Sqlite3RebaserHandle> rebaser, PackedByteArray input_data);
    int fts5_tokenize_query(void);
    int fts5_tokenize_prefix(void);
    int fts5_tokenize_document(void);
    int fts5_tokenize_aux(void);
    int fts5_token_colocated(void);
    int create_module_v2(Ref<Sqlite3Handle> db, String name, Ref<Sqlite3ModuleHandle> module, uint64_t client_data, Callable destructor);
    int unlock_notify(Ref<Sqlite3Handle> db, Callable on_notify, Variant user_data);
    int declare_vtab(Ref<Sqlite3Handle> db, String sql);
    int drop_modules(Ref<Sqlite3Handle> db, PackedStringArray keep);
    int vtab_distinct(Ref<Sqlite3IndexInfoHandle> info);
    int conflict_rollback(void);
    int conflict_ignore(void);
    int conflict_fail(void);
    int conflict_replace(void);
    int stmt_scanstat_nloop(void);
    int stmt_scanstat_nvisit(void);
    int stmt_scanstat_est(void);
    int stmt_scanstat_name(void);
    int stmt_scanstat_explain(void);
    int stmt_scanstat_selectid(void);
    int stmt_scanstat_parentid(void);
    int stmt_scanstat_ncycle(void);
    int vtab_in(Ref<Sqlite3IndexInfoHandle> info, int iCons, int bHandle);
    int vtab_in_first(Ref<Sqlite3ValueHandle> pVal, Ref<Sqlite3ValueHandle> out_value);
};
