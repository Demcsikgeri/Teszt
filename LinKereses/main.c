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
        printf("Add meg a t�mb %d. elem�t: \n", i+1);
        scanf("%d",&tomb[i]);
    }

    // Line�ris keres�s t�tele
    i=0;
    while(i<N && tomb[i]!=5){
        i++;
    }
    if(i<N){
        printf("Van keresett elem, indexe: %d\n",i+1);
    }else{
        printf("Nincs keresett elem.\n");
    }
    return 0;
}
