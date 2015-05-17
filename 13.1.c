#include <stdio.h>
#include <stdlib.h>

int power(int base, int expo){
    if(expo==0) return 1;
    return base*power(base, expo-1);
}

int main()
{
    int short i, number, digits[4], result=0;
    for(i=0; i<4; i++)  digits[i] = 0;
    printf("Enter a number in the range 100 to 10000\n\n");
    scanf("%d", &number);
    if(number<100 || number>10000)  {printf("\nInvalid input"); return -1;}

    for(i=0; i<4; i++){                     // e.g. 153
        digits[i] = number%power(10,i+1);   // digits[1] = 53
        if(i>0) digits[i] = (digits[i] - digits[i-1])/power(10,i);  //(53 - 3)/10 = 5
        if(number/1000 > 0)  result = result + power(digits[i],4);
        else                {result = result + power(digits[i],3);}
    }

    if(number == result)    printf("\n%d is a narcissistic number", number);
    else                    {printf("\n%d is not a narcissistic number", number);}
    return 0;
}
