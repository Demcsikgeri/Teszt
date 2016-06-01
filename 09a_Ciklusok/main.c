#include <stdio.h>
#include <stdlib.h>
int tol,ig;

int main() {
    printf("Adja meg a 'tol'-t: ");
    scanf("%i",&tol);
    printf("Adja meg az 'ig'-et: ");
    scanf("%i",&ig);
    if(tol%2!=0){
        tol=tol+1;
    }
    while(tol<=ig) {
        printf("%i\n", tol );
        tol=tol+2;
    }
    return 0;
}
