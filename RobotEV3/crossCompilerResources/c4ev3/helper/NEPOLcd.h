#ifndef NEPOLCD
#define NEPOLCD

#include "NEPOColors.h"
#include "NEPOPictures.h"

void SetCursorColumn(int column);

void SetCursorRow(int row);

void DrawString(std::string str, int column, int row);

#endif
