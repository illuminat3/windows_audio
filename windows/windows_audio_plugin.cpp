#include "windows_audio_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>
#include <thread>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

namespace windows_audio {

// Static
void WindowsAudioPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "windows_audio",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<WindowsAudioPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

WindowsAudioPlugin::WindowsAudioPlugin() {
  ma_result result = ma_engine_init(NULL, &engine_);
  if (result != MA_SUCCESS) {
    // Handle error
  }
}

WindowsAudioPlugin::~WindowsAudioPlugin() {
  ma_engine_uninit(&engine_);
  if (audio_thread_.joinable()) {
    audio_thread_.join();
  }
}

void WindowsAudioPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("load") == 0) {
    const std::string *file_path = std::get_if<std::string>(method_call.arguments());
    if (file_path) {
      Load(*file_path);
      result->Success();
    } else {
      result->Error("Invalid argument", "File path is required.");
    }
  } else if (method_call.method_name().compare("play") == 0) {
    Play();
    result->Success();
  } else {
    result->NotImplemented();
  }
}

void WindowsAudioPlugin::Load(const std::string &file_path) {
  audio_file_path_ = file_path;
  ma_result result = ma_sound_init_from_file(&engine_, audio_file_path_.c_str(), 0, NULL, NULL, &sound_);
  if (result != MA_SUCCESS) {
    // Handle error
  }
}

void WindowsAudioPlugin::Play() {
  if (audio_thread_.joinable()) {
    audio_thread_.join();
  }

  audio_thread_ = std::thread([this]() {
    ma_result result = ma_sound_start(&sound_);
    if (result != MA_SUCCESS) {
      // Handle error
    }

    // Wait until the audio is finished
    while (ma_sound_is_playing(&sound_)) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    ma_sound_uninit(&sound_);
  });
}

}  // namespace windows_audio
