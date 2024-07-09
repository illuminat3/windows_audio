# windows_audio

A simple windows audio plugin for flutter

## Implementation

Add the flutter plugin to your pubspec.yaml file

```yaml
dependencies:
  windows_audio: ^0.0.1
```

Then create an instance of the player

```dart
final Player = WindowsAudio();
```

Finally load the audio and play it

```dart
Player.load("path/to/audio");
Player.play();
```

This supports wav, mp3 and ogg files.
