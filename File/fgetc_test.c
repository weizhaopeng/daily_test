#include<stdio.h>
#include"stdlib.h"

void main (void)
{
    char char_temp,array_temp[20];
    FILE *fp=fopen("file","r+");

    printf("%ld\n",ftell(fp));
    char_temp=fgetc(fp);
    printf("%c",char_temp);
    fscanf(fp,"%s",array_temp);
    printf("%ld\n",ftell(fp));
    printf("%s\n",array_temp);
    
    do{
        char_temp=fgetc(fp);
        printf("%c",char_temp);
    }while(char_temp==' ');

    printf("%ld\n",ftell(fp));

}
