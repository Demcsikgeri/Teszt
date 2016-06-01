#ifndef ADATOK_H_INCLUDED
#define ADATOK_H_INCLUDED

typedef struct
{
    char rendszam[8];
    int idopont;
} SAtlepesi_Rekord;

typedef SAtlepesi_Rekord *PSAtlepesi_Rekord;

PSAtlepesi_Rekord Get_Belepesi_Adatok();
PSAtlepesi_Rekord Get_Kilepesi_Adatok();

#endif // ADATOK_H_INCLUDED
