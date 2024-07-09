#ifndef FLUTTER_PLUGIN_WINDOWS_AUDIO_PLUGIN_H_
#define FLUTTER_PLUGIN_WINDOWS_AUDIO_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace windows_audio {

class WindowsAudioPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  WindowsAudioPlugin();

  virtual ~WindowsAudioPlugin();

  // Disallow copy and assign.
  WindowsAudioPlugin(const WindowsAudioPlugin&) = delete;
  WindowsAudioPlugin& operator=(const WindowsAudioPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace windows_audio

#endif  // FLUTTER_PLUGIN_WINDOWS_AUDIO_PLUGIN_H_
