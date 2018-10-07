#include <stdio.h>

typedef struct hashtable {
	int cap;
	struct unit{
		struct node {
			char *word;
			struct node *next;
		} *start;
		int num;
	} *unit;
}

int main(void) {
	hashtable ht;
	return 0;


		
