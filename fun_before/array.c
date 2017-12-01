#include"stdio.h"
int main(void)
{
int a,b,a1[]={1,2,3,4,5,6},a2[][4]={1,2,3,4,5,6},a3[2][2][2];
char arr1[10],arr2[10],arr3[10],arr4[10];
printf("请输入包含四个词的字符串\n");
scanf("%s%s%s%s",arr1,arr2,arr3,arr4);
system('cls');
printf("您输入的是:\n%s %s %s %s\n",arr1,arr2,arr3,arr4);
//printf("a=%d\nb=%d\n",a,b);
return 0;
}

