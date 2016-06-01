#include <stdio.h>
#include <stdlib.h>

int szokoev_e(int ev){
 /*
   Minden néggyel osztható év,
   kivéve a százzal is oszthatókat.
   Szökõévek viszont a 400-zal osztható évek.
   Vagyis a századfordulók évei közül csak azok szökõévek,
   amelyek 400-zal is oszthatók.
 */

    if ((ev%4)==0)
    {
        // oszthato 4-el
        if ((ev%100)==0)
        {
            // oszthato szazzal, ezért nem valószínû hogy szökõév
            if ((ev%400)==0)
                return 1; // oszthato 400-al, mégiscsak szököév
            else
                return 0; // nem oszthato 400-al de oszthato 100-al ezért nem szoköév
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
