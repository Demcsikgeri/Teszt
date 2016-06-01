#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MyConsole.h"
//typedef unsigned char usc;
typedef int tt[3];

// Változók
int FIELDS[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int countPlayer, actPlayer, round = 0, winner = 0, GX = 34, GY = 9;

// Függvények
void Clean()
{
    system("CLS");
    DrawGrid(GX,GY);
    Refresh(GX,GY);
    Set_Console_Cursor_Position(0,0);
}

void ClearFields(tt *fFIELDS) // 2d soronként 3 elem
{
    int y,x;

    for(y = 0; y < 3; y = y +1)
        for(x = 0; x < 3; x = x +1)
            fFIELDS[y][x] = 0;

}             // 1. feladat

void Announce(int winner)
{
    Set_Console_Text_Color(14);
    Set_Console_Cursor_Position(GX-4,GY+10);
    switch(winner)
    {
    case 0:
        printf("Dontetlen");
        break;
    case 1:
        printf("1. jatekos nyert");
        break;
    case 2:
        printf("2. jatekos nyert");
        break;
    }
    Set_Console_Text_Color(7);

}     // 1/b feladat
void DrawGrid(int y6, int x6)

{
    //ertek

    Set_Console_Text_Color(14);

    Set_Console_Cursor_Position(y6,x6-1);
    printf(" A B C");

    Set_Console_Cursor_Position(y6-1,x6+1);
    printf("1");

    Set_Console_Cursor_Position(y6-1,x6+3);
    printf("2");

    Set_Console_Cursor_Position(y6-1,x6+5);
    printf("3");




    //tabla
    Set_Console_Cursor_Position(y6,x6);
    printf("%c%c%c%c%c%c%c",201,205,203,205,203,205,187);

    Set_Console_Cursor_Position(y6,x6+1);
    printf("%c %c %c %c",186,186,186,186);

    Set_Console_Cursor_Position(y6,x6+2);
    printf("%c%c%c%c%c%c%c",204,205,206,205,206,205,185);

    Set_Console_Cursor_Position(y6,x6+3);
    printf("%c %c %c %c",186,186,186,186);

    Set_Console_Cursor_Position(y6,x6+4);
    printf("%c%c%c%c%c%c%c",204,205,206,205,206,205,185);

    Set_Console_Cursor_Position(y6,x6+5);
    printf("%c %c %c %c",186,186,186,186);

    Set_Console_Cursor_Position(y6,x6+6);
    printf("%c%c%c%c%c%c%c",200,205,202,205,202,205,188);

}
int CheckWin(tt* t)   // 2. feladat
{
    int i,z,nyertes;

    for(z=0; z<3; z++)
    {
        nyertes = 0;
        for(i=0; i<3; i++)
        {
            nyertes = nyertes + t[z][i];
            if(nyertes == 3)
            {
                return 2;
            }
            else if(nyertes == -3) return 1;
        }
    }
    for(z=0; z<3; z++)
    {
        nyertes = 0;
        for(i=0; i<3; i++)
        {

            nyertes = nyertes + t[i][z];

        }
        if(nyertes == -3)
        {
            return 1;
        }
        else if(nyertes == 3) return 2;
    }
    if((t[0][0]+t[1][1]+t[2][2])==3)
    {
        return 2;
    }
    else if((t[0][0]+t[1][1]+t[2][2])==-3)
    {
        return 1;
    }
    else if((t[2][0]+t[1][1]+t[0][2])==3)
    {
        return 2;
    }
    else if((t[2][0]+t[1][1]+t[0][2])==-3)
    {
        return 1;
    }
    return 0;

}               // 3. feladat
void Refresh(int GX, int GY)
{
    int i,j;
    for(i=0; i<3; i=i+1)
    {
        for(j=0; j<3; j=j+1)
        {
            Set_Console_Cursor_Position((GX+1)+i*2,(GY+1)+j*2);
            // printf("%i",FIELDS[i][j]);
            switch(FIELDS[j][i])
            {
            case -1:
                Set_Console_Text_Color(9);
                printf("x");
                break;
            case  0:
                printf(" ");
                break;
            case  1:
                Set_Console_Text_Color(10);
                printf("o");
                break;
            }
        }
        Set_Console_Text_Color(7);
    }


}  // 4. feladat
int GetPlayer(int actPlayer)
{
    int y,ok=0,i;
    char x;

    Set_Console_Cursor_Position(0,0);
    do
    {
        Set_Console_Text_Color(14);
        printf("Add meg a koordinatat!\n");
        scanf("%c%d",&x,&y);
        x=x-97;
        y=y-1;
        if (FIELDS[y][x]==0 && x>=0 && x<3 && y>=0 && y<3)
        {
            if (actPlayer==1)
            {
                FIELDS[y][x]=-1;
            }
            else
            {
                FIELDS[y][x]=1;
            }
            ok=1;
        }
        Clean();
    }
    while (ok==0);

}
// 5. feladat
void GetAI(int actPlayer)
{
    int x,y,ok=0;
    //srand(time(NULL));
    do
    {
        x=rand()%3;
        y=rand()%3;
        if(FIELDS[x][y]==0)
        {
            if(actPlayer==1)
            {
                FIELDS[x][y]=-1;

            }
            else
            {
                FIELDS[x][y]=1;
            }
            ok=1;
        }

    }
    while(ok!=1);
    MySleep(500);
}
// 6. feladat
int GetPlayerNumber()
{
    int jatekosokszama;
    Set_Console_Cursor_Position(0,0);
    printf("Hany jatekos jatszon? (0-1-2)\n");
    scanf("%i", &jatekosokszama);
    while(jatekosokszama>2 || jatekosokszama<0)
    {
        printf("Nem jo szamot adtal meg! Ird be ujra!\n");
        scanf("%i", &jatekosokszama);
    }
    Clean();
    return jatekosokszama;
}        // 7. feladat

int main()
{
    srand(time(NULL));

    do
    {
        Clean();
        actPlayer = 1;
        round = 0;
        DrawGrid(GX, GY);
        ClearFields(FIELDS);
        countPlayer = GetPlayerNumber();
        do
        {
            switch(countPlayer)
            {
            case 0 :
            {
                GetAI(actPlayer);
                break;
            }
            case 1 :
            {
                if(actPlayer == 1)
                {
                    GetPlayer(actPlayer);
                }
                else
                {
                    GetAI(actPlayer);
                }
                break;
            }
            case 2 :
            {
                GetPlayer(actPlayer);
                break;
            }
            }
            round = round +1;
            actPlayer = ((actPlayer)%2) + 1;

            Refresh(GX,GY);
            winner = CheckWin(FIELDS);
        }
        while(round < 9 && winner == 0);

        Announce(winner);

    }
    while(getch() != 'x');
    return 0;
}
