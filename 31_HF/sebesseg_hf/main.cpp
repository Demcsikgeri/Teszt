#include <iostream>
#include <conio.h>
#include <stdio.h>


#include "adatok.h"

void SAtlepesi_Rekord_Kiir(PSAtlepesi_Rekord rek)
{
    printf("%s : %i\r\n",rek->rendszam,rek->idopont);
}

int main()
{
    int i;

    // Belépési adatok kiíratása

    PSAtlepesi_Rekord belep_tomb=Get_Belepesi_Adatok();

    for(i=0;i<1000;i+=1)
        SAtlepesi_Rekord_Kiir(&belep_tomb[i]);

    // Kilépési adatok kiíratása

    PSAtlepesi_Rekord kilep_tomb=Get_Kilepesi_Adatok();

    PSAtlepesi_Rekord tomb_elemein_lepegeto_pointer=kilep_tomb;

    for (i=0;i<1000;i+=1,tomb_elemein_lepegeto_pointer+=1)
        SAtlepesi_Rekord_Kiir(tomb_elemein_lepegeto_pointer);

    // Várakozás billentyûütésig
    getch();
    return 0;
}
