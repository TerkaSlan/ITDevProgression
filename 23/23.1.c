#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,result=1;
    char x, tempphoneNumber[11], phoneNumber[9], temp[9];
    printf("Enter the phone number you'd like to check\n");
    fgets(tempphoneNumber, 11, stdin);
    for(i=0; i<9; i++){ //shifting the number so it starts w/ 9
        phoneNumber[i] = tempphoneNumber[i+1];
    }

    FILE *fp;
    fp = fopen("phoneNumbers.txt", "r");
    char character, preprevious;
    i=0;
    while((character=fgetc(fp))!=EOF){
        if(character == '\n')   {i=0;}
        else{
            temp[i] = character;
            i++;
        }
        if(i==9){
            result = strncmp(phoneNumber, temp, 9);
            if(result==0){//a match was found
                break;
            }
        }
    }
    fclose(fp);
        if(result==0){printf("\nThis phone number was found, it's not available !");}
        else         {printf("\nThis phone number is available !");}
    return 0;
}
