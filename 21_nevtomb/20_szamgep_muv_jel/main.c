#include <stdio.h>
#include <stdlib.h>

int szam1,szam2;
float eredmeny;
char muv;

int main()
{
    printf("Add meg az elso szamot:\n");
    scanf("%i",&szam1);
    while(getchar()!=10);//bill. memoria uritese
    printf("Add meg a muveletet (+*-/):\n");
    muv=getchar();
    while(getchar()!=10);r
    printf("Add meg a masodik szamot:\n");
    scanf("%i",&szam2);
    while(getchar()!=10);
    switch (muv)
    {
        case '+': eredmeny=szam1 + szam2;
                  break;
        case '-': eredmeny=szam1 - szam2;
                  break;
        case '*': eredmeny=szam1 * szam2;
                  break;
        case '/': eredmeny=szam1 / (float)szam2;
                  break;
        default:  eredmeny=0;
    }
    printf("\n%i%c%i=%.3f",szam1,muv,szam2,eredmeny);

    return 0;
}
