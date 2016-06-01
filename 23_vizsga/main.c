#include <stdio.h>
#include <stdlib.h>
int tomb[9];
int i,be,j,csillagdarab=0,db,nemeredmeny;

void gebasz(int fdb,int *ft)
{
    int sz;
    for(sz = 0; sz<fdb; sz= sz+3)
    {
        printf("  %i %i %i\n", sz, sz+1, sz+2);
        printf("  %i %i %i\n",ft[sz],ft[sz+1],ft[sz+2]);
    }
}
void csillagok( int fdb, char ch)
{
    int fszamlalo;
    for(fszamlalo=0;fszamlalo<fdb;fszamlalo=fszamlalo+1)
    printf("%c",ch);

}
int szorzo(int szam1, int szam2)
{
    int eredmeny;
    eredmeny=szam1*szam2;
    return eredmeny;
}
int main()
{
    for(i = 0; i<9; i= i+1)
    {
        tomb[i] = 0;
    }

    /*printf("0 1 2\n");
    printf("%i %i %i\n", tomb[0], tomb[1], tomb[2]);
    printf("3 4 5\n");
    printf("%i %i %i\n", tomb[3], tomb[4], tomb[5]);
    printf("6 7 8\n");
    printf("%i %i %i\n\n", tomb[6], tomb[7], tomb[8]);*/


    gebasz(9,tomb);
    for(j=0;j<9;j+=1)
    {
        do{
        scanf("%d",&be);
        }
        while(tomb[be]!=0);
        tomb[be] = 1;

        gebasz(9,tomb);
    }
    printf("Hany csillagot akarsz megadni?");
    /*scanf("%d",&csillagdarab);
    csillagok(csillagdarab);*/
    scanf("%d",&db);
    csillagok(db,':');
    nemeredmeny = szorzo(10,4);
    printf("\n%d",nemeredmeny);
    return 0;
}
