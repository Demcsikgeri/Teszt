#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");// Magyar �kezetes karakterek be�ll�t�sa
    int x;// x v�ltoz� deklar�l�sa
    x=13;// x v�ltoz� defini�l�sa �rt�ke 13 lesz
    int y=x;// y v�ltoz� deklar�l�sa �s defini�l�sa x �rt�k�t veszi fel
    printf("Y �rt�ke: %d\n",y);// y �rt�k�nek ki�r�sa a k�perny�re
    int *p;// p mutat� deklar�l�sa
    x=15;// x v�ltoz� �jradefini�l�sa �j �rt�ke 15 lesz
    p=&x;// p mutat� defini�l�sa �rt�ke az x v�ltoz� mem�riac�me lesz
    y=*p;// y v�ltoz� �jradefini�l�sa �j �rt�ke a p mutat� �ltal meghat�rozott mem�riac�men lev� �rt�k lesz
    printf("Y �j �rt�ke: %d\n",y);// y �j �rt�k�nek ki�r�sa a k�perny�re
    return 0;
}
