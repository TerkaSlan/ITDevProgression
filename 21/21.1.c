#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int main(){

    FILE *fp;
    fp = fopen("example.txt", "r");
    fseek(fp,0L,SEEK_END);
    int counter=0, filesize = ftell(fp);
    fseek(fp,0L,SEEK_SET);

    char *buf, current[7];   memset(current,'\0',7);
    buf = malloc(sizeof(char)*filesize);
    fread(buf,1,filesize,fp);
    fclose(fp);

    int i, j,k, array[100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            array[j][i] = 0;
        }
    }
    i=0;

    int rowCount=*buf-'0';
    buf++;
    while(*buf==' ')   {buf++;}
    int columnCount=*buf-'0';
    buf+=2;
    k=0;
    for(j=0; j<rowCount; j++){
        while(*buf!='\n'){
            if((*buf>='0' && *buf<='9') || *buf=='-')               {current[i] = *buf; i++;}
            else if(current[0]!='\0')                  {array[j][k] = atoi(current); i=0; memset(current,'\0',7); k++;}
            buf++;
        }
        array[j][k] = atoi(current); i=0; memset(current,'\0',7);
        buf++; k=0;
    }

    int resultRow = INT_MIN, resultCol = INT_MIN;

    while(k!=rowCount){
        for(i=0; i<columnCount; i++){array[k][columnCount] = array[k][columnCount] + array[k][i];}
        k++;
    }k=0;
    while(k!=rowCount){
        if(array[k][columnCount] > resultRow)   resultRow = array[k][columnCount];
        k++;
    }k=0;
    while(k!=columnCount){
        for(i=0; i<rowCount; i++){array[rowCount][k] = array[rowCount][k] + array[i][k];}
        k++;
    }k=0;
    while(k!=columnCount){
        if(array[rowCount][k] > resultCol)   resultCol = array[rowCount][k];
        k++;
    }
    printf("\n\nThe highest value for columns is: %d\n\n", resultCol);
    printf("\n\nThe highest value for rows is: %d", resultRow);
    return 0;
}
