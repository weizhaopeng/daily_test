#include <stdio.h>

void print(void) {
	printf("hello");
}

typedef struct {
	int a;
	char b;
} node;
int main(void) {
	//直接使用变量类型
	typeof(int) a = 20;
	//使用变量
	char	   *str = "weizhaopeng";
	typeof(str) str1;
	//使用结构体变量
	node c;
	c.a = 20;
	c.b = 'a';
	typeof(c) node_temp;
	//使用数组类型
	char array[20] = "yangxiaohan";
	typeof(array) b;
	//使用函数
	print();
	typeof(print) print_t();
	print_t();


	printf("%d, %s, %d, %s", a, str, node_temp.a, array);
	printf("%p, %p", array, b);
	return 0;
}
