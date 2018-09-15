#include <stdio.h>
#include <sys/mman.h>

int main (int argc, char **argv) {
	void *p = NULL;
	long  len = 1024*1024*1024;

	p = mmap(NULL,len, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	printf("%p\n", p);

	munmap(p, len);
	return 0;
}
