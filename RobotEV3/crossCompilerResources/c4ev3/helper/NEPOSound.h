#ifndef NEPOSOUND
#define NEPOSOUND

#include "NEPODefs.h"

void SetVolume(int volume);

int GetVolume();

void PlaySystemSound (int soundName);

void NEPOPlayTone (unsigned short frequency, unsigned short duration);

#endif
