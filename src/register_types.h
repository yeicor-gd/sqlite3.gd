#ifndef HOME_YEICOR_PROJECTS_SQLITE3_GD_AUTOWRAPPER_SQLITE3_GD_SRC_REGISTER_TYPES_H
#define HOME_YEICOR_PROJECTS_SQLITE3_GD_AUTOWRAPPER_SQLITE3_GD_SRC_REGISTER_TYPES_H

#include "gdextension_interface.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/defs.hpp>

using namespace godot;

void sqlite3_gd_initialize_module(ModuleInitializationLevel p_level);

void sqlite3_gd_uninitialize_module(ModuleInitializationLevel p_level);

extern "C" {
    auto GDE_EXPORT sqlite3_gd_library_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    ) -> GDExtensionBool;
}

#endif // HOME_YEICOR_PROJECTS_SQLITE3_GD_AUTOWRAPPER_SQLITE3_GD_SRC_REGISTER_TYPES_H
