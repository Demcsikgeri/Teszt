#include <stdio.h>
#include <stdlib.h>
int tol,ig,t;

int main() {
    printf("Adja meg az egyik hatart: ");
    scanf("%i",&tol);
    printf("Adja meg a masik hatart: ");
    scanf("%i",&ig);

    if(tol<ig) {
        t=1;
    } else {
        t=-1;
    }

    if(tol%2!=0) {
        tol=tol+t;
    }

    if(ig%2!=0) {
        ig=ig-t;
    }

    if(tol<ig) {
        while(tol<=ig) {
            printf("%i\n", tol );
            tol=tol+2;
        }
    } else {
        while(ig<=tol) {
            printf("%i\n", ig );
            ig=ig+2;
        }
    }
    return 0;
}
