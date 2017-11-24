#include"struct.h"
int main (void)
{
	static int count;
	int n,posi;
	NODE *head,*temp;

	puts("请输入学生人数");
	scanf("%d",&count);

	head=link_list_creat();
	link_list_print(head);
	
	printf("请输入结点插入的位置（在第n个结点之前，n位于1~%d）",count+1);
	scanf("%d",&posi);
	link_list_insert(head,posi);
	link_list_print(head);	

	return 0;
}

