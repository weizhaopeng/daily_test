#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	void *p  = malloc(sizeof(char)*10);
	char *p1 = malloc(sizeof(char)*10);
	char *p2 = (char*)p;

	printf("char sizeof:%ld%ld\n", sizeof(char), sizeof(void));
	printf("%p\n", p);
	printf("size_t = %ld, ssize_t = %ld\n", sizeof(size_t), sizeof(ssize_t));
	
	p  = memset(p2, 'a', 10);
	p1 = memset(p1, 'a', 10);
	
	printf("%c, %c\n", p2[1], p1[1]);
	free(p);
	free(p1);

	return 0;
}
	
