#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *string, short unsigned len){
    char temp, even[len/2 +1], odd[len +1];
    memset(even, 0, len/2 +1);
    memset(odd, 0, len/2 +1);
    short unsigned i=1, j=0, k=0;
    while(i!=len+1){
        if(i%2!=0)  {odd[j] = *string;  j++;}
        else        {even[k] = *string; k++;}
        i++;    string++;
    }
    strcat(odd,even);
    printf("%s", odd);
    return;
}

int main()
{
    char string[100];
    fgets(string,100,stdin);
    short unsigned len = strlen(string);
    encrypt(string,len);
    return 0;

}
