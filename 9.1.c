#include <stdio.h>
#include <stdlib.h>

void convert(unsigned number, unsigned base){
    int i,j, temp[100];
    for(i=0; i<100; i++)    temp[i]=-1;
    i=0;
    while(number != 0){
        temp[i] = number%base;
        number= number /base;
        i++;
    }
    if(base==2) printf("\nThe number in Binary is:\n\n");
    if(base==16) printf("\nThe number in Hexadecimal is:\n\n");
    for(j=i-1; j>=0; j--){
        switch(temp[j]){
        case 10:
            printf("A ");
            break;
        case 11:
            printf("B ");
            break;
        case 12:
            printf("C ");
            break;
        case 13:
            printf("D ");
            break;
        case 14:
            printf("E ");
            break;
        case 15:
            printf("F ");
            break;
        default:
            printf("%d ", temp[j]);
            break;
        }
    }
    return;
}

int main(){

    int numToConvert;
    char base;
    printf("Choose the base you want to convert to:\nHexadecimal -> h\nBinary -> b\n");
    scanf("%c", &base);
    printf("Enter the number:\n");
    scanf("%d", &numToConvert);
    if(numToConvert==0) printf("\nThe number in binary or hexadecimal is 0.");
    if(numToConvert<0)  printf("\nSorry, the number has to be positive");
    if(base=='h')   {convert(numToConvert, 16); return 0;}
    if(base=='b')   {convert(numToConvert, 2);  return 0;}
    else            {printf("Wrong input, try again.\n");    return -1;}
}
