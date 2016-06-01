#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    char * s = "Szia Világ!\n";
    printf(s);
    return 0;
}
