#include"stdio.h"
#include"string.h"
int main(void)
{
int i,n;
int a[16]={0};
system("cls");
printf("请输入一个十进制整数（0-32767)\n");
scanf("%d",&n);
for(i=16;i>1;i--)
{
a[i]=n%2;
n=n/2;
}
for(i=1; i<16 ; i++)
{
printf("%d",a[i]);
if(i%4==0)
printf(" ");
}
printf("\n");
return 0;
}

