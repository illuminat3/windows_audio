#include "windows_audio_plugin.h"
#include <flutter/standard_method_codec.h> 
#include <gtest/gtest.h>
#include <memory>

namespace windows_audio {

// Define the friend test class
class WindowsAudioPluginTest {
 public:
  static void TestHandleMethodCall(WindowsAudioPlugin& plugin,
      const flutter::MethodCall<flutter::EncodableValue>& method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
    plugin.HandleMethodCall(method_call, std::move(result));
  }
};

// Mock class for flutter::MethodResult
class MockMethodResult : public flutter::MethodResult<flutter::EncodableValue> {
 public:
  MockMethodResult() : flutter::MethodResult<flutter::EncodableValue>() {}

  void SuccessInternal(const flutter::EncodableValue* result) override {
   
  }

  void ErrorInternal(const std::string& error_code,
                     const std::string& error_message,
                     const flutter::EncodableValue* details) override {

  }

  void NotImplementedInternal() override {

  }
};

// Example test case
TEST(WindowsAudioPlugin, HandleMethodCallLoad) {
  WindowsAudioPlugin plugin;
  auto result = std::make_unique<MockMethodResult>();
  auto args = std::make_unique<flutter::EncodableValue>(flutter::EncodableValue("test_audio.mp3"));
  flutter::MethodCall<flutter::EncodableValue> method_call("load", std::move(args));

  WindowsAudioPluginTest::TestHandleMethodCall(plugin, method_call, std::move(result));
}

}  // namespace windows_audio
