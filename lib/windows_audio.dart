import 'windows_audio_platform_interface.dart';

class WindowsAudio {
  Future<String?> getPlatformVersion() {
    return WindowsAudioPlatform.instance.getPlatformVersion();
  }

  Future<void> load(String filePath) {
    return WindowsAudioPlatform.instance.load(filePath);
  }

  Future<void> play() {
    return WindowsAudioPlatform.instance.play();
  }
}
