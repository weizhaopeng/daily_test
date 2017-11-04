#include<stdio.h>
void main (void)
{
	char *p="weizhaopeng";
	char *arr[5];
	int i;
	/*arr[0]="nihao";
	arr[1]="wo";
	arr[2]="jiao";
	arr[3]="weizhaopeng";*/
	for (i=0;i<5;i++)
	{
		printf("请输入第%d个字符串\n",i+1);
		scanf("%s",arr+i);
	}	
	for(i=0;i<5;i++)
	printf("%s",arr+i);
	printf("\n");

	for(i=0;*(p+i)!='\0';i++)
	printf("%c",*(p+i));
	printf("\n");
}

