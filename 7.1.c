#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int i=2;
    double angle=45.0, fraction=0, num=1.0, den=1.0, change=1.0;

    while(angle<-180){
        angle = angle+180;
    }
    while(angle>180){
        angle = angle-180;
    }
    angle = (angle*M_PI)/180;//converting to radians
    num = angle;
    fraction = angle;
    while(change>0.000001){
        num = num*angle*angle;// change between nth and n+1th element is x^2/i(i+1)
        den = den*(i+1)*(i);  
        if(i%4!=0){           // if odd, substact, otherwise add
            change = num/den;
            fraction = fraction - change;
        }
        else{change = num/den;
            fraction = fraction + change;}
        i+=2;
    }
    printf("%.3lf", fraction);
    printf("\nThe sin(x) function gives me %.3lf", sin(angle));

    return 0;
}
