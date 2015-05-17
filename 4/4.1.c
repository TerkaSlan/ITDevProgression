/*Create a program, which reads from an input (a file or keyboard) VISA credit card number, and
determines its validity. To be valid, the number must comprise 16 digits and pass the Luhn algorithm.
The Luhn algorithm steps are as follows:
1. From the rightmost digit, moving left, double the value of every second digit; if the product of
this doubling operation is greater than 9 (e.g., 8 × 2 = 16), then sum the digits of the products
(e.g., 16: 1 + 6 = 7, 18: 1 + 8 = 9).
2. Take the sum of all the digits.
3. If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid; else it is
not valid*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doubleEveryOther_sumAllDigits(int *num){
    short unsigned int count=0, tmp;
    int sum=0;
    while(count<8){
        *num = *num*2;
        if(*num>9){ // sum of the digits
            tmp = *num%10;
            *num = *num/10 + tmp;
        }
        num-=2;
        count++;
    }
    num++;
    //summing all digits
    for(tmp=0; tmp<15; tmp++){
        sum = sum + *num;
        num++;
    }
    if(sum%10==0)   printf("\n\nYour card is valid!");
    else            {printf("\nThis is not a valid card");}
    return;
}

int main()
{
    char char_numbs[17];
    int numbs[16];
    printf("Write your card number, no spaces\n");
    fgets(char_numbs,17,stdin);
    int a = strlen(char_numbs);
    if(strlen(char_numbs)!=16)  return -1;
    int i=0;
    for(i=0; i<16; i++){
        numbs[i] = char_numbs[i] - '0';
        printf("%d  ", numbs[i]);
    }
    printf("\n\n\n");
    //passing the address of 2nd rightmost digit
    doubleEveryOther_sumAllDigits(&numbs[14]);

    return 0;
}
