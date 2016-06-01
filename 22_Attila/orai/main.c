#include <stdio.h>
#include <stdlib.h>
#include "MyConsole.h"

char tomb[50][50];

void nulla(){
    int i,dzs;

    for (i=0; i<50;i+=1)
        for (dzs=0; dzs<50; dzs+=1)
            tomb[i][dzs]=0;
}

int xyervenyese(int x, int y)
{
    return (x<50 && x>-1 && y<50 && y>=0);
}

void genkarxy(int x, int y)
{
    tomb[y][x]=(rand()%('z'-'a'))+'a';
    Set_Console_Cursor_Position(x,y);
    printf("%c",tomb[y][x]);
}

int act_x;
int act_y;

void berak(int x, int y, char mit)
{
    tomb[y][x]=mit;
    Set_Console_Cursor_Position(x,y);
    printf("%c",tomb[y][x]);
}

void lep()
{
    // 0=fel
    // 1=le
    // 2=jobbra
    // 3=balra


    switch (rand()%4)
    {
        case 0: {
            if (act_y>0)
            if (tomb[act_y-1][act_x]==0)
            {
                berak(act_x,act_y,'*');
                act_y-=1;
                return;
            }

            break;
        }
        case 1: {
            if (act_y<49)

            if (tomb[act_y+1][act_x]==0)
            {
                berak(act_x,act_y,'*');
                act_y+=1;
                return;
            }

            break;
        }
        case 2: {

            if (act_x<49)

            if (tomb[act_y][act_x+1]==0)
            {
                berak(act_x,act_y,'*');
                act_x+=1;
                return;
            }

            break;
        }
        case 3: {
            if (act_x>0)

            if (tomb[act_y][act_x-1]==0)
            {
                berak(act_x,act_y,'*');
                act_x-=1;
                return;
            }

            break;
        }
    }
}

int main()
{
    nulla();

    act_x=0;
    act_y=0;

    int x;int y;

    while (1)
    {
        lep();
        MySleep(500);
    }

    Set_Console_Cursor_Position(15,6);
    Set_Console_Text_Color(FCIY | BCIM);

    printf("Hello world!\n");
    getch();
    return 0;
}
