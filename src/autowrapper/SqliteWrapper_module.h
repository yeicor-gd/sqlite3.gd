#ifndef SQLITEWRAPPER_MODULE_H
#define SQLITEWRAPPER_MODULE_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "SqliteWrapper.h"

using namespace godot;

void gdext_initialize_module_auto(ModuleInitializationLevel p_level);
void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level);

extern "C" {
    GDExtensionBool GDE_EXPORT gdext_library_init_auto(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        const GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    );
}

#endif // SQLITEWRAPPER_MODULE_H