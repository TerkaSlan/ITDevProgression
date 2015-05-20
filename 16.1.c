#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// while checking correctness of the code i was using http://jodies.de/ipcalc

int power(int base, int expo){
    if(expo==0)  return 1;
    return base*power(base, expo-1);
}

int main(){

    unsigned i=0, j=0, k=0, l=0, placesLeft=0, newSubnet=0;
    int subnetMask=0, subnetMask2=0, ip[4], ip2[4];
    char input[20] = "192.168.0.1/6\n";               //dories 2. input
    char input2[20] = "193.12.4.1/6\n";
    printf("Enter an IP address in the form 192.168.0.1/24\n");
    //fgets(input,19,stdin);
    if(strcmp(input,input2)==0) {printf("\n\nTwo computers on the cannot have the same network cannot have the same IP"); return 0;}
    char *pInput = &input[strlen(input)-2];             // points to the end
    for(i=0; i<4; i++)  {ip[i]=0;    ip2[i]=0;}         // cleaning the dump
    i=0;
    while(*pInput!='/'){                                // getting the subnetMask
        subnetMask = subnetMask + (*pInput - '0')*power(10,i);
        pInput--; i++;
    }pInput--;i++;
    if(subnetMask<1 || subnetMask>32)   {printf("\nWrong subnet mask, try again"); return -1;}

    for(j=0; j<4; j++){                                 //separate ip to 4 variables in ip array
        while((*pInput != '.') && (*pInput>='0' && *pInput<='9')){
            ip[j] = ip[j] + (*pInput - '0')*power(10,k);
            pInput--; i++; k++;
        }
    pInput--;i++; k=0;
    }

    int range = subnetMask/8 +1;                        //determine at what quartile the SM is important for me (then lower quartiles have to match exactly)
    for(i=0; i<subnetMask - 8*(range-1); i++){
        newSubnet = newSubnet + power(2,7-i);           //[e.g] SM=27 gives me 4th quartile and 224(128+64+32)
    }
    int wildcard = 255 - newSubnet;                     // the difference betw. lowest and highest acceptable ip
    int anding = ip[3-range+1]&newSubnet;               // omitting anding on lower quart.,
    int hostMin = anding;
    int hostMax = anding + wildcard;
    i=0;
    //Checking the second input
    pInput = &input2[strlen(input2)-2]; //going from the end e.g. SM=27, range = 4 -record numbers after /
    while(*pInput!='/'){
        subnetMask2 = subnetMask2 + (*pInput - '0')*power(10,i);
        pInput--; i++;
    }pInput--;i++;
    if(subnetMask2 != subnetMask)   {printf("\nSubnet Masks don't match, the computers are not on the same network"); return 0;}

    i=0; k=0;
    for(j=0; j<4; j++){                //separate ip2 to 4 variables in ip array
        while((*pInput != '.') && (*pInput>='0' && *pInput<='9')){
            ip2[j] = ip2[j] + (*pInput - '0')*power(10,k);
            pInput--; i++; k++;
        }
    pInput--;i++; k=0;
    }

    // Look for error, hostMin + hostMax apply to given qu. only, the last number cannot be 0 and all the qu. before have to match exactly
    if(range==1){
        if((ip2[3] > hostMax || ip2[3]< hostMin) || (ip2[0]==0)){  printf("\nThese 2 computers are not on the same network");  return 0;}
    }
    if(range==2){
        if((ip2[2] > hostMax || ip2[2]< hostMin) || (ip2[0]==0)){  printf("\nThese 2 computers are not on the same network");  return 0;}
        if(ip2[3] != ip[3])                    {  printf("\nThese 2 computers are not on the same network");  return 0;}
    }
    if(range==3){
        if((ip2[1] > hostMax || ip2[1]< hostMin) || (ip2[0]==0)){  printf("\nThese 2 computers are not on the same network");  return 0;}
        if((ip2[3] != ip[3])||(ip2[2] != ip[2])){ printf("\nThese 2 computers are not on the same network");  return 0;}
    }
    if(range==4){
        if((ip2[0] > hostMax || ip2[0]< hostMin) || (ip2[0]==0)){  printf("\nThese 2 computers are not on the same network");  return 0;}
        if((ip2[3] != ip[3])||(ip2[2] != ip[2]) ||(ip2[1] != ip[1])){ printf("\nThese 2 computers are not on the same network");  return 0;}
    }

    printf("\nThese 2 computers are on the same network");
    return 0;
}
