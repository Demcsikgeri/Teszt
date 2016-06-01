#include <stdio.h>
#include <stdlib.h>

int valaszt,valaszt2,a,b;

int main()
{
   do{
        system("CLS");
        printf("\n\n1. Koszon\n");
        printf("2. Negy alapmuvelet\n");
        printf("3. Felrobban\n");
        printf("4. Kilep\n");
        scanf("%i",&valaszt);
        system("CLS");
        switch (valaszt)
        {
            case 1: printf("Hello world!");
                    printf("\nVissza menube: ");
                    system("PAUSE");
                    break;
            case 2: printf("\n\n1. Osszead\n");
                    printf("2. Kivon\n");
                    printf("3. Szoroz\n");
                    printf("4. Oszt\n");
                    scanf("%i",&valaszt2);
                    printf("Adj meg egy szamot!");
                    scanf("%i",&a);
                    printf("Add meg a masik szamot!");
                    scanf("%i",&b);
                    switch(valaszt2)
                    {
                     case 1:printf("a+b=%i",a+b);
                            break;
                     case 2:printf("a-b=%i",a-b);
                            break;
                     case 3:printf("a*b=%i",a*b);
                            break;
                     case 4:printf("a/b=%f",(a/(float)b));
                            break;
                     default: printf("Nincs ilyen menupont!");
                    }
                    printf("\nVissza a fomenube: ");
                    system("PAUSE");
                    break;
            case 3: printf("*\n* *\n* * * * BUMMMM");
                    printf("\nVissza menube: ");
                    system("PAUSE");
                    break;
            case 4: break;
            default: printf("Nincs ilyen menupont!");
                     printf("\nVissza menube: ");
                     system("PAUSE");
        }
   }while(valaszt!=4);
   return 0;
}
