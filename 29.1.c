#include <stdio.h>

typedef struct bracket{
    char data;
    struct bracket *next;
} tBracket;

int isEmpty(tBracket **top){//** na head
    if(*top == NULL)    return 1;   //stack is empty
    else{   return 0;}              //stack is not empty
}

void printError(char *reason){//ktory znak nesedi
    printf("\n------------------\nYour expression is not correct !");
    printf("\n\n ' %c ' is the thing i have problem with", *reason);
    return;
}

int pop(char symbol, tBracket **top){
    if(isEmpty(*top))   return 0;//ak je stack prazdny, funkcia konci
    else{
    tBracket *temp = *top;//docasny pointer na head
    *top           = temp->next;//obsah head sa prepisuje na dalsiu node, cim stratim pozadovanu node
    free(temp);
    return 1;}
}

void insert(char x, tBracket **top){
    tBracket *temp = malloc(sizeof(tBracket));
    temp->data =    x;
    temp->next =    *top;//temp->next berie to, co je v head
    *top       =    temp;//obsah head sa prepisuje, aby ukazoval na novu node
    return 0;
}

int main()
{
    int counter[2] = {0,0};//poradie, jeden counter mi nestaci na urcenie hierarchie 3 urovni, 0 je stadium, do ktoreho sa chcem dostat na konci
    tBracket *head = NULL;
    tBracket *head2 = NULL;
    char *buffer;
    buffer = malloc(sizeof(char)*120);
    fgets(buffer,120,stdin);//nacitam input
    while(*buffer!='\n'){//prechadzam nim az po enter
        switch(*buffer){//zaujimaju ma iba zatvorky
            case '(':
                insert(*buffer, &head);//buffer je pointer, musim ho posunut ako *, &head posuvam, lebo **top berie dovnutra adresu head, nie hodnotu
                printf("\n %c added !", *buffer);   counter[0]++;
                break;
            case ')':
                if(isEmpty(&head)){//ziadne ( sa predtym nenapisalo, zly input
                    printError(buffer);
                    return -1;}
                if(pop('(', &head))   printf("\n %c deleted !", *buffer);   counter[0]--;// dostavam c[0]=0
                if(isEmpty(&head))   printf("The stack is now empty");
                break;
                // Using counter[0,1,2] to establish hierarchy of brackets, just for an inspiration
                //for the second part of the question, works though
            /*case '[':
                insert(*buffer, &head);
                printf("\n %c added !", *buffer);   counter[0]++;
                break;
            case ']':
                if(isEmpty(&head)){
                    printError(buffer);
                    return -1;}
                if(pop('[', &head)){
                   printf("\n %c deleted !", *buffer); counter[0]--;
                   if(isEmpty(&head) !=1 && counter[0]!=0){//2. uroven, ] ukoncujem 1. aj 2. uroven, c[0] nemoze byt iny nez 0
                        printf("\n\nNOT a correct equation");
                        return -1;
                       }
                }
                if(isEmpty(&head))   printf("The stack is now empty");
                break;
           case '{':
                insert(*buffer, &head);
                printf("\n %c added !", *buffer);   counter[1]++;
                break;
            case '}':
                if(isEmpty(&head)){
                    printError(buffer);
                    return -1;}
                if(pop('{', &head)){
                    printf("\n %c deleted !", *buffer); counter[1]--;
                   if(isEmpty(&head) !=1 && counter[0]!=0){
                        return -1;}
                }
                if(isEmpty(&head))   printf("The stack is now empty");
                break;
            //------------------OPERATORS-------------------//
            case '-':
                insert(*buffer, &head2);
                printf("\n %c added !", *buffer);
                printf("\n\n:-:\t%c", head2->data);
                break;
            case '+':
                insert(*buffer, &head2);
                printf("\n %c added !", *buffer);
                printf("\n\n:-:\t%c", head2->data);
                break;
            case '/':
                insert(*buffer, &head2);
                printf("\n %c added !", *buffer);
                printf("\n\n:-:\t%c", head2->data);
                break;
            case '*':
                insert(*buffer, &head2);
                printf("\n %c added !", *buffer);
                printf("\n\n:-:\t%c", head2->data);
                break;*/

        }
            buffer++;
    }
    if(isEmpty(&head) /*&& counter[0]==0 && counter[1]==0*/)   printf("\n\nCongrats, your equation is correct !");//oba c[] su 0
    else{printf("\n\nThere is something abundant, not a correct equation.");}
    return 0;
}
