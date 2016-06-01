#include <stdio.h>
#include <conio.h>
#include "MyConsole.h"
#include "../S13_generator/Szinek.h"


enum nev
{
    semmi,
    x,
    y,
    szinez
};

int gx=0;
int gy=0;

void jobbra_lep()
{
    gx+=1;
}
void balra_lep()
{
    gx-=1;
}
void lefele_lep()
{
    gy+=1;
}
void felfele_lep()
{
    gy-=1;
}
void kiir(char c)
{
    Set_Console_Cursor_Position(gx,gy);
    printf("%c",c);
}
void ugrik(int x, int y)
{
    gx=x;
    gy=y;
}

int main()
{
    FILE *f=fopen("c:\\Users\\Lukas\\Dropbox\\SZFe_2014\\prog\\c_strukturalt\\37_Allapotgep\\S13_generator\\smiley.S13","r");

    if (f==NULL)
    {
        return 1;
    }

    //allapotgep

    int allapot=semmi;
    int x_coo;
    int y_coo;

    while (!feof(f))
    {
        char c=fgetc(f);

        switch (allapot)
        {
        case semmi:
        {
            switch (c)
            {
            case 'U':
                allapot=x;
                x_coo=0;
                break;
            case 'J':
                jobbra_lep();
                break;
            case 'B':
                balra_lep();
                break;
            case 'L':
                lefele_lep();
                break;
            case 'F':
                felfele_lep();
                break;
            case 'S':
                allapot=szinez;
                break;
            default :
                kiir(c);
                break;
            }
            break;
        }
        case x:
        {
            switch(c)
            {
            case ';':
            {
                allapot=y;
                y_coo=0;
                break;
            }

            case '0': //0-2
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                x_coo=(x_coo*10)+(c-48);
                break;
            }
            case ' ':
            case '\t':
                break;
            default:
                allapot=semmi;
                break;
            }
            break;
        }
        case y:
        {
            switch(c)
            {
            case '0': //0-2
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                y_coo=(y_coo*10)+(c-48);
                break;
            }
            case ' ':
            case '\t':
                break;
            default:
                allapot=semmi;
                ugrik(x_coo,y_coo);
                break;
            }
            break;
        }
        case szinez:
        {
            switch (c-48)
            {
                case feher: Set_Console_Text_Color(FCIW | BCN);break;
                case piros: Set_Console_Text_Color(FCIR | BCN);break;
                case zod: Set_Console_Text_Color(FCIG | BCN);break;
                case kek: Set_Console_Text_Color(FCIB | BCN);break;
            }
            allapot=semmi;
            break;
        }
        }
    }


    getch();

    return 0;
}
