#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main( int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    fprintf(stdout, "Szia Vil�gdhd!\n");
    fprintf(stderr, "Szia Vil�g!\n");
    return 0;
}
