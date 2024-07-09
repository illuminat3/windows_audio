import 'package:plugin_platform_interface/plugin_platform_interface.dart';
import 'windows_audio_method_channel.dart';

abstract class WindowsAudioPlatform extends PlatformInterface {
  WindowsAudioPlatform() : super(token: _token);

  static final Object _token = Object();

  static WindowsAudioPlatform _instance = MethodChannelWindowsAudio();

  static WindowsAudioPlatform get instance => _instance;

  static set instance(WindowsAudioPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  // In future find a way to get this from pubspec.yaml
  Future<String?> getPlatformVersion() async {
    return "1.0.0";
  }

  Future<void> load(String filePath) {
    throw UnimplementedError('load() has not been implemented.');
  }

  Future<void> play() {
    throw UnimplementedError('play() has not been implemented.');
  }
}
