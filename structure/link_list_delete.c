#include"struct.h"
void link_list_delete(NODE **head,int delete_posi)
{
	NODE *node_temp=*head,*node_deleted;
	
	if(delete_posi==1)
	{	
		node_deleted=*head;
		*head=(*head)->next;
	}	/*如果删除的是第一个结点*/
	else
	{	
		for(int i=1;i<delete_posi-1;i++)
		node_temp=node_temp->next;
		
		if(node_temp->next->next==NULL)
		{
			node_deleted=node_temp->next;
			node_temp->next=NULL;
		}
		else
		{		
			node_deleted=node_temp->next;
			node_temp->next=node_deleted->next;
		}
	}

	free(node_deleted);
}
	
	 
	
