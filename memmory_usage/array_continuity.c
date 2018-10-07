#include <stdio.h>

int main(void) {
	char array[2000] = {0};
	for (int i = 0; i < 2000; i++)
		printf("%p\n", array+i);
	return 0;
}
