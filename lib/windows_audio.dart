import 'windows_audio_platform_interface.dart';
import 'package:flutter/foundation.dart';

class WindowsAudio {
  Future<String?> getPlatformVersion() {
    return WindowsAudioPlatform.instance.getPlatformVersion();
  }

  Future<void> load(String filePath) {
    if (kReleaseMode) {
      filePath = "data/flutter_assets/$filePath";
    }
    return WindowsAudioPlatform.instance.load(filePath);
  }

  Future<void> play() {
    return WindowsAudioPlatform.instance.play();
  }
}
