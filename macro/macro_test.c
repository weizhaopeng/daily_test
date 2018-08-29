#include <stdio.h>
#include <string.h>

#define NIHAO "nihao"
#define NIHAOMA NIHAO   "ma"

int main(int argc, char *argv[]) {
	printf("%s\n", NIHAO);
	printf("%s\n","nihao""\0ma");

	return 0;
}

