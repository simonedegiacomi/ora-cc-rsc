#ifndef NEPOLOG
#define NEPOLOG

#include <cstdint>
#include "NEPODefs.h"

void startLoggingThread(uint8_t motorPorts);

void *loggingLoop(void *arguments);

void logMotors(uint8_t usedMotorPorts);

bool isMotorPortUsed(uint8_t usedMotorPorts, uint8_t motorPort);

void logMotor(char portName, uint8_t port);

void logSensors();

void logSensor(int port);

std::string readSensorAsString(int port, SensorHandler *sensor);

std::string readEV3TouchSensorAsString(int port);
std::string readEV3GyroSensorAsString(int port);
std::string readEV3ColorSensorAsString(int port);
std::string readEV3IrSensorAsString(int port);
std::string readEV3UltrasonicSensorAsString(int port);
std::string readHTCompassSensorAsString(int port);
std::string readHTIrSensorAsString(int port);
std::string readNXTSoundSensorAsString(int port);
std::string readHTColorSensorV2AsString(int port);

#endif
