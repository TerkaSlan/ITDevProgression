#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void testing(unsigned int number){
    unsigned int product=1*2*3*4, i=1; // the lowest one
    while(product<UINT_MAX){
        if(product == number)   {printf("\n\n%u can be rewritten as %u * %u * %u * %u",number, i,i+1,i+2,i+3); return;}
        if(product > number)    {printf("\n\n%u cannot be rewritten in the form of 4 consecutive integers", number); return;}
        product = product/i*(i+4);//testing 2*3*4*5, then 3*4*5*6, ....
        i++;
    }
    return;
}

int main(){

    unsigned int number;
    printf("Enter a non/negative integer, max. %u\n", UINT_MAX);
    scanf("%u", &number);
    // the product of n consecutive integers is divisible by n factorial
    if(number%24==0)    testing(number);
    else{printf("%u cannot be rewritten in the form of 4 consecutive integers", number);}
    return 0;
}
