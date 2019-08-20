#ifndef NEPOSENSORS
#define NEPOSENSORS

#include "NEPODefs.h"

#define DEFAULT_MODE_COLOR      COL_COLOR
#define DEFAULT_MODE_GYRO       GYRO_ANG
#define DEFAULT_MODE_INFRARED   IR_PROX
#define DEFAULT_MODE_TOUCH      TOUCH_PRESS
#define DEFAULT_MODE_ULTRASONIC US_DIST_CM
#define DEFAULT_MODE_SOUND      NXT_SOUND_DB
#define DEFAULT_MODE_COMPASS    NXT_COMPASS_COMPASS
#define DEFAULT_MODE_IRSEEKER   NXT_IR_SEEKER_DC

#define TIMERS_COUNT 5

void NEPOSetAllSensors(SensorHandler *port1, SensorHandler *port2, SensorHandler *port3, SensorHandler *port4);

void NEPOResetEV3GyroSensor(int port);

std::list<double> NEPOReadEV3ColorSensorRGB(int port);

// TODO: Rename to NEPOReadIRSeekAllChannels to match convention
std::list<double> _ReadIRSeekAllChannels(int port);

Color NEPOReadHTColorSensorV2(int port);

std::list<double> NEPOReadHTColorSensorV2RGB(int port);

double NEPOReadHTColorSensorV2Light(int port);

double NEPOReadHTColorSensorV2AmbientLight(int port);

void ResetTimer(int stopwatch);

unsigned long long GetTimerValue(int stopwatch);

inline double colorComponentValueToPercentage(double value) {
    return ((value * 100.0) / 1023.0);
}


#endif
