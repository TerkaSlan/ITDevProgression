#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int num){
    int temp = num, reverse=0;
    while (temp != 0)
    {
      reverse = reverse * 10;
      reverse = reverse + temp%10;
      temp    = temp/10;
    }
    if(reverse == num)  return true;
    else{               return false;}
}

int main()
{
    int number,backup;
    printf("Enter a number to check if it's a palindrome\n");
    scanf("%d", &number);
    if(isPalindrome(number))        printf("It's a palindrome\n");
    else{
        printf("Sorry, not a palindrome\n\n");
        backup = number;
        while(!(isPalindrome(number))){
            number++;
        }
        printf("The next greater palindrome is: %d\n", number);
        while(!(isPalindrome(backup))){
            backup--;
        }
        printf("The next lower palindrome is: %d", backup);
    }
    return 0;
}
