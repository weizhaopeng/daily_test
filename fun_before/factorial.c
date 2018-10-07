#include <stdio.h>
#include <time.h>

static inline long sum(int n);

int main(void) {
	int n = 0;
	clock_t start = clock(), result = 0;

	puts("input the n");
	scanf("%d", &n);
	result = sum(n);
	printf("result = %ld\n", result);
	printf("time is %ld\n", clock()-start);

	return 0;
}

#ifdef FACTORIAL
static inline long sum(int n) {
	if (n == 1)
		return 1;
	else
		return sum(n-1)*n;
}
#endif

#ifdef ITERATION
static inline long sum(int n) {
	long sum_all = 1;					//定义了存储的变量
	for (int i = 1; i <= n; i++)		//进行了实际迭代需要迭代的次数
		sum_all *= i;					//保留最原始的计算式
		return sum_all;					//最后返回结果
}
#endif
	
