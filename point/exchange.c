#include<stdio.h>
int main (void)
{
	int a,b;
	puts("请输入a,b\n");
	scanf("%d%d",&a,&b);
	int *p1,*p2;
	p1=&a;
	p2=&b;
	printf("a=%d,b=%d\n",*p1,*p2);
	int *temp;
	temp=p1;
	p1=p2;
	p2=temp;
	printf("a=%d,b=%d\n",*p1,*p2);
return 0;
}
