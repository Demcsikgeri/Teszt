#include <stdio.h>
#include <stdlib.h>
int par_poz;
int main()
{
    printf("Kerek egy szamot!\n");
    scanf("%i",&par_poz);
    if(par_poz==0)
    {
        printf("Nulla");
    }
    else
    {
        if(par_poz%2==0)
        {
           printf("Paros ");
        }
        else
        {
           printf("Paratlan ");
        }

        if(par_poz>0)
        {
           printf("es pozitiv.");
        }
        else
        {
           printf("es negativ.");
        }
    }
    return 0;
}
