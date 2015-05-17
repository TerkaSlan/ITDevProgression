#include <stdio.h>
#include <stdlib.h>
//Read whole number N, convert to abs(N), sum=sum+N%10, N = N/10, if N==0 -> stop   =   sum of digits in a number
int main()
{
    int N,sum=0;        // limitation: capacity of N is 2^32/2-1
    printf("Input N:\n");
    scanf("%d", &N);
    if(N<0) N=N*(-1);
    while(N!=0){
        sum = sum + N%10;
        N = N/10;
    }
    printf("\nOutput: %d", sum);

    return 0;
}
