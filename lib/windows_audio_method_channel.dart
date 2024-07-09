import 'package:flutter/services.dart';
import 'package:logging/logging.dart';
import 'windows_audio_platform_interface.dart';

class MethodChannelWindowsAudio extends WindowsAudioPlatform {
  final MethodChannel _channel = const MethodChannel('windows_audio');
  final Logger _logger = Logger('MethodChannelWindowsAudio');

  MethodChannelWindowsAudio() {
    _setupLogging();
  }

  void _setupLogging() {
    Logger.root.level = Level.ALL;
  }

  @override
  Future<void> load(String filePath) async {
    try {
      await _channel.invokeMethod('load', filePath);
    } on PlatformException catch (e) {
      _logger.severe("Failed to load audio: '${e.message}'.");
    }
  }

  @override
  Future<void> play() async {
    try {
      await _channel.invokeMethod('play');
    } on PlatformException catch (e) {
      _logger.severe("Failed to play audio: '${e.message}'.");
    }
  }
}
