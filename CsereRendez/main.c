#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main()
{
    setlocale(LC_ALL, "");
    int i,j=0;
    int tomb[N];
    for(i=0;i<N;i++){
        printf("Add meg a t�mb %d. elem�t: \n", i+1);
        scanf("%d",&tomb[i]);
    }

    // Cser�s rendez�s t�tele
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            if(tomb[i]>tomb[j]){
                int temp=tomb[i];
                tomb[i]=tomb[j];
                tomb[j]=temp;
            }
        }
    }
    printf("T�mb elemei n�vekv� sorrendben:\n");
    for(i=0;i<N;i++){
        printf("%d, ",tomb[i]);
    }
    return 0;
}
