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

    // Megsz�ml�l�s t�tele
    int db=0;
    for(i=0;i<N;i++){
        if(tomb[i]==5){
            db++;
        }
    }
    printf("A keresett elem darabsz�ma: %d",db);
    return 0;
}
