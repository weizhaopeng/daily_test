#include<stdio.h>
void main (void)
{
    char ch[20];
    FILE *fp=fopen("file","r+");
    
    fscanf(fp,"%s",ch);
    
    printf("%s\n%ld\n",ch,ftell(fp));
}

