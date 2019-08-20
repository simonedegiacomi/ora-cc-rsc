#ifndef NEPOBLUETOOTH
#define NEPOBLUETOOTH

#include "NEPODefs.h"

#define BLUETOOTH_STRING_MESSAGE_MAX_LENGTH 128


BluetoothConnectionHandle NEPOConnectTo(std::string name);

void NotifyBluetoothNameNotFoundError();

BluetoothConnectionHandle NEPOWaitConnection();

void NEPOSendStringTo(BluetoothConnectionHandle to, std::string string);

std::string NEPOReceiveStringFrom(BluetoothConnectionHandle from);

void NotifyBluetoothNameNotFoundError();

#endif