#ifndef MYCONSOLE_H_INCLUDED
#define MYCONSOLE_H_INCLUDED

#define _WIN32_WINNT 0x0601
#include <windows.h>

void Init_Console();
void Set_Console_Title(char *FTitle);
void Set_Console_Buffer_Sizes(int FWidth, int FHeight);
void Set_Console_FullScreen();
void Set_Console_Cursor_Position(int FX, int FY);

const unsigned char FOREGROUND_BLACK = 0;
const unsigned char BACKGROUND_BLACK = 0;

const unsigned char FCN = FOREGROUND_BLACK;
const unsigned char FCR = FOREGROUND_RED;
const unsigned char FCG = FOREGROUND_GREEN;
const unsigned char FCB = FOREGROUND_BLUE;
const unsigned char FCY = FOREGROUND_RED   | FOREGROUND_GREEN;
const unsigned char FCC = FOREGROUND_GREEN | FOREGROUND_BLUE;
const unsigned char FCM = FOREGROUND_BLUE  | FOREGROUND_RED;
const unsigned char FCW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

const unsigned char FCIN = FOREGROUND_INTENSITY | FOREGROUND_BLACK;
const unsigned char FCIR = FOREGROUND_INTENSITY | FOREGROUND_RED;
const unsigned char FCIG = FOREGROUND_INTENSITY | FOREGROUND_GREEN;
const unsigned char FCIB = FOREGROUND_INTENSITY | FOREGROUND_BLUE;
const unsigned char FCIY = FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_GREEN;
const unsigned char FCIC = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;
const unsigned char FCIM = FOREGROUND_INTENSITY | FOREGROUND_BLUE  | FOREGROUND_RED;
const unsigned char FCIW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

const unsigned char BCN = BACKGROUND_BLACK;
const unsigned char BCR = BACKGROUND_RED;
const unsigned char BCG = BACKGROUND_GREEN;
const unsigned char BCB = BACKGROUND_BLUE;
const unsigned char BCY = BACKGROUND_RED   | BACKGROUND_GREEN;
const unsigned char BCC = BACKGROUND_GREEN | BACKGROUND_BLUE;
const unsigned char BCM = BACKGROUND_BLUE  | BACKGROUND_RED;
const unsigned char BCW = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

const unsigned char BCIN = BACKGROUND_INTENSITY | BACKGROUND_BLACK;
const unsigned char BCIR = BACKGROUND_INTENSITY | BACKGROUND_RED;
const unsigned char BCIG = BACKGROUND_INTENSITY | BACKGROUND_GREEN;
const unsigned char BCIB = BACKGROUND_INTENSITY | BACKGROUND_BLUE;
const unsigned char BCIY = BACKGROUND_INTENSITY | BACKGROUND_RED   | BACKGROUND_GREEN;
const unsigned char BCIC = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
const unsigned char BCIM = BACKGROUND_INTENSITY | BACKGROUND_BLUE  | BACKGROUND_RED;
const unsigned char BCIW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

void Set_Console_Text_Color(int FColor_Code);

void Clear_Console_Buffer();
void Write_To_Console_Buffer(int FX, int FY, int FColor_Code, char FCharacter);
void Write_Buffer_To_Console();

void Get_Mouse_xy(int* Fx, int*Fy);

void MySleep(int Fms);

#endif // MYCONSOLE_H_INCLUDED
