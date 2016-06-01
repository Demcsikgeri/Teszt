#include <stdio.h>
#include <stdlib.h>
char ch, jelszo[3],eut[501],eut2[501];
int karszam,i;

int main()
{
    FILE *fp,*fa,*fb;
    printf("Adj meg egy jelszot");
    for(i=0;i<3;i+=1)
    {
       jelszo[i]=getch();
       printf("*");
    }
    //printf("%s", jelszo);

    printf("\nAdd meg a titkositott fajl eleresi utjat!");
    i=-1;
    do{
       i+=1;
       eut[i]=getche();
    }while(i<499 && eut[i]!=13);

    /*EOS elhelyezése*/
    if(eut[i]==13)
      eut[i]=0;
    else
      eut[i+1]=0;

    printf("\nAdd meg a visszafejtett fajl eleresi utjat!");
    i=-1;
    do{
       i+=1;
       eut2[i]=getche();
    }while(i<499 && eut2[i]!=13);

    /*EOS elhelyezése*/
    if(eut2[i]==13)
      eut2[i]=0;
    else
      eut2[i+1]=0;

    fa=fopen(eut, "r");
    fb=fopen(eut2, "w");
    if (fb!=NULL && fa!=NULL)
    {
        karszam = 0;
        while(!feof(fa))
        {
            ch=fgetc(fa);
            karszam = karszam +1;
            if(!feof(fa))
            {
             switch (karszam)
                {
                    case 1:fprintf(fb,"%c", ch-jelszo[0]);
                      break;
                    case 2:fprintf(fb,"%c", ch-jelszo[1]);
                      break;
                    case 3:fprintf(fb,"%c", ch-jelszo[2]);
                      karszam=0;
                      break;
                }
            }
        }
        fclose(fa);
        fclose(fb);
    }
    return 0;
}
