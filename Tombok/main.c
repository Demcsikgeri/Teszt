#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");// Magyar ékezetes karakterek beállítása
    int ta[5];// ta tömb deklarálása aminek 5 eleme lehet maximum
    ta[0]=1;// ta elsõ elemének értéke 1
    int *p=ta;// p mutató deklarálása és az értéke a ta tömb elsõ elemének memóriacíme
    *p=2;// p mutató által tartalmazott memóriacím értéke 2 (ta tömb elsõ elemének helye)
    ++p;// p értékének növelése 1-el
    *p=3;// p mutató által tartalmazott memóriacím értéke 3 (ta tömb második elemének helye)
    *(++p)=4;// p értékének növelése és az általa meghatározott memóriacímen lévõ érték legyen 4(ta tömb harmadik elemének helye)
    printf("ta0=%d ta1=%d ta2=%d\n", ta[0], ta[1], ta[2]);// ta tömb elsõ 3 értékének kiírása a képernyõre
    return 0;
}
