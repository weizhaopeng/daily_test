#include<stdio.h>
main()
{
	char str1[20],str2[20],*p1,*p2;
	p1=str1;
	p2=str2;
	printf("input str1\n");
	gets(str1);
	printf("input str2\n");
	gets(str2);
	while(*p2)
	*p1++=*p2++;
	*p1='\0';
	printf("now str1 is:\n");
	puts(str1);
	printf("now str2 is:\n");
	puts(str2);
}

