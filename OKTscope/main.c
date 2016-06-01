#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    func();
    printf("Külsõ szám: %d\n", szam);
    int i;
    for(i=1; i <= 5; ++i)
    {
        static int szam = 7;
        printf("szam erteke: %d\n", szam++);
    }
    return 0;
}
