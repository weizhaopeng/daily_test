#include"pretreat.h"

#define FUN1 99

int main (int argc, char **argv)
{
	#ifdef FUN1
	fun1();
	#endif

	#ifndef FUN2
	fun2();
	#endif

	#ifndef FUN1
	fun2();
	#elif FUN1 == 100
	fun1();
	#else
	fun2();
	#endif
	return 0;
}
