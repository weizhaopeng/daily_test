#include "test.h"

void fun_b(void)
{
	extern int global_variate;

	global_variate = 30;
	printf("%d\n",global_variate);
	return;
}

