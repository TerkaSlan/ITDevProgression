#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int power(int base, int expo){
    if(expo==0) return 1;
    return base*power(base, expo-1);
}

unsigned FibLoop(unsigned N, int *pToArray){
    unsigned x=1,y=1, sum=1;
    if(N==1)    return 1;
    if(N==2)    return 1;
    while(sum<N-1){
        sum = x + y;
        x = y;
        y = sum;
        *pToArray = sum;
        pToArray++;
    }
    return sum;
}

bool checkIfFibonacci(int *pToArray, int number){
    while(*pToArray<=number){
        if(number==*pToArray) return true;
        pToArray++;
    }
    return false;
}

int main()
{
    FILE *fp;
    char *buf;
    fp=fopen("example.txt","r");
    if(fp==0){  // if the file could not be opened
        printf("Error opening the file!");
        return -1;
    }

    fseek(fp,0,SEEK_END);   // getting the file size
    int filesize=ftell(fp), counter=0, j=0;
    fseek(fp,0,SEEK_SET);

    buf=(char*)malloc(filesize);    // allocating memory for the buffer
    fread(buf,1,filesize,fp);   // reading the whole file into the buffer

    fclose(fp); // close that file
    buf+=(filesize-5);
    unsigned fibonacci[20], tempNumber=0, sum=0;//20 is enough for FibNums up to 10K
    for(j=0; j<20; j++)  fibonacci[j]=0;
    FibLoop(10000,fibonacci);
    j=0;
    while(counter != filesize-4){
        if(*buf >='0' && *buf <='9'){
            tempNumber = tempNumber + (*buf-'0')*power(10,j);
            j++;
        }
        else{
            j=0;
            if(*buf == '\n' || *buf == ' '){
               if(checkIfFibonacci(fibonacci, tempNumber))  sum++;
            }
            tempNumber = 0;
        }
        counter++; buf--;
    }
    printf("\nThere are %u fibonacci numbers", sum);
    return 0;

}
