#include <stdio.h>
#include <stdlib.h>

int pn;

int main()
{
    printf("Adj meg egy szamot!\n");
    scanf("%d",&pn);
    if (pn==0)
    {
       //igaz
       printf("a szam nulla");
    }
    else
    {
       //hamis
        if(pn>0)
        {
          printf("a szam pozitiv");
        }
        else
        {
          printf("a szam negativ");
        }
    }
    return 0;
}
