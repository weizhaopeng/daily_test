#include<stdio.h>
void constr(char *a,char *b)
{	
	while(*a)
	a++;
	*a++=' ';
	while(*b)
	*a++=*b++;
	*a='\0';
}	
int main (void)
{
	char str1[20],str2[20],*p,*p1,*p2;
	p1=str1;
	p2=str2;
	printf("input str1:\n");
	gets(p1);
	printf("input str2:\n");
	gets(p2);
	printf("now the connectec string is :\n");
	constr(p1,p2);
	puts(p1);
return 0;
}	
