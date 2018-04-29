#ifndef _FUN_IN_STRUCT_H_
#define _FUN_IN_STRUCT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *word;
	int   count;
	void (*word_print)(void);
	int  (*count_print)(void);
} data_store_object;

void WordPrint();
int CountPrint(void);


#endif

