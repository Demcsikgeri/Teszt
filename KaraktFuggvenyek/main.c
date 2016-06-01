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
    printf("A mondat %d szóból épül fel.\n",db+1);
    char a='e',b='K';
    printf("Adott egy \'%c\' és egy \'%c\' betû.\n",a,b);
    printf("Az elsõ nagybetûvel: %c\n",toupper(a));
    printf("A második kisbetûvel: %c\n",tolower(b));
    if(islower(a)){
        printf("Az elsõ most már kisbetû\n");
    }else{
        printf("Az elsõ most nagybetû\n");
    }
    if(isupper(b)){
        printf("A második most már nagybetû");
    }else{
        printf("A második most kisbetû");
    }
    return 0;
}
