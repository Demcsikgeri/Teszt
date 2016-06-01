#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
//#include <stdlib.h>
#include "MyConsole.h"

typedef struct
{
    int x;
    int y;
} SCoo;

typedef SCoo* PSCoo;

//typdef struct {

SCoo *kigyo=NULL;
int kigyo_meret=0;
SCoo irany;

//} SKigyo;

SCoo kaja;

const int screen_width=80;
const int screen_height=25;

void init_kigyo()
{
    kigyo=(PSCoo)malloc(1*sizeof(SCoo));
    kigyo_meret=1;

    kigyo->x=rand()%screen_width;
    kigyo->y=rand()%screen_height;

    irany.x=1;
    irany.y=0;
}

int rajta_van_e_a_kigyon(SCoo Coo)
{
    int i;
    for (i=0; i<kigyo_meret; i+=1)
        if ((kigyo[i].x==Coo.x) && (kigyo[i].y==Coo.y))
            return 1;

    return  0;
}

void kaja_random()
{
    do
    {
        kaja.x=rand()%screen_width;
        kaja.y=rand()%screen_height;
    }while(rajta_van_e_a_kigyon(kaja));
}

int lepes()
{
    if (
        (kigyo[kigyo_meret-1].x!=kigyo[kigyo_meret-2].x)
        ||
        (kigyo[kigyo_meret-1].y!=kigyo[kigyo_meret-2].y)
       )
    {
        Set_Console_Cursor_Position(kigyo[0].x, kigyo[0].y);
        printf(" ");

        int i;
        for (i=0; i<(kigyo_meret-1); i+=1)
        {
            kigyo[i].x=kigyo[i+1].x;
            kigyo[i].y=kigyo[i+1].y;
        }
    }

    SCoo fej_uj_helye;

    fej_uj_helye.x=kigyo[kigyo_meret-1].x+irany.x;
    fej_uj_helye.y=kigyo[kigyo_meret-1].y+irany.y;

    if (fej_uj_helye.x>=screen_width)
        fej_uj_helye.x=0;

    if (fej_uj_helye.x<0)
        fej_uj_helye.x=screen_width-1;

    if (fej_uj_helye.y>=screen_height)
        fej_uj_helye.y=0;

    if (fej_uj_helye.y<0)
        fej_uj_helye.y=screen_height-1;

    if (rajta_van_e_a_kigyon(fej_uj_helye))
        return 0;

    kigyo[kigyo_meret-1].x=fej_uj_helye.x;
    kigyo[kigyo_meret-1].y=fej_uj_helye.y;

    if (
        (kigyo[kigyo_meret-1].x==kaja.x)
        &&
        (kigyo[kigyo_meret-1].y==kaja.y)
    )
    {
        kigyo=(PSCoo)realloc(kigyo,(kigyo_meret+1)*sizeof(SCoo));
        kigyo_meret+=1;
        kigyo[kigyo_meret-1].x=kigyo[kigyo_meret-2].x;
        kigyo[kigyo_meret-1].y=kigyo[kigyo_meret-2].y;
        kaja_random();
    }

    return 1;
}

void iranyit()
{
    if (kbhit())
    {
        SCoo uj_irany;

        switch(getch())
        {
        case 'a':
        {
            uj_irany.x=-1;
            uj_irany.y=0;
            break;
        }
        case 's':
        {
            uj_irany.x=0;
            uj_irany.y=1;
            break;
        }
        case 'd':
        {
            uj_irany.x=1;
            uj_irany.y=0;
            break;
        }
        case 'w':
        {
            uj_irany.x=0;
            uj_irany.y=-1;
            break;
        }
        }

        if (
            (irany.x+uj_irany.x)!=0
            ||
            (irany.y+uj_irany.y)!=0
        )
            irany=uj_irany;
    }
}

void kirajzol()
{
    Set_Console_Cursor_Position(kaja.x,kaja.y);
    Set_Console_Text_Color(FCIR | BCN);
    printf("*");

    Set_Console_Text_Color(FCIG | BCN);
    int i;
    for(i=0; i<(kigyo_meret-1); i+=1)
    {
        Set_Console_Cursor_Position(kigyo[i].x,kigyo[i].y);
        printf("%c",254);
    }

    Set_Console_Text_Color(FCIM | BCN);
    Set_Console_Cursor_Position(kigyo[kigyo_meret-1].x,kigyo[kigyo_meret-1].y);
    printf("%c",2);
}

int main()
{
    srand(time(NULL));

    init_kigyo();
    kaja_random();

    while(1)
    {
        iranyit();
        if (lepes()==0)
        {
            exit(1);
        }
        kirajzol();
        MySleep(100);
    }

    return 0;
}
