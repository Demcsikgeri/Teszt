#include <stdio.h>
#include <stdlib.h>

int szokoev_e(int ev){
 /*
   Minden n�ggyel oszthat� �v,
   kiv�ve a sz�zzal is oszthat�kat.
   Sz�k��vek viszont a 400-zal oszthat� �vek.
   Vagyis a sz�zadfordul�k �vei k�z�l csak azok sz�k��vek,
   amelyek 400-zal is oszthat�k.
 */

    if ((ev%4)==0)
    {
        // oszthato 4-el
        if ((ev%100)==0)
        {
            // oszthato szazzal, ez�rt nem val�sz�n� hogy sz�k��v
            if ((ev%400)==0)
                return 1; // oszthato 400-al, m�giscsak sz�k��v
            else
                return 0; // nem oszthato 400-al de oszthato 100-al ez�rt nem szok��v
        }
        else
            return 1;
    }
    else
        return 0;
}

float negyzete(int ertek){
    return ertek*ertek;
}

float gyoke(int ertek){
    return sqrt(ertek);
}

float szamol(int ev){

    if (szokoev_e(ev)==1)
        return negyzete(ev); // Ha szokoev -> negyzete
    else
        return gyoke(ev); // Ha NEM szokoev -> gyoke
}

int main()
{
    printf("The biggeszt:%f", szamol(2015) );
    getch();
    return 0;
}
