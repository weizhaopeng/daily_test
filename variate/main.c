#include "test.h"

int main(int argc, char *argv[])
{
	global_variate = 10;
	printf("%d\n",global_variate);

	fun_a();
	fun_b();

	return 0;
}

