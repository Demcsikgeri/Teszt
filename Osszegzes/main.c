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

    // �sszegz�s t�tele
    int sum=0;
    for(i=0;i<N;i++){
        sum+=tomb[i];
    }
    printf("�sszeg: %d\n",sum);
    return 0;
}
