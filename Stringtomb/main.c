#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "");// Magyar ékezetes karakterek beállítása
    char s[]={'k','a','r','a','k','t','e','r','s','o','r','o','z','a','t',0};
    printf("Ez egy %s\n",s);
    char c[]="string";
    printf("Ez is egy %s\n",c);
    printf("Vagy külön-külön írva\n");
    int i;
    for(i=0;c[i]!=0;++i){
        printf("Karakter %c\n",c[i]);
    }
    return 0;
}
