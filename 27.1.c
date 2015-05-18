#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Cars{
    char *brand;
    char *type;
    short unsigned year;
    char *color;
    short unsigned power;
    short unsigned nOfDoors;
    struct Cars *next;      //linked list implementation - i don't know how man will be added
}tCar;

void addItem(tCar **pToHead, char *brand, char *type, short unsigned year, char *color, short unsigned power, short unsigned nOfDoors){
    tCar *temp = malloc(sizeof(tCar));
    temp->brand = brand;
    temp->type = type;
    temp->color = color;
    temp->year = year;
    temp->power = power;
    temp->nOfDoors=nOfDoors;
    temp->next = *pToHead;
    *pToHead = temp;
    return;
}

void print(tCar **pToHead){
    tCar *temp;
    temp = *pToHead;
    short unsigned i=1;
    while(temp!=NULL){i++;  temp = temp->next;} // so that the entry number matches the order
    temp = *pToHead;    i--;
    while(temp!=NULL){
        printf("[ENTRY %u]:\n", i);
        printf("Brand: %s\nType: %s\nYear: %u\nColor: %s\nPower: %u\nNumber of doors: %u\n\n",temp->brand, temp->type, temp->year, temp->color, temp->power, temp->nOfDoors);
        i--;
        temp = temp->next;
    }
    return;
}

void printBasedOnColor(tCar **pToHead,char *color){
    tCar *temp;
    temp = *pToHead;
    bool matchFound=false;
    short unsigned i=1;
    while(temp!=NULL){i++;  temp = temp->next;}
    temp = *pToHead;    i--;
    while(temp!=NULL){
        if(strcmp(color, temp->color)==0){
            printf("\nWe found a match !\n"); matchFound=true;
            printf("[ENTRY %u]:\n", i);
            printf("Brand: %s\nType: %s\nYear: %u\nColor: %s\nPower: %u\nNumber of doors: %u\n\n",temp->brand, temp->type, temp->year, temp->color, temp->power, temp->nOfDoors);
        }
        i--;
        temp = temp->next;
    }
    if(!matchFound) printf("\nSorry, there is no such car in our database");
    return;
}

void printBasedOnBrand(tCar **pToHead, char *brand){
    tCar *temp;
    temp = *pToHead;
    bool matchFound=false;
    short unsigned i=1;
    while(temp!=NULL){i++;  temp = temp->next;}
    temp = *pToHead;    i--;
    while(temp!=NULL){
        if(strcmp(brand, temp->brand)==0){
            printf("\nWe found a match !\n"); matchFound=true;
            printf("[ENTRY %u]:\n", i);
            printf("Brand: %s\nType: %s\nYear: %u\nColor: %s\nPower: %u\nNumber of doors: %u\n\n",temp->brand, temp->type, temp->year, temp->color, temp->power, temp->nOfDoors);
        }
        i--;
        temp = temp->next;
    }
    if(!matchFound) printf("\nSorry, there is no such car in our database");
    return;
}

void throwAway(tCar **pToHead){
    tCar *temp;
    temp = *pToHead;
    *pToHead = temp->next;
    return;
}

int main()
{
    tCar *head = NULL;
    addItem(&head, "Opel", "Astra", 2001, "silver", 75,4);
    addItem(&head, "BMW", "X5", 2009, "black", 95,2);
    addItem(&head, "Skoda", "Favorit", 1990, "red", 48,4);

    //Fuck playing with the input, no time for that on maturita
    print(&head);
    throwAway(&head);
    printf("\nAfter the deletion:\n\n");
    printBasedOnBrand(&head, "BMW");
    return 0;
}
