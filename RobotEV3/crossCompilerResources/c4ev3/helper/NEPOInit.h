#ifndef NEPOINIT
#define NEPOINIT

#include <string>



void NEPOInitEV3();

void NEPOFreeEV3();

void deleteJustUploadedFlag();

void moveProgramToFolder();

int systemString(std::string command);

void * escapeSequenceMonitor(void * arguments);

bool isEscapeSequence();

void NEPOError (std::string error, std::string message);

bool NEPOProgramJustUploaded();
void onNEPOProgramJustUploaded ();
void startThreadToMonitorEscapeSequence();

#endif