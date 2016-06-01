#include <stdio.h>
#include <stdlib.h>

int p1,p2,p3,p4,p5,db=0;
main()
{
    printf("Add be az 1. befutot!\n");
    scanf("%i",&p1);
    if (p1!=0)
    {
        db=db+1;
        printf("Add be a 2. befutot!");
        scanf("%i",&p2);
        if (p2!=0)
        {
            db=db+1;
            printf("Add be a 3. befutot!");
            scanf("%i",&p3);
            if(p3!=0)
            {
                db=db+1;
                printf("Add be a 4. befutot!");
                scanf("%i",&p4);
                if (p4!=0)
                {
                    db=db+1;
                    printf("Add be a 5. befutot!");
                    scanf("%i",&p5);
                    if (p5!=0)
                    {
                        db=db+1;
                    }
                }
            }
        }

    }
    /*kiíratás*/
    if (db>0) printf("\n%i",p1);
    if (db>1) printf("\n%i",p2);
    if (db>2) printf("\n%i",p3);
    if (db>3) printf("\n%i",p4);
    if (db>4) printf("\n%i",p5);


    return 0;
}
