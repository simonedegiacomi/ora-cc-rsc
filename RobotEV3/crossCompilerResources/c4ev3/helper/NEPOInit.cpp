#include <ev3.h>
#include "NEPOInit.h"
#include "NEPOLcd.h"

#define POOL_ESCAPE_SEQUENCE 100

#define INSTALLER_FOLDER "../prjs/BrkProg_SAVE"
#define PROJECTS_FOLDER "../prjs"
#define JUST_UPLOADED_FLAG_FILE_NAME "../prjs/BrkProg_SAVE/NEPO-just-uploaded.txt"

bool initialized = false;

void inline NEPOInitEV3 () {
    if (initialized) {
        return;
    }
    initialized = true;
    InitEV3();
    if (NEPOProgramJustUploaded()) {
        onNEPOProgramJustUploaded();
    }
    startThreadToMonitorEscapeSequence();
    SetLedPattern(LED_GREEN_PULSE);
}

void inline NEPOFreeEV3 () {
    SetLedPattern(LED_GREEN);
    FreeEV3();
    exit(0);
}

bool NEPOProgramJustUploaded () {
    return access(JUST_UPLOADED_FLAG_FILE_NAME, F_OK) == 0;
}


void onNEPOProgramJustUploaded () {
    PlaySound(SOUND_DOUBLE_BEEP);
    deleteJustUploadedFlag();
    moveProgramToFolder();
    NEPOFreeEV3();
}

void deleteJustUploadedFlag() {
    remove(JUST_UPLOADED_FLAG_FILE_NAME);
}

/**
 * Copied the program (executable .elf + launcher .rbf) to a folder with the same name as the program,
 * to allow the user to delete theprogram.
 */
void moveProgramToFolder() {
    std::string programName = PROGRAM_NAME;
    std::string projectsFolder = PROJECTS_FOLDER;
    std::string installerfolder = INSTALLER_FOLDER;
    std::string programFolder = projectsFolder + "/" + programName;

    systemString("mkdir -p " + programFolder);
    systemString("mv " + installerfolder + "/" + programName + ".elf " + programFolder + "/" + programName + ".elf");
    systemString("mv " + installerfolder + "/" + programName + ".tmp " + programFolder + "/" + programName + ".rbf");
    systemString("rm " + installerfolder + "/" + programName + ".rbf");
}

int inline systemString (std::string command) {
    return system(command.c_str());
}

void startThreadToMonitorEscapeSequence () {
    pthread_t threadId;
    pthread_create(&threadId, NULL, escapeSequenceMonitor, NULL);
}

void * escapeSequenceMonitor (void * arguments) {
    while (!isEscapeSequence()) {
        Wait(POOL_ESCAPE_SEQUENCE);
    }
    NEPOFreeEV3();
    initialized = false;
    return NULL;
}

bool isEscapeSequence () {
    return ButtonIsDown(BTNCENTER) && ButtonIsDown(BTNDOWN);
}

void NEPOError (std::string error, std::string message) {
    SetLedPattern(LED_RED);
    LcdClean();
    DrawString("ERROR", 8, 2);
    DrawString(error.c_str(), 10 - (error.length() / 2), 4);
    DrawString(message.c_str(), 0, 8);
    DrawString("CENTER + DOWN to exit", 1, 11);
    PlaySystemSound(SOUND_LOW_BEEP);
    while(true) {
        Wait(1000);
    }
}
