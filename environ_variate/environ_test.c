#include <stdio.h>
#include <stdlib.h>

int main(void) {
	extern char ** environ;
	for (int i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);

	printf("java的home目录是：%s\n", getenv("JAVA_HOME"));
	return 0;
}
