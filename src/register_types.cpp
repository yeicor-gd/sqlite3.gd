#include "register_types.h"

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/defs.hpp>

#include "autowrapper/module.h"
#include "gdextension_interface.h"

using namespace godot;

namespace {
    void gdext_initialize_module(ModuleInitializationLevel p_level) {
        gdext_initialize_module_auto(p_level);
    }

    void gdext_uninitialize_module(ModuleInitializationLevel p_level) {
        gdext_uninitialize_module_auto(p_level);
        // Teardown logic (if any) goes here.
    }
}

extern "C" {
    auto GDE_EXPORT gdext_library_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    ) -> GDExtensionBool {
        godot::GDExtensionBinding::InitObject const init_obj(
            p_get_proc_address, p_library, r_initialization
        );

        init_obj.register_initializer(gdext_initialize_module);
        init_obj.register_terminator(gdext_uninitialize_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
