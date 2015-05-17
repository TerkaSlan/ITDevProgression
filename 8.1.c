#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int num[100],i,smallest=INT_MAX, gcd=1, n; // INT_MAX so that I can be sure smallest will be overwritten
    printf("How many numbers do you want to find GCD of (<=100)?\n");
    scanf("%d", &n);
    printf("Give me numbers \n");
    for(i = 0; i < n; i ++){
        scanf("%d", &num[i]);
        if(num[i]<smallest) smallest = num[i]; //Find the smallest one from the values
    }

    while(smallest > 1 && gcd!=smallest){
        for(i = 0; i < n; i ++){
            if(num[i]%smallest != 0) break;//smallest is NOT common GCD
            if(i==n-1)   gcd = smallest;
        }
        if(gcd!=smallest)   smallest--;//Try luck with smaller possible GCD
    }

    printf("The common GCD is: %d", gcd);
    return 0;
}
