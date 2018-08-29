#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	void *p = malloc(20);
	free(p);
	return 0;
}
