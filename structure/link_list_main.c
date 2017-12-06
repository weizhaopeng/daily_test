#include"struct.h"
int count;

int main (void)
{
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

	puts("删除结点：1——删除，0——跳过");
	int delete_judge;
	scanf("%d",&delete_judge);
	if(delete_judge)
	{	
		printf("请输入要删除第*个结点\n");
		int delete_posi;
		scanf("%d",&delete_posi);
		link_list_delete(head,delete_posi);
	}	
	link_list_print(head);
	return 0;
}

