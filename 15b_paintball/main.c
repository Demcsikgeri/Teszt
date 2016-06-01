#include <stdio.h>
#include <stdlib.h>

int i, db=5;
int p[5];
main()
{
    /*i = -1;

    i = i + 1;
    printf("Add be az %d. befutot!\n",i+1);
    scanf("%i",&p[i]);
    if (p[i]!=0)
    {
        i = i + 1;
        printf("Add be az %d. befutot!\n",i+1);
        scanf("%i",&p[i]);
        if (p[i]!=0)
        {
            i = i + 1;
            printf("Add be az %d. befutot!\n",i+1);
            scanf("%i",&p[i]);
            if(p[i]!=0)
            {
                i = i + 1;
                printf("Add be az %d. befutot!\n",i+1);
                scanf("%i",&p[i]);
                if (p[i]!=0)
                {
                    i = i + 1;
                    printf("Add be az %d. befutot!\n",i+1);
                    scanf("%i",&p[i]);

                }
            }
        }

    }*/
    i=-1;
    do
    {
        i = i + 1;
        printf("Add be az %d. befutot!\n",i+1);
        scanf("%i",&p[i]);
    }
    while(p[i]!=0 && i<(db-1));

    if (p[i]!=0)
    {
       i=i+1;
    }
    db=i;

    /*kiíratás*/
    printf("Eredeti sorrend:");
   /* i = 0;
    if (db>i) printf("\n%i",p[i]);
    i = i + 1;
    if (db>i) printf("\n%i",p[i]);
    i = i + 1;
    if (db>i) printf("\n%i",p[i]);
    i = i + 1;
    if (db>i) printf("\n%i",p[i]);
    i = i + 1;
    if (db>i) printf("\n%i",p[i]);*/
    i=0;
    while(db>i)
    {
        printf("\n%i",p[i]);
        i=i+1;
    }
    printf("\n\nVisszafele:");

    /*i = db-1;
    if (0<=i) printf("\n%i",p[i]);
    i = i - 1;
    if (0<=i) printf("\n%i",p[i]);
    i = i - 1;
    if (0<=i) printf("\n%i",p[i]);
    i = i - 1;
    if (0<=i) printf("\n%i",p[i]);
    i = i - 1;
    if (0<=i) printf("\n%i",p[i]);*/
    i=db-1;
    while(0<=i)
    {
        printf("\n%i",p[i]);
        i=i-1;
    }
    return 0;
}
