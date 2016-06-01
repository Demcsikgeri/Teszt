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

    // Minimum Maximum tétele
    int min=tomb[0];
    int max=tomb[0];
    for(i=1;i<N;i++){
        if(tomb[i]<min){
            min=tomb[i];
        }
        if(tomb[i]>max){
            max=tomb[i];
        }
    }
    printf("Min: %d\tMax: %d\n",min,max);
    return 0;
}
