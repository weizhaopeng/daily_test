#include<stdio.h>
typedef int INT;
int bltest(void)
{
auto int a ;
static int x;
a++;
x++;
//printf("a=%d\nx=%d\n",a,x);
//return a;
return a;
}
INT main()
{
const int CN=5;
register int i,j,k;
enum alipay{name,age=12,famale=0,money=255,beizhu};
char n;
INT m=4;
enum alipay user1;
user1=age;
for (i=0 ; i<5 ; i++)
printf("%d\n",bltest());
printf("age=%d\n",(float)user1);
printf("num n=%d\n",m);
printf("please intput a char\n");
printf("nihao:\t");
scanf("%s",&n);
printf("nihao\nnishibushi\tyoubinga\vbushi a yexujiushi \n");
printf("杨晓涵推送的内容%d 0 o\n",CN);
printf("魏朝鹏推送的内容\n");
return 0;
}
