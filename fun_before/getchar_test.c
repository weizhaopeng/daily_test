#include <stdio.h>

int main(void) {
	char buf[10] = {0};
	for (int i = 0; i < 10; i++)
		buf[i] = getchar();
	
	printf("%s\n", buf);
	return 0;
}
