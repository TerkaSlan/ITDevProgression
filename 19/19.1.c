#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    FILE* subor = NULL;
    char znak;
    subor = fopen("example.txt", "r");

    if(subor == NULL)
        return 1;
    bool display = true;
    while((znak = fgetc(subor)) !=EOF){
            if(znak == '<')                     {display = false; continue;}
            if(znak == '>' && display==false)   {display = true; continue;}
            if(display)         putchar(znak);
    }
    fclose(subor);

    return 0;

}
