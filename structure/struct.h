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

NODE *link_list_creat();
void link_list_insert(NODE *head,int n);
void link_list_print(NODE *head);

#endif
