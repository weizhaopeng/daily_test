#include"stdio.h"
#include"stdlib.h"
int main(void)
{
char a;
int n=15,x=15,y=-15,z=16,w;
//itoa(z,w,2);
printf("请输入五个字符\n");
/*for(w=0;w<5;w++)
getchar(*(a+w));
for(w=0;w<5;w++)
putchar(*(a+w));*/
a=getchar();
putchar(a);
putchar('\n');
printf("bianhuanhou=%d\n",~n);
printf("luoji=%d\n",n&10);
printf("右移+=%d\n右移-=%d\n",x>>=2,y>>=2);
printf("z=%d\n",sizeof(int));
return 0;
}
