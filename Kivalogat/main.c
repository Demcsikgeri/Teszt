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

    // Kiv�logat�s t�tele
    int tomb2[N];
    for(i=0;i<N;i++){
        if(tomb[i]>5){
            tomb2[j]=i;
            j++;
        }
    }
    for(i=0;i<j;i++){
        printf("Nagyobb mint 5 �rt�k� elem: %d , aminek indexe: %d\n",tomb[tomb2[i]],tomb2[i]+1);
    }
    return 0;
}
