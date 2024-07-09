import 'package:flutter_test/flutter_test.dart';
import 'package:windows_audio/windows_audio.dart';
import 'package:windows_audio/windows_audio_platform_interface.dart';
import 'package:windows_audio/windows_audio_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockWindowsAudioPlatform
    with MockPlatformInterfaceMixin
    implements WindowsAudioPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final WindowsAudioPlatform initialPlatform = WindowsAudioPlatform.instance;

  test('$MethodChannelWindowsAudio is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelWindowsAudio>());
  });

  test('getPlatformVersion', () async {
    WindowsAudio windowsAudioPlugin = WindowsAudio();
    MockWindowsAudioPlatform fakePlatform = MockWindowsAudioPlatform();
    WindowsAudioPlatform.instance = fakePlatform;

    expect(await windowsAudioPlugin.getPlatformVersion(), '42');
  });
}
