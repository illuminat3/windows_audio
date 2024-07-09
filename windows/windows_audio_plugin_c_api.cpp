#include "include/windows_audio/windows_audio_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "windows_audio_plugin.h"

void WindowsAudioPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  windows_audio::WindowsAudioPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
