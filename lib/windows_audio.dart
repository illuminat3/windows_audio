
import 'windows_audio_platform_interface.dart';

class WindowsAudio {
  Future<String?> getPlatformVersion() {
    return WindowsAudioPlatform.instance.getPlatformVersion();
  }
}
