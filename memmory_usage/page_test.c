#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
	char 	 a;
	short 	 b;
	int   	 c;
	double	 d;
	long int f;
} node;

int main(int argc, char **argv) {
	printf("linux操作系统的页大小是：%d\n", getpagesize()/1024);
	int ret = 0;
	
	node *node1 = calloc(1, sizeof(node));
	node1->a = 'a';
	node1->b = 111;
	node1->c = 12222222;
	node1->d = 1212.33333;
	node1->f = 1212121212333;
	printf("结构体的长度是:%ld\nshort类型所在的逻辑地址是：%p\n", sizeof(node), (void*)node1->b);
	printf("%d\n", node1->b);
	

	ret = posix_memalign(&node1, 16, sizeof(node));
	if (ret != 0) {
		perror("posix_memalign");
		exit(-1);
	}
	node node2 = {12, 111, 222, 333, 444};
	printf("结构体的长度是:%ld\nshort类型所在的逻辑地址是：%p\n", sizeof(node), (void*)node1->b);
	printf("%d\n", node2.b);

	free(node1);
	return 0;
}

