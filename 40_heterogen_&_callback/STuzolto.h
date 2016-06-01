#ifndef STUZOLTO_H_INCLUDED
#define STUZOLTO_H_INCLUDED

typedef enum
{
    soprogeto,
    varazslo,
    baljos
}ERang;

typedef struct
{
    int  TypeID;
    char nev[30];
    int  szul_ev;
    int  rang;
}STuzolto; //méret=38

typedef STuzolto *PSTuzolto;

PSTuzolto Tuzolto_beker();
void Tuzolto_kiir(PSTuzolto FTuzolto);
int Tuzolto_mennyi_idos(PSTuzolto FTuzolto);

#endif // STUZOLTO_H_INCLUDED
