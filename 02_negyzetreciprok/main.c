#include<stdio.h> /*# = el�ford�t�si
direkt�va helye: bet�lt�nk(include)
egy header f�jlt*/
int a; /*deklar�ci�s ter�let,
ahol a v�ltoz�kat deklar�ljuk
(t�pusmeghat�roz�s)*/
float b;
int main() /*f�f�ggv�ny t�pusa �s neve,
mivel f�ggv�ny k�ztelez� ()*/
{/*f�ggv�ny-block kezdete*/

    /*kiirat�s printf, 1 vagy t�bb param�terrel
    az els� mindig "sztring" ->const char*!
    */
    printf("Kerlek adj meg egy szamot!");
    /*bek�r�s, %d-%i-%f... konverzi�s bet�,
     a v�ltoz� mem�ria c�m�t => & */
    scanf("%d",&a);
    b = 1.0/(a*a);
    printf("ertek: %f",b);
    /*% �s a konv. bet� k�z�tt adhatsz form�z�st
    pl. hossz: 15
    t�rt jegyek sz�ma .7
    + az el�jel mindig megjelenjen
    - hossz�s�gon bel�l balra igaz�t

    m�velet v�gezhet� ki�rat�sban is
    \n sort�r�s*/
    printf("\neredmeny duplaja:%+-15.7fblabla",b*2);
    printf("\n\na cime: %i",&a);
    printf("\nb cime: %i",&b);
    return 0; /*a f�ggv�ny visszat�r�si �rt�ke
    , mindig itt van a v�g�n*/
}/*f�ggv�ny-block v�ge*/
