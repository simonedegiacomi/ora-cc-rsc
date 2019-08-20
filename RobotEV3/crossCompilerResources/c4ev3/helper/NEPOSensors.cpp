#include "NEPOSensors.h"

unsigned long long NEPOTimers[TIMERS_COUNT];

void NEPOSetAllSensors(SensorHandler * port1, SensorHandler * port2, SensorHandler * port3, SensorHandler * port4){
    DrawString("Initializing sensors", 1, 3);
    SetAllSensors(port1, port2, port3, port4);
    LcdClean();
}

void NEPOResetEV3GyroSensor(int port) {
    LcdClean();
    DrawString("Resetting Gyro " + ToString(port + 1), 3, 3);
    ResetEV3GyroSensor(port);
    LcdClean();
}

std::list<double> NEPOReadEV3ColorSensorRGB (int port) {
    RGB rgb = ReadEV3ColorSensorRGB(port);
    std::list<double> values;
    _setListElementByIndex(values, 0, colorComponentValueToPercentage(rgb.red));
    _setListElementByIndex(values, 1, colorComponentValueToPercentage(rgb.green));
    _setListElementByIndex(values, 2, colorComponentValueToPercentage(rgb.blue));
    return values;
}

std::list<double> _ReadIRSeekAllChannels (int port) {
    EV3IrSeekResult res = ReadEV3IrSensorSeek(port);
    std::list<double> valuesInList;
    for (int i = 0; i < EV3_IR_CHANNELS; i++) {
        int direction = res.directions[i];
        int distance = res.distances[i];
        if (distance == 128) { // no beacon for this channel
            valuesInList.push_back(0);
            valuesInList.push_back(HUGE_VAL);
        } else {
            valuesInList.push_back(direction);
            valuesInList.push_back(distance);
        }
    }
    return valuesInList;
}

std::list<double> NEPOReadHTColorSensorV2RGB (int port) {
    RGBA rgba = ReadHTColorSensorV2RGBA(port, HTColorSensorDefaultMode);
    std::list<double> values;
    _setListElementByIndex(values, 0, colorComponentValueToPercentage(rgba.red));
    _setListElementByIndex(values, 1, colorComponentValueToPercentage(rgba.green));
    _setListElementByIndex(values, 2, colorComponentValueToPercentage(rgba.blue));
    return values;
}

double NEPOReadHTColorSensorV2Light (int port) {
    RGBA rgba = ReadHTColorSensorV2RGBA(port, HTColorSensorDefaultMode);
    return colorComponentValueToPercentage(rgba.white);
}

double NEPOReadHTColorSensorV2AmbientLight (int port) {
    RGBA rgba = ReadHTColorSensorV2RGBA(port, HTColorSensorPassiveMode);
    double light = (rgba.white * 100.0) / 38200.0;
    return std::max(light, 100.0);
}

void ResetTimer (int stopwatch) {
    NEPOTimers[stopwatch] = TimerGetMS();
}

unsigned long long GetTimerValue (int stopwatch) {
    return TimerGetMS() - NEPOTimers[stopwatch];
};
