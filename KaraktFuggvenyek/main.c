#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "fej.h"

int main()
{
    setlocale(LC_ALL, "");
    char mondat[100];
    int i,db=0;
    puts("Adj meg egy mondatot.");
    gets(mondat);
    for(i=0;i<strlen(mondat);i++){
        if(isspace(mondat[i])){
            db++;
        }
    }
    printf("A mondat %d sz�b�l �p�l fel.\n",db+1);
    char a='e',b='K';
    printf("Adott egy \'%c\' �s egy \'%c\' bet�.\n",a,b);
    printf("Az els� nagybet�vel: %c\n",toupper(a));
    printf("A m�sodik kisbet�vel: %c\n",tolower(b));
    if(islower(a)){
        printf("Az els� most m�r kisbet�\n");
    }else{
        printf("Az els� most nagybet�\n");
    }
    if(isupper(b)){
        printf("A m�sodik most m�r nagybet�");
    }else{
        printf("A m�sodik most kisbet�");
    }
    return 0;
}
