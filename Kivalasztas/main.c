#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main()
{
    setlocale(LC_ALL, "");
    int i;
    int tomb[N];
    for(i=0;i<N;i++){
        printf("Add meg a tömb %d. elemét: \n", i+1);
        scanf("%d",&tomb[i]);
    }

    // Kiválasztás tétele
    i=0;
    while(tomb[i]!=5){
        i++;
    }
    printf("A keresett elem indexe: %d\n",i+1);
    return 0;
}
