#include <stdio.h>
#include <stdlib.h>
int n,x,i;

int main() {
    printf("Adja meg a vart hatvanyt: ");
    scanf("%i",&n);

    x=1;
    i=0;
    while(i<n) {
        x=x*2;
        i=i+1;
    }
    printf("2^%i = %i",n,x);
    return 0;
}
