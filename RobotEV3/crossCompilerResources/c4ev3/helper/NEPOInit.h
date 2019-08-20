#ifndef NEPOINIT
#define NEPOINIT

#include <string>

void inline NEPOInitEV3();

void inline NEPOFreeEV3();

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