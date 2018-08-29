#include <stdio.h>

#define PRINT_ADD(x, y) printf(#x"+"#y"\n");
#define CONNECT(x, y) x##y
void fun(void) {
	#define IS_PRINT
	#ifdef IS_PRINT
	printf("is print\n");
	#else

	printf("is not print\n");
	#endif
	#undef IS_PRINT
}

int main(void) {
	PRINT_ADD("nihao", "yangxiaohan");
	int a = 12, b = 20, ab = 25;
	printf("ab=%d\n", CONNECT(a, b));

	#ifdef IS_PRINT
	printf("in the main is print");
	#endif
	fun();
	#ifdef IS_PRINT
	printf("in the main is print");
	return 0;
	#endif
}
