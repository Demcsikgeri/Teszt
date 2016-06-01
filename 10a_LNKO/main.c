#include <stdio.h>
#include <stdlib.h>
int a,b,lnko;

int main() {
    printf("Adjon meg az elso szamot!\n");
    scanf("%i", &a);
    printf("Adjon meg a masodik szamot!\n");
    scanf("%i", &b);

    if(a<b) {
        lnko = a;
    } else {
        lnko = b;
    }

    while((a%lnko!=0)||(b%lnko!=0)) {
        lnko=lnko-1;
    }
    printf("lnko(a,b) = %i", lnko);
    return 0;
}
