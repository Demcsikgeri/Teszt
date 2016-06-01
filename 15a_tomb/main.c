#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, db=4;
int tomb[4];
int main()
{
    //srand(time(NULL));
    printf("Adj meg szamokat, legfeljebb %i darabot, 0-ra kilep!\n",db);
    i=-1;
    do{
        i=i+1;
        scanf("%i",&tomb[i]);
        //tomb[i]=(rand()/(RAND_MAX/5))+10;
    }while(i<(db-1) && tomb[i]!=0);

    /*valos darabszam megallapitasa:*/
    if(tomb[i]!=0) db=i+1;
    else db=i;

    printf("\n\nEnnyi szamot adtal meg: %i",db);
    printf("\n\nEzek a szamok voltak:");
    i=0;
    while (i<db)
    {
        printf("%i ", tomb[i]);
        i=i+1;
    }
    printf("\n\nEzek a szamok voltak visszafele sorrendben:");
    i=db-1;
    while (i>=0)
    {
        printf("%i ", tomb[i]);
        i=i-1;
    }
    return 0;
}
