#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace(char *pSen, char *pToReplace, char *pToPartOfSentence){
    char *ret = strstr(pSen, pToPartOfSentence);
    int i;
    for(i=0;i<strlen(pToPartOfSentence); i++){
        ret[i]=*pToReplace;
        pToReplace++;
    }
}

void lowercase(char *pSen){
    while(*pSen!='\n'){
        if(*pSen>='A' && *pSen<='Z') {*pSen = *pSen + 32;}
        pSen++;
    }
}

void capitalise(char *pSen){
    while(*pSen!='\n'){
        if(*pSen>='a' && *pSen<='z') {*pSen = *pSen - 32;}
        pSen++;
    }

}

int main()
{
    short unsigned i=0;
    char sentence[256], toReplace[256], partOfSentence[256];
    memset(sentence,'\0',256);
    printf("Enter the sentence:\n");
    fgets(sentence,256,stdin);
    printf("\n\nEnter the part of the sentence you want to replace:\n");
    fgets(partOfSentence,256,stdin);
    partOfSentence[strlen(partOfSentence)-1] = '\0'; //so it doesn't end w/ \n
    printf("\n\nEnter the text you want it to replace by (the lengths have to match):\n");
    fgets(toReplace,256,stdin);
    toReplace[strlen(toReplace)-1] = '\0';
    if(strlen(partOfSentence)!=strlen(toReplace))   {printf("\n\nThe lengths don't match");  return -1;}
    capitalise(sentence);
    printf("\n\n[AFTER CAPITALISATION]:\n");
    while(sentence[i]!='\n'){
        printf("%c", sentence[i]);
        i++;
    }i=0;
    lowercase(sentence);
    printf("\n\n[AFTER CONVERTING TO LOWERCASE]:\n");
    while(sentence[i]!='\n'){
        printf("%c", sentence[i]);
        i++;
    }i=0;
    replace(sentence, toReplace, partOfSentence);
    printf("\n\n[AFTER REPLACING]:\n");
    while(sentence[i]!='\n'){
        printf("%c", sentence[i]);
        i++;
    }
    return 0;
}
