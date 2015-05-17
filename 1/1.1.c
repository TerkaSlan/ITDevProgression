#include <stdio.h>
#include <stdlib.h>
//Outline a flowchart and create a program, which calculates the sum of all numbers between A and B; A,B N; A ≤ B.
int main()
{
    unsigned a,b,i,result=0;        // limitation: capacity of result is 2^32-1 (4,3 billion)
    printf("The first number:\n");
    scanf("%u", &a);
    printf("\nThe second number:\n");
    scanf("%u", &b);
    if(a<b){
        for(i=a+1; i<b; i++)  {result = result+i;}
        printf("\n\nSum of all the numbers between %u and %u is %d.", a,b,result);
    }
    else if(a>b){
        for(i=b+1; i<a; i++)  {result = result+i;}
        printf("\n\nSum of all the numbers between %u and %u is %d.", b,a,result);
    }
    else{printf("\n\nSum of all the numbers between %u and %u is 0.", a,b);}

    return 0;
}