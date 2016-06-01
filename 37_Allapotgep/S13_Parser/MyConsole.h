#ifndef MYCONSOLE_H_INCLUDED
#define MYCONSOLE_H_INCLUDED

#define _WIN32_WINNT 0x0601

#include <windows.h>

static inline void Set_Console_FullScreen()
{
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
}

static inline void Set_Console_Buffer_Sizes(int FWidth, int FHeight)
{
    COORD c={
        FWidth,
        FHeight
    };

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

static inline void Set_Console_Cursor_Position(int FX, int FY)
{
    COORD c={
        FX,
        FY
    };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

#define FOREGROUND_BLACK 0
#define BACKGROUND_BLACK 0

#define FCN FOREGROUND_BLACK
#define FCR FOREGROUND_RED
#define FCG FOREGROUND_GREEN
#define FCB FOREGROUND_BLUE
#define FCY FOREGROUND_RED   | FOREGROUND_GREEN
#define FCC FOREGROUND_GREEN | FOREGROUND_BLUE
#define FCM FOREGROUND_BLUE  | FOREGROUND_RED
#define FCW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

#define FCIN FOREGROUND_INTENSITY | FOREGROUND_BLACK
#define FCIR FOREGROUND_INTENSITY | FOREGROUND_RED
#define FCIG FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define FCIB FOREGROUND_INTENSITY | FOREGROUND_BLUE
#define FCIY FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_GREEN
#define FCIC FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE
#define FCIM FOREGROUND_INTENSITY | FOREGROUND_BLUE  | FOREGROUND_RED
#define FCIW FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

#define BCN BACKGROUND_BLACK
#define BCR BACKGROUND_RED
#define BCG BACKGROUND_GREEN
#define BCB BACKGROUND_BLUE
#define BCY BACKGROUND_RED   | BACKGROUND_GREEN
#define BCC BACKGROUND_GREEN | BACKGROUND_BLUE
#define BCM BACKGROUND_BLUE  | BACKGROUND_RED
#define BCW BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE

#define BCIN BACKGROUND_INTENSITY | BACKGROUND_BLACK
#define BCIR BACKGROUND_INTENSITY | BACKGROUND_RED
#define BCIG BACKGROUND_INTENSITY | BACKGROUND_GREEN
#define BCIB BACKGROUND_INTENSITY | BACKGROUND_BLUE
#define BCIY BACKGROUND_INTENSITY | BACKGROUND_RED   | BACKGROUND_GREEN
#define BCIC BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE
#define BCIM BACKGROUND_INTENSITY | BACKGROUND_BLUE  | BACKGROUND_RED
#define BCIW BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE

static inline void Set_Console_Text_Color(int FColor_Code)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FColor_Code);
}

static inline void MySleep(int Fms)
{
    Sleep(Fms);
}

#endif // MYCONSOLE_H_INCLUDED