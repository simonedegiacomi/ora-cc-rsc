#include "NEPOLcd.h"

#define LCD_COLOR_BLACK 1
#define DEFAULT_FONT_CHARACTER_HEIGHT 10
#define DEFAULT_FONT_CHARACTER_WIDTH 8

void SetCursorColumn (int column) {
    if (column < 0) {
        column = 0;
    }
    SetCursorX(column * DEFAULT_FONT_CHARACTER_WIDTH);
}

void SetCursorRow (int row) {
    if (row < 0) {
        row = 0;
    }
    SetCursorY(row * DEFAULT_FONT_CHARACTER_HEIGHT);
}

void DrawString (std::string str, int column, int row) {
    SetCursorColumn(column);
    SetCursorRow(row);
    LcdPrintf(LCD_COLOR_BLACK, "%s", str.c_str());
}
