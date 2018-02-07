#include"test_memfree.h"

NODE *fun1()
{
	NODE arr[5]={"0"};
	NODE *list[5];

	for(int i=0;i<5;i++)
		list[i]=arr+i;
	
	return list;
}

int main (void)
{
	NODE *list[5];
	list=fun1();

	for(int i=0;i<5;i++)
		printf("%d\n",list[i]->a);

	return 0;
}


