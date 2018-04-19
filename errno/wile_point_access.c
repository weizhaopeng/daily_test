/*************************************************************************
	> File Name: wile_point_access.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Apr 2018 10:28:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include <errno.h>

typedef struct node {
    int a;
    int b;
}node;

int main() {
    extern int errno;
    node *n = NULL;

    n->a = 11;
    printf("%d\n", errno);
    perror("error");
    return 0;
}
