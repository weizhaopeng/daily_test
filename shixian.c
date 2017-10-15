#include"stdio.h"
#include"head_file.h"
int main(void)
{
int a,b;
printf("请输入a\n");
scanf("%d",&a);
printf("请输入b\n");
scanf("%d",&b);
printf("a b中更大的数值是：%d",sort(a,b));
return 0;
}
