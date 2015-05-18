#include <stdio.h>
#include <stdbool.h>

bool leapiness(unsigned short year){
    if(year%400 == 0)       return 1;
    else if(year%100 == 0)  return 0; // year is not/400 and /100 = NOT A LEAP YAER
    else if(year%4 == 0)    return 1;
    else                    return 0;
}

unsigned short previousLeap(unsigned short year){
    while(!leapiness(year))    {year--;}
    return year;
}

unsigned short followingLeap(unsigned short year){
    while(!leapiness(year))    {year++;}   //check until isLeap function doesn't return true
    return year;
}

int main()
{
    unsigned short year;

    printf("Enter a year to check if it is a leap year\n");
    scanf("%u", &year);

    if(!leapiness(year)){
        printf("\n\n%u is not a leap year\n", year);
        printf("The Previous one is %u\n", previousLeap(year));
        printf("The Following one is %u\n", followingLeap(year));
    }
    else{
        printf("\n\n%u is a leap year\n", year);
    }

    return 0;
}
