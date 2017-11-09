#include<stdio.h>
int *search(int *p)
{
	int *p1=p;
	for(int i=0;i<4;i++)
	{
		if (*(p1+i)<60)
		return p;
	}
	*p1=0;
	return p1;
}		
int main(void)
{
	int score[][4]={{66,44,66,66},{66,66,66,66},{55,66,66,66},{66,66,66,66}};
	int *p1;
	for (int i=0;i<4;i++)
	{
		p1=search(score[i]);
		if(*p1)
		printf("不及格的学生是%d，成绩为：%d %d %d %d\n",i+1,*(p1+0),*(p1+1),*(p1+2),*(p1+3));
	}
return 0;
}	
