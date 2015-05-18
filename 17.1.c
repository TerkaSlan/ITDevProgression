#include <stdio.h>
#include <limits.h>

unsigned long long fact(unsigned long long x, unsigned long long stop){
    unsigned long long i, temp=1;   // despite long long, prone to overflows in difference is big and/or the values are
    for(i=0; i<stop; i++){
        temp = temp*x;
        x--;
    }
    return temp;
}

int main()
{
    unsigned n,k;
    printf("Enter n:\n");
    scanf("%u", &n);
    printf("Enter k:\n");
    scanf("%u", &k);
    if(n<k){printf("\n\nn must be greater that k, try again."); return -1;}
    unsigned long long difference = n-k; //to be able to calculate large values
    unsigned long long num = fact(n, difference);
    unsigned long long den = fact(difference,difference);
    printf("\n\nThe binomial coefficient is: %llu",num/den);
    return 0;
}
