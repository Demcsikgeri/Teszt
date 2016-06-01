#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

typedef struct
{
    int szulev;
    char nev[30];
    int gyerszam;
} SEmber;

typedef SEmber *PSEmber;

void SEmber_kiir(PSEmber Ember)
{
    printf("%i\r\n",Ember->szulev);
    printf("%s\r\n",(*Ember).nev);
    printf("%i\r\n",Ember->gyerszam);
}

int main()
{
    SEmber e[3]=
    {
        {
            1981,
            "Hello World!",
            5
        },
        {
            1969,
            "John Doe",
            112
        },
        {
            1919,
            "Test Elek"
            ,
            0
        }
    };

    SEmber_kiir(&e[1]);

    printf("%i\r\n",sizeof(SEmber));
    printf("%i\r\n",sizeof(e));
    printf("%i\r\n",sizeof(PSEmber));

    printf("%x\r\n",&e[1]);
    printf("%x\r\n",&e[1].szulev);
    printf("%x\r\n",&e[1].nev);
    printf("%x\r\n",&e[1].gyerszam);


    getch();
    return 0;
}
