#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

unsigned long FibRecursion(unsigned long N){
    if(N==0)    return 0;
    if(N==1)    return 1;
    return FibRecursion(N-1)+FibRecursion(N-2);
}

unsigned FibLoop(unsigned N){
    unsigned x=1,y=1, sum, i=1;
    if(N==1)    return 1;
    if(N==2)    return 1;
    while(i<N-1){
        sum = x + y;
        x = y;
        y = sum;
        i++;
    }
    return sum;
}


int main()
{
    unsigned i=0, N, result;
    printf("[CALCULATING THE Nth FIBONACCI NUMBER]\nEnter N (up to %u)\n", UINT_MAX);
    scanf("%u", &N);
    clock_t start, end;
    float timePassed;
    start = clock();
    result = FibLoop(N);
    end = clock();
    timePassed = 1.0*(end-start)/CLOCKS_PER_SEC;
    printf("\n\n[LOOP] The result for %u is %u. Calculated it in %f seconds", N, result, timePassed);

    start = clock();
    result = FibRecursion(N);
    end = clock();
    timePassed = 1.0*(end-start)/CLOCKS_PER_SEC;//N=45 in 19 seconds for me
    printf("\n\n[RECURSION] The result for %u is %u. Calculated it in %f seconds", N, result, timePassed);
    return 0;
}
