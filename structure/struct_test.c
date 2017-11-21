#include"stdio.h"
#include"stdlib.h"

static int count;	

struct stu
{
	int num;
	char name[20];
	char sex;
};
typedef struct stu STU;

struct node
{
	STU student;
	struct node *next;
};
typedef struct node NODE;

NODE *creat()
{
	NODE *head,*new,*tail;
	head=new=tail=(NODE *)malloc(sizeof(NODE));
	tail->next=NULL;
	puts("请输入学生的学号，姓名，性别：\n例如：15011630 魏朝鹏 m\n(男=m，女=f)");
	scanf("%d%s%c",&new->student.num,new->student.name,&new->student.sex);

	for(int i=1;i<count;i++)
	{
		new=(NODE *)malloc(sizeof(NODE));

	/*	if(new==NULL)
		{	
			puts("分配错误");
			exit(-1);
		}
*/
		tail->next=new;
		puts("请输入学生的学号，姓名，性别：\n例如：15011630 魏朝鹏 m\n(男=m，女=f)");
		scanf("%d%s%c",&new->student.num,new->student.name,&new->student.sex);
		
		tail=new;
		tail->next=NULL;
	}
	return head;
}	
int main (void)
{
	int n;
	NODE *head,*temp;

	puts("请输入学生人数");
	scanf("%d",&count);

	temp=head=creat();
	
	for(int i=0;i<count&&temp->next!=NULL;i++)
	{
		printf("%d\t%s\t%c\n",temp->student.num,temp->student.name,temp->student.sex);
		temp=temp->next;
	}	
	return 0;
}

