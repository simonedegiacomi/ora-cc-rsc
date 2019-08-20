#ifndef NEPOMOTORS
#define NEPOMOTORS

#include <algorithm>
#include "NEPODefs.h"

#define SPEED_MAX 100

inline int Speed(int speed) {
    return std::max(-SPEED_MAX, std::min(speed, SPEED_MAX));
}

/**
 * RotateMotor of c4ev3, called with a negative angle, will behave as if the angle was positive.
 * This function will run the motor in reverse if the angle is negative.
*/
void RotateMotorForAngleWithTurn(int outputs, float speed, float angle, float turn);

void RotateMotorForAngle(int outputs, float speed, float angle);

void SteerDrive(int portLeft, int portRight, float speedLeft, float speedRight);

void StopSteer (int portLeft, int portRight);

void SteerDriveForDistance(int portLeft, int portRight, float speedLeft, float speedRight, float distance);

void WaitSteerDriveToReachAngle(int portLeft, int portRight, float speedLeft, float speedRight, int angle);

void WaitMotorToReachAngle(int motorPort, float speed, int angle);

float computeOuterCircumferenceForSteerDrive (float speedLeft, float speedRight, float distance);
float computeAngleForSteerDrive (float outerCircumference);

#endif
