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

    // Minimum indexes rendez�s t�tele
    for(i=0;i<N-1;i++){
        int minind=i;
        for(j=i+1;j<N;j++){
            if(tomb[j]<tomb[minind]){
                minind=j;
            }
        }
        if(i!=minind){
            int temp=tomb[i];
            tomb[i]=tomb[minind];
            tomb[minind]=temp;
        }
    }
    printf("Minimum index alapj�n sorbarendezett t�mb:\n");
    for(i=0;i<N;i++){
        printf("%d, ",tomb[i]);
    }
    return 0;
}
