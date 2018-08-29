#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {
	/*
	srandom(20);
	for (int i = 0; i < 100; i++) 
		printf("%ld\n", 20+random()%80);
	*/
	int set[10] = {0};
	initstate(20, (char*)set, 40);
	for (int i = 0; i < 10; i++) 
		printf("%d\n", set[i]);
	
	return 0;
}
