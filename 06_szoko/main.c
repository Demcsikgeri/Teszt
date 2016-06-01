#include <stdio.h>
#include <stdlib.h>
int evszam;
int main()
{
    printf("Adj egy evszamot!\n");
    scanf("%i",&evszam);
    if(evszam % 4 == 0)
    {
        if(evszam % 100 == 0)
        {
            if(evszam % 400 == 0)
            {
               printf("Szokik");   //2000
            }
            else
            {
               printf("Nem szokik"); //1900
            }

        }
        else
        {
             printf("Szokik");    //2012
        }
    }
    else
    {
        printf("Nem szokik");  //2017
    }
    return 0;
}
