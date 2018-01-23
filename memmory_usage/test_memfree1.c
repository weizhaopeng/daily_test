#include"test_memfree.h"

void fun1()
{
	extern char *array1;
	printf("%s\n",array1);
}
char *array1="nihao";

int main (void)
{
	fun1();
	fun2();

	return 0;
}


