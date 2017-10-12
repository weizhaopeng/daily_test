#include"stdio.h"
int main (void)
{
	int i=0,a;
	for (;i<10;i++)
	{
		printf("请输入一个0——3的数值\n");
		scanf("%d",&a);
		switch(a)
		{	
			case 0:
			printf("您输入的是0\n");
			//break;

			case 1:
			printf("您输入的是1\n");
			continue;

			case 2:
			printf("您输入的是2\n");
			break;
			
			case 3:
			printf("您输入的是3\n");
			break;

			default:
			printf("您输入的数值超出范围了\n");
		}
//	break;		
	}	
	return 0;
}


