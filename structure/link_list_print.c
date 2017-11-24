#include"struct.h"
void link_list_print(NODE *head)
{
	NODE *temp;
	temp=head;
	
	while(temp!=NULL)
	{
		printf("学生姓名    学号\n%s\t",temp->student.name);
		printf("%d\n",temp->student.num);
		temp=temp->next;
	}
}

	
