#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char nev[18][20]={"Aczel Judit"
,"Antal Ferenc Istvan"
,"Chambre Zoltan"
,"Hamvas Jozsef"
,"Herbert Attila"
,"Hatejer Klaudia"
,"Horvath Vivien"
,"Juhasz Adam"
,"Kantor Bence"
,"Kelemen Marton"
,"Kiglics Dora"
,"Metal Janos"
,"Petranyi Gabor"
,"Stefko Soma"
,"Szarvak Szabolcs"
,"Toth Anita"
,"Toth Orsolya"
,"Nagy Eszter"};

int i,db=18,aji[18],ki;

int main()
{
    srand(time(NULL));
    for(i=0;i<db;i=i+1)
    {
      //puts(nev[i]);
      aji[i]=0;
    }

    for(i=0;i<db;i=i+1)
    {
      do{
        ki=rand()%db;
      }while(aji[ki]==1);
      aji[ki]=1;
      puts(nev[ki]);
      getchar();
    }
    return 0;
}
