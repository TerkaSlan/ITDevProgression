#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXCOUNT 10000

void InsertToHeap(int *pHeap, int newValue, int count){

    int position = count, temp;
    if(position==0)     {*pHeap = newValue;  return;}//If inserting root, don't bother with the rest of the code
    int *pHeapChild = pHeap;
    pHeapChild+=count;
    *pHeapChild = newValue;
    int *pHeapParent = pHeap+=((position-1)/2);//pHeap for 1,2      1 for 3,4   ....
    while(position > 0 && *pHeapChild > *pHeapParent){
            temp = *pHeapChild;         //switch the values
            *pHeapChild = *pHeapParent;
            *pHeapParent = temp;

            position = (position-1)/2;

            pHeapChild = pHeapParent;//switch the addresses so that *pHeapChild > *pHeapParent will work
            pHeapParent = pHeapParent-=position;

    }

    printf("\n");
    return;
}

void display(int *pToHeap){
    printf("The final look:\n");
    while(*pToHeap != INT_MAX){
        printf("%d\n", *pToHeap);
        pToHeap++;
    }
}
    //delete netreba
/*void DeleteFromHeap(int newValue){

    int result = heap[0], position=0;
    heap[0] = heap[--count] // nie heap[count--] !!!!!!!!!

    while(position < count){
        if(count > position*2 +2){ //ma uzol 2 potomkov?
            int posMax = heap[pocition*2 +1], temp;
            posMax = heap[position*2+2] > heap[position*2 +1] ? position*2 +1 : position*2 + 2;
            if(heap[posMax] > heap[position)
            {
                temp = heap[position];
                heap[position] = heap[posMax];
                heap[posMax] = temp;
                position = posMax;
            }

        }
        else{
            if(position*2+1 >= count){break;}
            else{
                int posMax = position, temp;
            posMax = heap[position*2+2] > heap[position*2 +1] ? position*2 +1 : position*2 + 2;
            if(heap[posMax] > heap[position)
            {
                temp = heap[position];
                heap[position] = heap[posMax];
                heap[posMax] = temp;
                position = posMax;
            }
            }
        }
    }

    count++;
}*/

int main()
{
    int i, heap[MAXCOUNT],temp;
    short unsigned nOfElements;
    for(i=0; i<MAXCOUNT; i++){
        heap[i] = INT_MAX;      // i need to set original values to sth not likely to be the input
    }
    printf("How many elements do you want to insert?");
    scanf("%d", &nOfElements);

    for(i=0; i<nOfElements; i++){
        printf("Enter element no. %d\n", i+1);
        scanf("%d", &temp);
        InsertToHeap(heap,temp,i);
    }
    display(heap);
    return 0;
}
