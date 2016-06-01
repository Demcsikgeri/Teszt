#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main( int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    fprintf(stdout, "Szia Világdhd!\n");
    fprintf(stderr, "Szia Világ!\n");
    return 0;
}
