#ifndef _FUN_IN_STRUCT_H_
#define _FUN_IN_STRUCT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *word;
	int   count;
	void (*word_print)(char *word);
	int  (*count_print)(int count);
} data_store_object;

void WordPrint(char *word);
int CountPrint(int count);


#endif

