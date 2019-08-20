#include "NEPOSound.h"

static int NEPOSoundVolume = 100;

void SetVolume(int volume) {
    NEPOSoundVolume = volume;
}

int GetVolume() {
    return NEPOSoundVolume;
}

void PlaySystemSound (int soundName) {
    PlaySoundEx(soundName, NEPOSoundVolume);
}

void NEPOPlayTone (unsigned short frequency, unsigned short duration) {
    PlayToneEx(frequency, duration, NEPOSoundVolume);
    Wait(duration);
}
