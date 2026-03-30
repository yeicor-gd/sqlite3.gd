#ifndef GDEXT_MODULE_H
#define GDEXT_MODULE_H

#include <gdextension_interface.h> // NOLINT(misc-include-cleaner)
#include <godot_cpp/godot.hpp> // NOLINT(misc-include-cleaner)
#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)

#include "Sqlite3Wrapper.h" // NOLINT(misc-include-cleaner)

using namespace godot;

void gdext_initialize_module_auto(ModuleInitializationLevel p_level);
void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level);

extern "C" {
    GDExtensionBool GDE_EXPORT gdext_library_init_auto(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    );
}

#endif // GDEXT_MODULE_H