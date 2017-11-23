#ifndef STRUCT_H
#define STRUCT_H

#include"stdio.h"
 #include"stdlib.h"

static int count;	

struct stu
{
	char name[20];
	int num;
};
typedef struct stu STU;

struct node
{
	STU student;
	struct node *next;
};
typedef struct node NODE;

#endif
