#ifndef NEPOTTS
#define NEPOTTS

#include <sys/types.h>
#include <sys/wait.h>
#include "NEPODefs.h"


void SetLanguage(std::string toSet);

inline void Say (std::string text, int speed, int pitch);

inline int generateAudioFile (std::string text, int speed, int pitch);

std::string mapSpeedToEspeakParameter(int speed);
std::string mapPitchToEspeakParameter(int pitch);

#endif
