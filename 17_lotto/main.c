#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int db=5,i,j,talatok,tipp[5],nyert[5];

int main()
{
    srand(time(NULL));
    i=-1;
    while(i<(db-1))
    {
      i=i+1;
      do{
        printf("Add meg %i. tippet!\n",i+1);
        scanf("%i",&tipp[i]);
        j=0;
        while(j<i && tipp[i]!=tipp[j])
        {
           j=j+1;
        }
      }while(tipp[i]<1 || tipp[i]>90 || i>j);
    }

    i=-1;
    while(i<(db-1))
    {
        i=i+1;
        do{
            nyert[i]=rand()%90+1;
            j=0;
            while(i>j && nyert[i]!=nyert[j]) j=j+1;
        }while(i>j);
        printf("%i ", nyert[i]);
    }
    return 0;
}




















