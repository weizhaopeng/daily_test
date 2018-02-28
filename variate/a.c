#include "test.h"

void fun_a(void)
{
	extern int global_variate;

	//global_variate = 20;
	printf("%d\n",global_variate);
	return;
}

