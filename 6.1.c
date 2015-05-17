#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
//#define CHOICE

long long int fact(long long int n){
    if(n==0)    return 1;
    if(n==1)    return 1;
    return n*fact(n-1);
}

int main()
{
    int i,j,choice;
    long long int k,n;
    #ifdef CHOICE
    printf("Which row do you wish to display (up to 20)?\n");
    scanf("%d", &choice);
    #endif
    for(i=0; i<=ROWS;  i++){
        #ifdef CHOICE
            i=choice;
        #endif // CHOICE
        for(j=0; j<=ROWS-i; j++){
            printf("   ");
        }
        for(k=0; k<=i; k++){
            n=i;
            printf("%3d", fact(n)/(fact(n-k)*fact(k)));
            printf("   ");
        }
        #ifdef CHOICE
        break;
        #endif // CHOICE
        printf("\n");
    }
    return 0;
}
