#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE *fp;
int x, db, szokoz_db;
char ch;
int main()
{
    srand(time(NULL));
    fp=fopen("d:\\temp\\szamok.txt","w+");
    if(fp!=NULL)
    {

        printf("Sikerult\n\n");
        for(db=0; db<5; db=db+1)
        {
            x=rand()%350;
            fprintf(fp,"%d ", x);

        }
        fseek(fp,0,SEEK_SET);
        szokoz_db=0;
        while(!feof(fp) && szokoz_db<2)
        {
           ch=fgetc(fp);
           if(ch==' ')
           {
            szokoz_db=szokoz_db+1;
           }
           //printf("%c",ch);
        }
        fscanf(fp, "%d", &x);
        printf("Az 5 generaltbol a 3. szam: %d", x);
        fclose(fp);
    }
    else
    {
        printf("Nem sikerült");
    }

    return 0;
}
