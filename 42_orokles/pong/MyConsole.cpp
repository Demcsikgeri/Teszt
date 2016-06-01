#include "MyConsole.h"

HANDLE hConsole;

int Console_Screen_Buffer_Width=0;
int Console_Screen_Buffer_Height=0;
PCHAR_INFO Console_Screen_Buffer=NULL;

void Init_Console()
{
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hStdin=GetStdHandle(STD_INPUT_HANDLE);
}

void Set_Console_Title(char *FTitle)
{
    SetConsoleTitle(FTitle);
}

void Set_Console_Buffer_Sizes(int FWidth, int FHeight)
{
    COORD c=
    {
        (short int) FWidth,
        (short int) FHeight
    };

    SetConsoleScreenBufferSize(hConsole,c);

    Console_Screen_Buffer_Width=FWidth;
    Console_Screen_Buffer_Height=FHeight;
    Console_Screen_Buffer=(PCHAR_INFO)realloc(Console_Screen_Buffer,sizeof(CHAR_INFO) * FWidth*FHeight);
}

void Set_Console_FullScreen()
{
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
}

void Set_Console_Cursor_Position(int FX, int FY)
{
    COORD c=
    {
        (short int) FX,
        (short int) FY
    };

    SetConsoleCursorPosition(hConsole,c);
}

void Set_Console_Text_Color(int FColor_Code)
{
    SetConsoleTextAttribute(hConsole, FColor_Code);
}

void Clear_Console_Buffer()
{
    memset(Console_Screen_Buffer,0,sizeof(CHAR_INFO)*Console_Screen_Buffer_Width*Console_Screen_Buffer_Height);
}

void Write_To_Console_Buffer(int FX, int FY, int FColor_Code, char FCharacter)
{
    PCHAR_INFO p=& Console_Screen_Buffer[FY*Console_Screen_Buffer_Width+FX];
    p->Char.AsciiChar=FCharacter;
    p->Attributes=FColor_Code;
}

void Write_Buffer_To_Console()
{
    COORD bufsize=
    {
        (short int) Console_Screen_Buffer_Width,
        (short int) Console_Screen_Buffer_Height
    };

    COORD bufpos=
    {
        (short int) 0,
        (short int) 0
    };

    SMALL_RECT destrect=
    {
        0,
        0,
        (short int)Console_Screen_Buffer_Width,
        (short int)Console_Screen_Buffer_Height
    };

    WriteConsoleOutput(
        hConsole,
        Console_Screen_Buffer,
        bufsize,
        bufpos,
        &destrect
    );
}

void MySleep(int Fms)
{
    Sleep(Fms);
}

void Get_Mouse_xy(int* Fx, int*Fy)
{
	/*CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
	CONSOLE_FONT_INFO cfi;
	BOOL bFont = GetCurrentConsoleFont(hConsole,0,&cfi);
	cfi.dwFontSize = GetConsoleFontSize(hConsole, cfi.nFont);

	int fx, fy;
	fx=cfi.dwFontSize.X;
	fy=cfi.dwFontSize.Y;

    POINT p;
	GetCursorPos(&p);
	HWND hWnd = GetConsoleWindow();
	ScreenToClient(hWnd,&p);
	x=p.x ;
	y=p.y ;

	int row,col;
	row=(int)x/fx;
	col =(int)y/fy;
	x=col;
	y=row;*/
}
