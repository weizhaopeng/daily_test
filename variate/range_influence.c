#include <stdio.h>
//全局变量
void function (void);

int 	   all_range_v = 1;
static int all_static_v = 2;

int main(void) {
	int v_in_func = 3;
	static int v_in_func_sta = 4;

	puts("in main\n");
	printf("all_range_v = %d\nall_static_v = %d\n", all_range_v, all_static_v);

	puts("in for\n");
	for (int index_for = 0; index_for < 5; index_for++) {
		int int_in_for = 0;
		static int sta_in_for = 11;
		int_in_for++;
		all_range_v++;
		all_static_v++;
		sta_in_for++;
		printf("v_in_for = %d\nall_range_v = %d\nall_static_v = %d\n, sta_in_for = %d\n",int_in_for, all_range_v, all_static_v, sta_in_for);
	}
	for (int i = 0; i < 4; i++) {
		if (1) {
			int int_if_v = 12;
			int_if_v++;
			static int sta_if_v = 14;
			sta_if_v++;
			printf("int_if_v = %d, sta_if_v = %d\n", int_if_v, sta_if_v);
		}
	}


	function();
	return 0;
}

void function (void) {
	puts("in function\n");
	printf("all_range_v = %d\nall_static_v = %d\n", all_range_v, all_static_v);
}
	
