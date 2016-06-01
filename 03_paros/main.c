#include <stdio.h>
#include <stdlib.h>

int par_paratlan;

int main()
{
    printf("Adj meg egy szamot!\n");
    scanf("%d",&par_paratlan);
    if (par_paratlan % 2 == 0)
    {
       //igaz
       printf("a szam paros");
    }
    else
    {
       //hamis
       printf("a szam paratlan");
    }
    return 0;
}
