#include "NEPOMotors.h"


void RotateMotorForAngleWithTurn(int outputs, float speed, float angle, float turn) {
    // If the rotate block is placed right after a motor block, the rotation won't be executed,
    // since the wheels are already spinning and the encoder values change
    Off(outputs);
    Wait(100);

    if (angle < 0) {
        speed *= -1;
        angle *= -1;
    }
    RotateMotorEx(outputs, speed, angle, turn, true, true);
}

void RotateMotorForAngle(int outputs, float speed, float angle) {
    RotateMotorForAngleWithTurn(outputs, speed, angle, 0);
}


void SteerDrive(int portLeft, int portRight, float speedLeft, float speedRight) {
    OnFwdReg(portLeft, speedLeft);
    OnFwdReg(portRight, speedRight);
}

void StopSteer (int portLeft, int portRight) {
    Off(portLeft);
    Off(portRight);
}

void SteerDriveForDistance(int portLeft, int portRight, float speedLeft, float speedRight, float distance) {
    float outerCircumference = computeOuterCircumferenceForSteerDrive(speedLeft, speedRight, distance);
    float angle = computeAngleForSteerDrive(outerCircumference);
    SteerDrive(portLeft, portRight, speedLeft, speedRight);
    WaitSteerDriveToReachAngle(portLeft, portRight, speedLeft, speedRight, angle);
    StopSteer(portLeft, portRight);
}

float computeOuterCircumferenceForSteerDrive (float speedLeft, float speedRight, float distance) {
    if (speedLeft + speedRight == 0) {
        return distance;
    } else if (abs(speedLeft) > abs(speedRight)) {
        return speedLeft / (speedRight + speedLeft) * 2.0 * distance;
    } else {
        return speedRight / (speedRight + speedLeft) * 2.0 * distance;
    }
}

float computeAngleForSteerDrive (float outerCircumference) {
    return abs(outerCircumference * 360.0 / (M_PI * WHEEL_DIAMETER));
}

void WaitSteerDriveToReachAngle(int portLeft, int portRight, float speedLeft, float speedRight, int angle) {
    if (abs(speedLeft) < abs(speedRight)) {
        WaitMotorToReachAngle(portRight, speedRight, angle);
    } else {
        WaitMotorToReachAngle(portLeft, speedLeft, angle);
    }
}

void WaitMotorToReachAngle(int motorPort, float speed, int angle) {
    int start = MotorRotationCount(motorPort);
    int targetEnd = start + (speed > 0 ? angle : -angle);
    if (speed > 0) {
        while(MotorRotationCount(motorPort) < targetEnd) {
            Wait(1);
        }
    } else {
        while(MotorRotationCount(motorPort) > targetEnd) {
            Wait(1);
        }
    }
}
