#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j,x=1,y ;
    printf("Give me the upper boundary up to which you wish to generate all the prime numbers\n");
    scanf("%d",&y);
    if(y<3){
        printf("Invalid input");
        return -1;
    }
    int z[y-2];
    // generating the numbers
    for ( i = 0; i < y-2; i++ ){
        z[i] = 2+i;
    }
    // sieving the primes
    for ( i = 0; i < y-2; i++ ){
        if(z[i] != 0){
            for(j=i+z[i]; j<y-2; j=j+z[i]){
                z[j] = 0;
            }
        }
    }
    // listing the primes
    printf("\n\n\n");
    for ( i = x-1; i < y-2; i++ ){
        if(z[i] !=0){
            printf("%d, ", z[i]);
        }
    }
    return 0;
}
