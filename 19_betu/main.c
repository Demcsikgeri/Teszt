#include <stdio.h>
#include <stdlib.h>

unsigned char betu;
int kod;

int main()
{
    printf("Adj meg egy karaktert!\n");
    scanf("%c",&betu);
    printf("\nEzt adtad: %c es ennek\
            az ASCII kodja: %i ",betu,betu);

    printf("\n\nAdj meg egy kodot!");
    scanf("%i",&kod);
    printf("Ehhez tartozo karakter: %c",kod);
    return 0;
}
