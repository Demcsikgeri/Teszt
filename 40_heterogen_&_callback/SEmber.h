#ifndef __SEMBER_HEADER
#define __SEMBER_HEADER

typedef struct
{
    int  TypeID;
    char nev[30];
    int  szul_ev;
}SEmber; //méret=34

typedef SEmber *PSEmber;

PSEmber Ember_beker();
void Ember_kiir(PSEmber FEmber);
int Ember_mennyi_idos(PSEmber FEmber);

#endif // SEMBER_H_INCLUDED
