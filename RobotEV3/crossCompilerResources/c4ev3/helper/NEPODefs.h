#include <string>
#include <ev3.h>

#include "NEPOColors.h"
#include "NEPOStrings.h"
#include "NEPOMath.h"
#include "NEPOMotors.h"
#include "NEPOLcd.h"
#include "NEPOSensors.h"
#include "NEPOSound.h"
#include "NEPOLists.h"
#include "NEPOInit.h"
#include "NEPOTTS.h"
#include "NEPOBluetooth.h"
#include "NEPOLog.h"

template<typename T, typename U>
void assertNepo(bool test, std::string text, T left, std::string op, U right);
