#include <stdio.h>
#include <stdlib.h>
int a,b,lkkt;

int main() {
    printf("Adjon meg az elso szamot!\n");
    scanf("%i", &a);
    printf("Adjon meg a masodik szamot!\n");
    scanf("%i", &b);

    if(a>b) {
        lkkt = a;
    } else {
        lkkt = b;
    }

    while((lkkt%a!=0)||(lkkt%b!=0)) {
        lkkt=lkkt+1;
    }
    printf("lkkt(a,b) = %i", lkkt);
    return 0;
}
