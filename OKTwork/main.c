#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum { max_string = 127};
static char string[max_string + 1] = "";

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");
    printf("Adj be egy sz�veget: ");
    fgets(string, max_string, stdin);
    printf("A megadott sz�veg: %s\n", string);
    int i;
    for(i=0; i<5; i++){
        printf("I jelenleg %d\n", i);
    }
    return 0;
}
