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

    // Minimum �s Maximum index t�tele
    int mini;
    int maxi;
    for(i=0;i<N;i++){
        if(tomb[i]<tomb[mini]){
            mini=i;
        }
        if(tomb[i]>tomb[maxi]){
            maxi=i;
        }
    }
    printf("A t�mb legkisebb eleme: %d, melynek indexe: %d\n",tomb[mini],mini+1);
    printf("A t�mb legnagyobb eleme: %d, melynek indexe: %d\n",tomb[maxi],maxi+1);
    return 0;
}
