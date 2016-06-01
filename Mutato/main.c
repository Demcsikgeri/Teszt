#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");// Magyar ékezetes karakterek beállítása
    int x;// x változó deklarálása
    x=13;// x változó definiálása értéke 13 lesz
    int y=x;// y változó deklarálása és definiálása x értékét veszi fel
    printf("Y értéke: %d\n",y);// y értékének kiírása a képernyõre
    int *p;// p mutató deklarálása
    x=15;// x változó újradefiniálása új értéke 15 lesz
    p=&x;// p mutató definiálása értéke az x változó memóriacíme lesz
    y=*p;// y változó újradefiniálása új értéke a p mutató által meghatározott memóriacímen levõ érték lesz
    printf("Y új értéke: %d\n",y);// y új értékének kiírása a képernyõre
    return 0;
}
