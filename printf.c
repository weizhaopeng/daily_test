#include"stdio.h"
int main(void)
{
int x=15,y=20;
char a='r',*atr="我是你的老父亲；",str[10]="我是你的老父亲；",arr1[10];
double c=15.163679;
printf("请输入一列字符串\n");
gets(arr1);
puts(arr1);
printf("x=\n%d\n%10d\n%-5d\n%ld\n",x,x,x,x);
printf("%o\n%5o\n%-2o\n%lo\n",y,y,y,y);
printf("%s\n%10.5s\n%-5s\n%s\n",atr,atr,atr,str);
printf("%x\n%10x\n%-5x\n%lx\n",y,y,y,y);
printf("%e\n%11.2e\n%g\n%-5.1e\n",c,c,c,c);




return 0;
}
