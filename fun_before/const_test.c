#include <stdio.h>

int main(void) {
	char string1[] = "nihao", string2[] = "zhenhao";
	
	const char *p1 = string1;
	char *const p2 = string2;
	//对于常量指针
	//string1[1] = 'w';
	//p1[1] 	   = 'w';
	string1[1] = 'z';
	printf("%s\n", string1);
	//string1 = string2;
	p1 = string2;
	printf("%s\n", p1);

	//对于指针常量
	string2[2] = 'w';
	printf("%s\n", string2);
	p2[2] = 'z';
	//p2 = string1;
	printf("%s\n", string2);
	return 0;
}
