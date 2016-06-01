#include <stdio.h>
#include <stdlib.h>

int n,x;

int main() {
    printf("Adjon meg egy szamot!\n");
    scanf("%i", &n);
    printf("Az adott szam osztoi:");
    x=1;
    while(x<=n) {
        if(n%x==0) {
            printf("\n%i", x);
        }
        x=x+1;
    }
    return 0;
}
