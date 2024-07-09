import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'windows_audio_method_channel.dart';

abstract class WindowsAudioPlatform extends PlatformInterface {
  /// Constructs a WindowsAudioPlatform.
  WindowsAudioPlatform() : super(token: _token);

  static final Object _token = Object();

  static WindowsAudioPlatform _instance = MethodChannelWindowsAudio();

  /// The default instance of [WindowsAudioPlatform] to use.
  ///
  /// Defaults to [MethodChannelWindowsAudio].
  static WindowsAudioPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [WindowsAudioPlatform] when
  /// they register themselves.
  static set instance(WindowsAudioPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
