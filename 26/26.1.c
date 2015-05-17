#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct flat{
    char address[30];
    unsigned price;
    unsigned area;
}tFlat;

int power(int base, int expo){
    if(expo==0) return 1;
    return base*power(base, expo-1);
}

int makeNumber(int *p_array){
    int number=0, i=0,j=0;
    while(*p_array!=-1){//tempAreaPrice[0] will be always -1 -> stopping point
        number = number + *p_array*power(10,i);
        i++;
        p_array--;
    }

   return number;
}

int main()
{
    tFlat flatDatabase[100];
    int k;
    for(k=0; k<100; k++)    {flatDatabase[k].address[0]='\0';}  //sth i'll make use of at the end in printfing
    FILE *fp;
    fp = fopen("example.txt", "r");

    fseek(fp,0,SEEK_END);   // getting the file size
    int filesize=ftell(fp);
    fseek(fp,0,SEEK_SET);

    char *buffer, tempAddress[30];
    memset(tempAddress, '\0', 30);
    int i,j=1, counter=0, tempArea[15], tempPrice[15], area, price;
    for(i=0; i<15; i++) {tempArea[i] = -1; tempPrice[i] = -1;}
    i=0;    k=0;
    buffer = malloc(sizeof(char)*filesize);
    fread(buffer,1,filesize,fp);
    fclose(fp);

    while(counter < filesize){
        while(*buffer != '\n' && counter < filesize){
            if(i==0)    {tempArea[j] = *buffer-'0'; j++;}//first line = area -> digits into array, then made number by makeNumber function
            if(i==1)    {tempPrice[j] = *buffer-'0'; j++;}
            if(i==2)    {tempAddress[j-1] = *buffer; j++;}//j-1 because i don't need to keep address[0] -1
            buffer++;
            counter++;
        }
        if(i==0)    area = makeNumber(&tempArea[j-1]);
        if(i==1)    price = makeNumber(&tempPrice[j-1]);

        j=1;
        i++;
        if(i==3){//i have all the info to make a new entry
            strcpy(flatDatabase[k].address, tempAddress);
            flatDatabase[k].area = area;
            flatDatabase[k].price = price;
            k++;

            for(i=0; i<15; i++) {tempArea[i] = -1; tempPrice[i] = -1;} // erase everything
            memset(tempAddress, '\0', 30);
            i=0;
        }
        i%=3;
        counter+=2; buffer++;
    }
    printf("\n\nFLAT DATABASE:\n");
    for(i=0; i<100; i++){// i have 3 house entries, there will be 100 on maturita
        if(flatDatabase[i].address[0]!='\0')    printf("[FLAT %d] is at %s, has %u m^2 and costs %u euros.\n", i+1, flatDatabase[i].address, flatDatabase[i].area, flatDatabase[i].price);
        else{break;}
    }
    i++;//there are i flats now
    int l;
    unsigned temp;
    //insertion sort
    printf("[AFTER THE SORT]\n");
    for(k=0; k<i-1; k++){
        j=k;
        while(j>0 && flatDatabase[j].price < flatDatabase[j-1].price){
            temp = flatDatabase[j].price;
            flatDatabase[j].price = flatDatabase[j-1].price;
            flatDatabase[j-1].price = temp;

            temp = flatDatabase[j].area;
            flatDatabase[j].area = flatDatabase[j-1].area;
            flatDatabase[j-1].area = temp;

            strcpy(tempAddress,flatDatabase[j].address);
            strcpy(flatDatabase[j].address,flatDatabase[j-1].address);
            strcpy(flatDatabase[j-1].address,tempAddress);

            j--;
        }
    }
    for(i=0; i<100; i++){// i have 3 house entries, there will be 100 on maturita
        if(flatDatabase[i].address[0]!='\0')    printf("[FLAT %d] is at %s, has %u m^2 and costs %u euros.\n", i+1, flatDatabase[i].address, flatDatabase[i].area, flatDatabase[i].price);
        else{break;}
    }
    counter=1;
    printf("\n\n4 cheapest flats w/ area 70 at least\n");
    for(i=0; i<100; i++){// i have 3 house entries, there will be 100 on maturita
        if(flatDatabase[i].address[0]!='\0' && flatDatabase[i].area>70)    {printf("[FLAT %d] is at %s, has %u m^2 and costs %u euros.\n", i+1, flatDatabase[i].address, flatDatabase[i].area, flatDatabase[i].price); counter++;}
        if(counter==5){break;}
    }
    return 0;
}
