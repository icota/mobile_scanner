//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <mobile_scanner/mobile_scanner_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) mobile_scanner_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "MobileScannerPlugin");
  mobile_scanner_plugin_register_with_registrar(mobile_scanner_registrar);
}
