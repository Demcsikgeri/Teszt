#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");// Magyar �kezetes karakterek be�ll�t�sa
    int ta[5];// ta t�mb deklar�l�sa aminek 5 eleme lehet maximum
    ta[0]=1;// ta els� elem�nek �rt�ke 1
    int *p=ta;// p mutat� deklar�l�sa �s az �rt�ke a ta t�mb els� elem�nek mem�riac�me
    *p=2;// p mutat� �ltal tartalmazott mem�riac�m �rt�ke 2 (ta t�mb els� elem�nek helye)
    ++p;// p �rt�k�nek n�vel�se 1-el
    *p=3;// p mutat� �ltal tartalmazott mem�riac�m �rt�ke 3 (ta t�mb m�sodik elem�nek helye)
    *(++p)=4;// p �rt�k�nek n�vel�se �s az �ltala meghat�rozott mem�riac�men l�v� �rt�k legyen 4(ta t�mb harmadik elem�nek helye)
    printf("ta0=%d ta1=%d ta2=%d\n", ta[0], ta[1], ta[2]);// ta t�mb els� 3 �rt�k�nek ki�r�sa a k�perny�re
    return 0;
}
