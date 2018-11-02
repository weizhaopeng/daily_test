#include <stdio.h>

typedef struct str {
	int  a;
	char b;
} str;

int main(void) {
	str str_temp = {
		a:0,
		b:'a'
	};

	printf("%d, %c\n", str_temp.a, str_temp.b);
	return 0;
}
