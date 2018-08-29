#include <stdio.h>

void fun(int in) {
	static int e;
	e = 10;
	e += in;
	printf("%d\n", e);
}

int a;
int c = 30;
int main(void) {
	//test the variate's address is or not changed after the init
	static int b;
	static int d = 20;
	printf("%p\t%p\t%p\t%p\n", &a, &b, &c, &d);
	a = 11;
	b = 22;
	printf("%p\t%p\t%p\t%p\n", &a, &b, &c, &d);

	printf("%d,%d\n", b, d);
	b = 33;
	d = 30;
	printf("%d,%d\n", b, d);

	fun(10);
	fun(20);
	return 0;
}
