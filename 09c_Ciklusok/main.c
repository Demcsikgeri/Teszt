#include <stdio.h>
#include <stdlib.h>
int tol,ig;

int main() {
    printf("Adja meg az egyik hatart: ");
    scanf("%i",&tol);
    printf("Adja meg a masik hatart: ");
    scanf("%i",&ig);

    if(tol<ig) {
        if(tol%2!=0) {
            tol=tol+1;
        }
        if(ig%2!=0) {
            ig=ig-1;
        }
        while(tol<=ig) {
            printf("%i\n", tol );
            tol=tol+2;
        }
    } else {
        if(tol%2!=0) {
            tol=tol-1;
        }
        if(ig%2!=0) {
            ig=ig+1;
        }
        while(ig<=tol) {
            printf("%i\n", ig );
            ig=ig+2;
        }
    }
    return 0;
}
