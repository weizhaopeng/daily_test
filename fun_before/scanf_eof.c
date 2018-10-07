#include <stdio.h>
#include <unistd.h>

int main(void) {
	char buf[100] = {0};
	char buf1[100] = {0};

	scanf("%s", buf);
	fflush(stdin);
	scanf("%s", buf1);

	printf("%s\n", buf);
	printf("%s\n", buf1);
	return 0;
}
