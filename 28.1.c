#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    unsigned short data;
    struct node *next;
} tNode;

void insert(tNode **pToHead, unsigned short x){
    tNode *temp = malloc(sizeof(tNode));//creating the node
    temp->data  = x;
    temp->next  = *pToHead;//i=0 - NULL, i>0 - *na predchadzajuci node
    *pToHead = temp;
    return;
}

void add(tNode **pToHead1, tNode **pToHead2, tNode **pToHeadResult){
    short unsigned carry=0;
    tNode *temp1;
    tNode *temp2;
    tNode *tempResult;

    temp1 = *pToHead1;
    temp2 = *pToHead2;
    tempResult = *pToHeadResult;

    while(temp1!=NULL){
        if((temp1->data + temp2->data <= 9) && carry==0){
           tempResult->data = temp1->data + temp2->data;
        }
        else if((temp1->data + temp2->data <= 8) && carry==1){
             tempResult->data = temp1->data + temp2->data + carry;  carry=0;
        }
        else if((temp1->data + temp2->data >= 9) && carry==1){
            tempResult->data = (temp1->data + temp2->data + carry)%10; //carry stays 1
        }
        else{tempResult->data = (temp1->data + temp2->data)%10;     carry=1;}
        temp1 = temp1->next;
        temp2 = temp2->next;
        tempResult = tempResult->next;
    }
    if(carry==1)    tempResult->data=carry;
    tempResult = tempResult->next;
    return;
}

void printNicely(tNode **pToHead){
    tNode *helper;
    helper = *pToHead;
    unsigned short i=1;
    char temp[256];
    printf("\n\nThe final result:\t");
    while(helper!=NULL){
        temp[i] = helper->data + '0';   //reversing the order so it displays correctly
        helper = helper->next;
        i++;
    }
    while(i>0){
        printf("%c",temp[i]);
        i--;
    }
    return;
}

void print(tNode **pToHead){
    tNode *helper;
    helper = *pToHead;
    printf("\nThe LL contains: \n\n");
    short unsigned i=1;
    while(helper!=NULL){
        printf("\n[NODE %d] Its address: 0x%x, data: %u, it points to: 0x%x\n",i, helper, helper->data, helper->next);
        helper = helper->next;
        i++;
    }
    printf("\n\n");
    return;
}

int main()
{
    tNode *head1 = NULL;
    tNode *head2 = NULL;
    tNode *result = NULL;
    unsigned short i;
    char number1[256], number2[256], temp[256];
    memset(number1,'\0', 256);
    memset(number2,'\0', 256);
    memset(temp,'\0', 256);
    printf("Enter the first number:\n");
    fgets(number1,255,stdin);
    printf("\nEnter the second number:\n");
    fgets(number2,255,stdin);

    if(strlen(number2)>strlen(number1)){
        strcpy(temp,number1);//backup
        for(i=0; i<strlen(number2)-strlen(number1); i++){
            number1[i] = '0';//0s at the beginning
        }number1[i] = '\0';
        strcat(number1,temp);
    }
    memset(temp,'\0', 256);
    if(strlen(number2)<strlen(number1)){
        strcpy(temp,number2);//backup
        for(i=0; i<strlen(number1)-strlen(number2); i++){
            number2[i] = '0';//0s at the beginning
        }number2[i] = '\0';
        strcat(number2,temp);
    }
    memset(temp,'\0', 256);//making sure temp's clean all the time
    i=0;
    while(number1[i]!='\n'){
        insert(&head1, number1[i]-'0');
        insert(&head2, number2[i]-'0');
        insert(&result, 0);
        i++;
    }
    insert(&result, 0);//allocation 1 extra node if i have carry at the beginning
    print(&head1);
    printf("\nHEAD 2:\n\n");
    print(&head2);

    add(&head1, &head2, &result);
    printf("\n\nAfter the adding:\n\n");
    print(&result);
    printNicely(&result);
    return 0;
}
