#include <conio.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int kerulet;
    int szavazat_szam;
    char jelolt[2][20];
    char part_nev[10];
} SPolitiKUSS;

SPolitiKUSS t[100];

void kiir(SPolitiKUSS *p)
{
    printf("%i %i %s %s %s\r\n",
           p->kerulet,
           p->szavazat_szam,
           p->jelolt[0],
           p->jelolt[1],
           p->part_nev
          );
}

int main()
{
    FILE *f=fopen("szavazatok.txt","r");

    int i=0;

    while (!feof(f))
    {
        fscanf(f,"%i",&t[i].kerulet);
        fscanf(f,"%i",&t[i].szavazat_szam);
        fscanf(f,"%s",t[i].jelolt[0]);
        fscanf(f,"%s",t[i].jelolt[1]);
        fscanf(f,"%s\r\n",t[i].part_nev);
        i+=1;
    }

    int c;

    for (c=0; c<i; c+=1)
        kiir(&t[c]);

    // 2. feladat
    printf("2. feladat:%i",i);

    // 3. feladat
    printf("Adj meg képviselõt!\r\n");
    char n_vez[100];
    char n_ker[100];
    printf("Vezeteknev:");
    scanf("%s",n_vez);
    printf("\r\nKeresztnev:");
    scanf("%s",n_ker);
    printf("\r\n");

    for (c=0; c<i; c+=1)
    {
        if (!strcmp(n_vez,t[c].jelolt[0]))
            if (!strcmp(n_ker,t[c].jelolt[1]))
            {
                printf("szavazatok szama:%i",t[c].szavazat_szam);
                break;
            }
    }

    if (c>=i)
        printf("Nincs");

    int ossz_szavazatok_szama=0;

    for (c=0; c<i; c+=1)
        ossz_szavazatok_szama +=  t[c].szavazat_szam;

    print("ossz_szavazatok_szama:%i\r\n",ossz_szavazatok_szama);
    print("reszveteli arany:%.2f%%\r\n",(ossz_szavazatok_szama*100.0)/12345.0);

    // 5. feladat
    int t_partok[5]= {0,0,0,0,0};

    // GYEP,HEP,TISZ,ZEP,FUG(-)

    for (c=0; c<i; c+=1)
    {
        if ( !strcmp(t[c].part_nev,"GYEP") )
            t_partok[0]+=t[c].szavazat_szam;
        if ( !strcmp(t[c].part_nev,"HEP") )
            t_partok[1]+=t[c].szavazat_szam;
        if ( !strcmp(t[c].part_nev,"TISZ") )
            t_partok[2]+=t[c].szavazat_szam;
        if ( !strcmp(t[c].part_nev,"ZEP") )
            t_partok[3]+=t[c].szavazat_szam;
        if ( !strcmp(t[c].part_nev,"-") )
            t_partok[4]+=t[c].szavazat_szam;
    }

    printf("GYEP%.2f:",(t_partok[0]*100.0)/ossz_szavazatok_szama);
    printf("HEP%.2f:",(t_partok[1]*100.0)/ossz_szavazatok_szama);
    printf("TISZ%.2f:",(t_partok[2]*100.0)/ossz_szavazatok_szama);
    printf("ZEP%.2f:",(t_partok[3]*100.0)/ossz_szavazatok_szama);
    printf("FUG%.2f:",(t_partok[4]*100.0)/ossz_szavazatok_szama);

    //6. feladat

    int tmp;

    int max_szav=t[0].szavazat_szam;

    for (c=1; c<i; c+=1)
        if (max_szav < t[c].szavazat_szam)
            max_szav=szavazat_szam;

    for (c=0; c<i; c+=1)
        if (t[c].szavazat_szam == max_szav )
            kiir(&t[c]);

    // 7. feladat
    int ker_max[8]= {0,0,0,0,0,0,0,0};

    for (c=0; c<i; c+=1)
        if ( ker_max[ t[c].kerulet-1] < t[c].szavazat_szam )
            ker_max[ t[c].kerulet-1] = t[c].szavazat_szam;
    /*    Jó megoldás, de nem teljesíti a kerület szerinti rendezettséget
        for (c=0; c<i; c+=1)
            if ( ker_max[t[c].kerulet-1] == t[c].szavazat_szam)
                kiir(&t[c]);
                */
    FILE *g=fopen("kepviselo.txt","w");

    int k;

    for (k=1; k<=8; k+=1)
        for (c=0; c<i; c+=1)
            if ( t[c].kerulet == k)
                if ( ker_max[k-1] == t[c].szavazat_szam)
                    if (!strcmp(t[c].part_nev,"-"))
                        fprinf(g,"%i %s %s fuggetlen", k, t[c].jelolt[0],t[c].jelolt[1]);
                    else
                        fprinf(g,"%i %s %s %s", k, t[c].jelolt[0],t[c].jelolt[1],t[c].part_nev);
    fclose(g);

    fclose(f);

    getch();
    return 0;
}
