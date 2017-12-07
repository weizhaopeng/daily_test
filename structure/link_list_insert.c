#include"struct.h"
void link_list_insert(NODE *head,int n)
{
	NODE *new,*temp;

	new=(NODE *)malloc(sizeof(NODE));
	if (new==NULL)
	{
		puts("memory allocation failed");
		exit(-1);
	}

	puts("请输入学生姓名和学号：\n；例如：魏朝鹏 15011630");
	scanf("%s%d",new->student.name,&new->student.num);
	
	temp=head;	
	if (n==1)
	{
		new->next=head;
		head=new;
	}
	else
	{
		for (int i=1;i<n-1;i++)
			temp=temp->next;
		if(temp->next==NULL)
		{	
			temp->next=new;
			new->next==NULL;
		}
		else
		{
			new->next=temp->next;
			temp->next=new;
		}
	}
}	
			
