#include "module.h" // NOLINT(misc-include-cleaner)
#include "Sqlite3Wrapper.h" // NOLINT(misc-include-cleaner)
#include <gdextension_interface.h> // NOLINT(misc-include-cleaner)
#include <godot_cpp/godot.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/core/defs.hpp> // NOLINT(misc-include-cleaner)

void gdext_initialize_module_auto(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    // Register wrapped classes
    GDREGISTER_CLASS(Fts5ApiHandle);
    GDREGISTER_CLASS(Fts5TokenizerHandle);
    GDREGISTER_CLASS(Fts5TokenizerV2Handle);
    GDREGISTER_CLASS(Fts5contextHandle);
    GDREGISTER_CLASS(Fts5extensionapiHandle);
    GDREGISTER_CLASS(Fts5phraseiterHandle);
    GDREGISTER_CLASS(Fts5tokenizerHandle);
    GDREGISTER_CLASS(Sqlite3ApiRoutinesHandle);
    GDREGISTER_CLASS(Sqlite3BackupHandle);
    GDREGISTER_CLASS(Sqlite3BlobHandle);
    GDREGISTER_CLASS(Sqlite3ChangegroupHandle);
    GDREGISTER_CLASS(Sqlite3ChangesetIterHandle);
    GDREGISTER_CLASS(Sqlite3ContextHandle);
    GDREGISTER_CLASS(Sqlite3FileHandle);
    GDREGISTER_CLASS(Sqlite3FilenameHandle);
    GDREGISTER_CLASS(Sqlite3Handle);
    GDREGISTER_CLASS(Sqlite3IndexInfoHandle);
    GDREGISTER_CLASS(Sqlite3IoMethodsHandle);
    GDREGISTER_CLASS(Sqlite3MemMethodsHandle);
    GDREGISTER_CLASS(Sqlite3ModuleHandle);
    GDREGISTER_CLASS(Sqlite3MutexHandle);
    GDREGISTER_CLASS(Sqlite3MutexMethodsHandle);
    GDREGISTER_CLASS(Sqlite3PcacheHandle);
    GDREGISTER_CLASS(Sqlite3PcacheMethods2Handle);
    GDREGISTER_CLASS(Sqlite3PcacheMethodsHandle);
    GDREGISTER_CLASS(Sqlite3PcachePageHandle);
    GDREGISTER_CLASS(Sqlite3RebaserHandle);
    GDREGISTER_CLASS(Sqlite3RtreeGeometryHandle);
    GDREGISTER_CLASS(Sqlite3RtreeQueryInfoHandle);
    GDREGISTER_CLASS(Sqlite3SessionHandle);
    GDREGISTER_CLASS(Sqlite3SnapshotHandle);
    GDREGISTER_CLASS(Sqlite3StmtHandle);
    GDREGISTER_CLASS(Sqlite3StrHandle);
    GDREGISTER_CLASS(Sqlite3ValueHandle);
    GDREGISTER_CLASS(Sqlite3VfsHandle);
    GDREGISTER_CLASS(Sqlite3VtabCursorHandle);
    GDREGISTER_CLASS(Sqlite3VtabHandle);
    GDREGISTER_CLASS(Sqlite3Wrapper);
}

void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    // Teardown logic (if any) goes here.
}

extern "C" {
    GDExtensionBool GDE_EXPORT gdext_library_init_auto(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    ) {
        const godot::GDExtensionBinding::InitObject init_obj(
            p_get_proc_address, p_library, r_initialization
        );

        init_obj.register_initializer(gdext_initialize_module_auto);
        init_obj.register_terminator(gdext_uninitialize_module_auto);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
