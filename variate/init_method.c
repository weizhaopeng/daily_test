#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//整形数组初始化
	int array1[5] = {0};
	for (int i = 0; i < 5; i++)
		printf("%d ", array1[i]);
	puts("\n");

	char array2[5] = {'\0'};
		printf("%s", array2);
	puts("\n");

	double array3[5] = {0};
	for (int i = 0; i < 5; i++)
		printf("%lf ", array3[i]);
	puts("\n");

	char *array4 = calloc(1, sizeof(char)*5);
	printf("%s", array4);
	return 0;
}
