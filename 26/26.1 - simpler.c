#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flats{
    char address[20];
    unsigned price;
    unsigned area;
}tFlat;

int main(){

    int k;
    tFlat flat[100];
    for(k=0; k<100; k++)    {flat[k].address[0]='\0';}
    FILE *fp = fopen("example.txt","r");
    fseek(fp,0,SEEK_END);
    int filesize = ftell(fp);
    fseek(fp,0,SEEK_SET);
    char *buf = malloc(sizeof(char)*filesize);
    fread(buf,1,filesize,fp);
    fclose(fp);

    int count=0,i=0,j=0;    k=0;
    char tempArea[20],tempPrice[20], tempAddress[20];
    memset(tempArea,'\0', 20);  memset(tempPrice,'\0', 20); memset(tempAddress,'\0', 20);
    while(count<filesize){
        while(*buf!='\n' && count<filesize){
            if(i==0)    {tempArea[j]=*buf;      j++;}
            if(i==1)    {tempPrice[j]=*buf;     j++;}
            if(i==2)    {tempAddress[j]=*buf;   j++;}
            buf++;  count++;
        }
        j=0;

        i++;
        if(i==3){
            flat[k].area = atoi(tempArea);
            flat[k].price = atoi(tempPrice);
            strcpy(flat[k].address, tempAddress);
            memset(tempArea,'\0', 20);  memset(tempPrice,'\0', 20); memset(tempAddress,'\0', 20);
            i=0;
            k++;
        }
        i%=3;
        count+=2; buf++;
    }

    printf("\n\nFLAT DATABASE:\n");
    for(i=0; i<100; i++){
        if(flat[i].address[0]!='\0')    printf("[FLAT %d] is at %s, has %u m^2 and costs %u euros.\n", i+1, flat[i].address, flat[i].area, flat[i].price);
        else                            {break;}//there are i flats
    }

    int min,temp;

    for(k=0; k<i; k++){
        min=k;
        for(j=k+1; j<i; j++){
            if(flat[j].price < flat[min].price) min = j;
        }

        temp = flat[k].price;
        flat[k].price = flat[min].price;
        flat[min].price = temp;
    }

    printf("\n\nFLAT DATABASE AFTER THE SORT:\n");
    for(i=0; i<100; i++){
        if(flat[i].address[0]!='\0' && flat[i].area>=70)    printf("[FLAT %d] is at %s, has %u m^2 and costs %u euros.\n", i+1, flat[i].address, flat[i].area, flat[i].price);
        else{break;}
    }
    return 0;
}
