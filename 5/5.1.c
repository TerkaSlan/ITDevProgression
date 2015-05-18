#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char *buf;

    FILE *fp;
    fp = fopen("example2.txt", "r");
    fseek(fp,0,SEEK_END);
    int filesize = ftell(fp);
    fseek(fp,0,SEEK_SET);
    buf = malloc(sizeof(char)*filesize);
    fread(buf,1,filesize,fp);
    fclose(fp);

    int counter=0,i=0,j, nOfWords=0, nOfSentences=0;
    char currentWord[20];
    memset(currentWord,'\0', 20);//erase dump
    bool valid = false;
    while(counter < filesize){
        while(*buf!=' ' && *buf!='.' && *buf!=',' && *buf!='\n' && counter < filesize){
            currentWord[i] = tolower(*buf); //so i don't have to waste time w/ checking if capital letters are valid or not
            i++; counter++; buf++;
        }if(*buf=='\n') counter++;
        for(j=0; j<i; j++){
            if(!((currentWord[j] < 'a' || currentWord[j]>'z') && currentWord[j]!=39)){//39 = apostrophe, the only exception
                valid = true;
            }
            else{valid=false; break;}
        }if(valid)  nOfWords++;
        if(*buf=='.' && (currentWord[j-1] >= 'a' || currentWord[j-1]<='z') && j!=0)  nOfSentences++;//sentence checking
        memset(currentWord,'\0', 20);//erase everything
        i=0;    valid=false;
        buf++;  counter++;
    }
    printf("There are %d words and %d sentences", nOfWords, nOfSentences);

    return 0;
}
