import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'windows_audio_platform_interface.dart';

/// An implementation of [WindowsAudioPlatform] that uses method channels.
class MethodChannelWindowsAudio extends WindowsAudioPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('windows_audio');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
