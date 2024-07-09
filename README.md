# windows_audio

A simple [windows audio plugin](https://pub.dev/packages/windows_audio) for flutter

## Implementation

Add the flutter plugin to your pubspec.yaml file

```yaml
dependencies:
  windows_audio: ^1.0.0
```

Firstly, import the flutter plugin

```dart
import "package:windows_audio/windows_audio.dart";
```

Then create an instance of the player

```dart
final Player = WindowsAudio();
```

Finally load the audio and play it

```dart
Player.load("assets/audio/filename");
Player.play();
```

Make sure that you have added the audio to the pubspec.yaml file

```yaml
assets:
 - assets/audio/filename
```

This plugin supports wav, mp3 and ogg files.
