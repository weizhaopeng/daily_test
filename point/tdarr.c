#include<stdio.h>
int main(void)
{
	int arr[3][3],*p;
	p=arr;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{	
			printf("请输入%d行%d列元素:\n",i+1,j+1);
			scanf("%d",*(p+i)+j);
		}
	}
	p=arr;
	 for(int i=0;i<3;i++)
        {
                for(int j=0;j<3;j++)
                {
			printf("%-5d",*(p+i)+j);
                }
		printf("\n");
        }
	return 0;
}
