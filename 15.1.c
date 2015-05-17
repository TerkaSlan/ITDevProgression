#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int number) {
    unsigned int i,j=0;
    int divisors[1000];
    for(i=0; i<1000; i++)   divisors[i] = -1;
    for (i=2; i<=number; i++) {
        if (number % i == 0 && i != number) {divisors[j] = i;    j++;}
    }i=0;
    if(divisors[0]==-1)  return true;
    else{
        printf("\n%d is not prime. \nHere is the list of its divisors: \n", number);
        while(divisors[i]!=-1){
            printf("%d  ", divisors[i]);
            i++;
        }
        return false;
    }
}

int main(){

    int i,x, num;
    printf("Enter a number you want to check\n");
    scanf("%d", &num);
    if(num<0){
        printf("Invalid input");
        return -1;
    }
    if(isPrime(num)) printf("%d is totally prime\n", num);
    return 0;
}
