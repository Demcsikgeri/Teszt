#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main()
{
    setlocale(LC_ALL, "");
    int i,j;
    int tomb[N];
    for(i=0;i<N;i++){
        printf("Add meg a tömb %d. elemét: \n", i+1);
        scanf("%d",&tomb[i]);
    }

    // Buborékos rendezés tétele
    for(i=1;i<N;i++){
        for(j=N-1;j>=i;j--){
            if(tomb[j-1]>tomb[j]){
                int temp=tomb[j-1];
                tomb[j-1]=tomb[j];
                tomb[j]=temp;
            }
        }
    }
    printf("Buborék módszer alapján sorbarendezett tömb:\n");
    for(i=0;i<N;i++){
        printf("%d, ",tomb[i]);
    }
    return 0;
}
