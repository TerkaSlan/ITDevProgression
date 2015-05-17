#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct students{
    char name[30];
    unsigned short result;
}tStud;

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
    tStud studentDatabase[300];
    int k;
    for(k=0; k<100; k++)    {studentDatabase[k].name[0]='\0';}  //sth i'll make use of at the end in printfing
    FILE *fp;
    fp = fopen("example.txt", "r");

    fseek(fp,0,SEEK_END);   // getting the file size
    int filesize=ftell(fp);
    fseek(fp,0,SEEK_SET);

    char *buffer, tempName[30];
    int i,j=1, counter=0, tempResult[10], result=0;
    for(i=0; i<10; i++) {tempResult[i] = -1;}
    i=0;    k=0;
    buffer = malloc(sizeof(char)*filesize);
    fread(buffer,1,filesize,fp);
    fclose(fp);

    while(counter < filesize){
        while(*buffer != '\n' && counter < filesize){
            if(i==0)    {tempName[j-1] = *buffer; j++;}//first line-> digits into array, then made number by makeNumber function
            if(i==1)    {tempResult[j] = *buffer-'0'; j++;}//j-1 because i don't need to keep address[0] -1
            buffer++;
            counter++;
        }
        if(i==1)    result = makeNumber(&tempResult[j-1]);

        j=1;
        i++;
        if(i==2){//i have all the info to make a new entry
            strcpy(studentDatabase[k].name, tempName);
            studentDatabase[k].result = result;
            k++;

            for(i=0; i<10; i++) {tempResult[i] = -1;} // erase everything
            memset(tempName, '\0', 30);
            i=0;
        }
        i%=2;
        counter+=2; buffer++;
    }
    printf("\n\STUDENT DATABASE:\n");
    for(i=0; i<100; i++){// i have 3 house entries, there will be 100 on maturita
        if(studentDatabase[i].name[0]!='\0')    printf("[STUDENT %d] Name: %s, Points: %u \n", i+1, studentDatabase[i].name, studentDatabase[i].result);
        else{break;}
    }
    i++;//there are i students now
    int l;
    unsigned temp;
    //insertion sort
    printf("[AFTER THE SORT]\n");
    for(k=0; k<i-1; k++){
        j=k;
        while(j>0 && studentDatabase[j].result < studentDatabase[j-1].result){
            temp = studentDatabase[j].result;
            studentDatabase[j].result = studentDatabase[j-1].result;
            studentDatabase[j-1].result = temp;

            strcpy(tempName,studentDatabase[j].name);
            strcpy(studentDatabase[j].name,studentDatabase[j-1].name);
            strcpy(studentDatabase[j-1].name,tempName);

            j--;
        }
    }
    counter=1;
    printf("\n\n30 students that will be accepted:\n\n");
    for(j=i-2; j>i-2-30; j--){
        printf("%s, who has %u points.\n", studentDatabase[j].name, studentDatabase[j].result);
    }
    return 0;
}
