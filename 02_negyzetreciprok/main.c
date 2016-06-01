#include<stdio.h> /*# = elõfordítási
direktíva helye: betöltünk(include)
egy header fájlt*/
int a; /*deklarációs terület,
ahol a változókat deklaráljuk
(típusmeghatározás)*/
float b;
int main() /*fõfüggvény típusa és neve,
mivel függvény köztelezõ ()*/
{/*függvény-block kezdete*/

    /*kiiratás printf, 1 vagy több paraméterrel
    az elsõ mindig "sztring" ->const char*!
    */
    printf("Kerlek adj meg egy szamot!");
    /*bekérés, %d-%i-%f... konverziós betû,
     a változó memória címét => & */
    scanf("%d",&a);
    b = 1.0/(a*a);
    printf("ertek: %f",b);
    /*% és a konv. betû között adhatsz formázást
    pl. hossz: 15
    tört jegyek száma .7
    + az elõjel mindig megjelenjen
    - hosszúságon belül balra igazít

    mûvelet végezhetõ kiíratásban is
    \n sortörés*/
    printf("\neredmeny duplaja:%+-15.7fblabla",b*2);
    printf("\n\na cime: %i",&a);
    printf("\nb cime: %i",&b);
    return 0; /*a függvény visszatérési értéke
    , mindig itt van a végén*/
}/*függvény-block vége*/
