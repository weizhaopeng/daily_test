/*测试线程同步：互斥量的方法
 *创建两个线程，同时访问一个数据，并且访问数据的时候需要等待几秒才推出解锁
 *后面的线程进行等待，查看相应的数据的值
 */
#include "thread.h"
		
void *function(void *argv);
void *function1(void *argv);
static inline int get_length  (const void *array_p);
static inline int set_elements(const void *array_p, void *(*oper_elements)(void *), void *argv);
static inline int get_element (const void *array_p, const int index);
static inline int set_element (const void *array_p, const int index, int new_value);

int main(void) {
	int 	  ret = 0;
	array_t  *at = NULL;
	pthread_t th1, th2, th3;
	struct timespec time_wait = {
		.tv_sec = 5,
		.tv_nsec = 0
	};

	at 		  = calloc(1, sizeof(array_t));
	at->array = calloc(1, sizeof(int)*100);
	at->length = 0;
	pthread_mutex_init(&at->mutex, NULL);
	ret = pthread_mutex_timedlock(&at->mutex, &time_wait);
	if (ret != 0) {
		printf("timedlock:%s\n", strerror(ret));
		return (-1);
	}

	//初始化数组
	puts("初始化数组内容:");
	for (int i = 0; i < LENGTH_ARRAY; i++) {
		at->array[i] = 1+(int)random()%100;
		printf("%d ", at->array[i]);
	}
	puts("");
	at->length = LENGTH_ARRAY;
	
	//创建线程
	pthread_create(&th1, NULL, function, at);
	puts("线程1创建成功");
	pthread_create(&th2, NULL, function, at);
	puts("线程2创建成功");
	pthread_create(&th3, NULL, function1, at);
	puts("线程3创建成功");

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);

	puts("初始化数组内容:");
	for (int i = 0; i < LENGTH_ARRAY; i++)
		printf("%d ", at->array[i]);
	puts("");

	pthread_mutex_destroy(&at->mutex);
	free(at->array); free(at);
	return 0;
}

void *function(void *argv) {
	array_t *at = argv;
	int		 ret = 0;

	ret = pthread_mutex_lock(&at->mutex);
	if (ret != 0) {
		printf("thread lock:%s\n", strerror(ret));
		return (NULL);
	}
	puts("加锁成功");
	for (int i = 0; i < at->length; i++) {
		at->array[i]++;
		printf("%d ", at->array[i]);
	}
	printf("\n");
	sleep(4);
	pthread_mutex_unlock(&at->mutex);
	puts("解锁成功");

	return (argv);
}

void *function1(void *argv) {
	array_t *at = argv;
	int ret = 0;

	sleep(4);
	ret = pthread_mutex_trylock(&at->mutex);
	if (ret == 0) {
	 	puts("加锁成功");
		for (int i = 0; i < at->length; i++) {
			at->array[i]++;
			printf("%d ", at->array[i]);
		}
		printf("\n");

		pthread_mutex_unlock(&at->mutex);
		puts("解锁成功");
	}
	else
		printf("th3:%s\n", strerror(ret));

	return argv;
}
//数组的操作函数
//获取数组的长度
static inline int get_length(const void *array_p) {
	array_t *at = (array_t*)array_p;
	int length_t = 0;

	pthread_mutex_lock(&at->mutex);
	length_t = at->length;
	pthread_mutex_unlock(&at->mutex);

	return (length_t);
}

//根据索引获取数组中的数值
static inline int get_element(const void *array_p, const int index) {
	array_t *at = (array_t*)array_p;
	int retval = 0;

	pthread_mutex_lock(&at->mutex);
	if (index >= at->length) {
		pthread_mutex_unlock(&at->mutex);
		retval = -1;
		errno = EINVAL;
	}
	else {
		retval = at->array[index];
		pthread_mutex_unlock(&at->mutex);
	}

	return (retval);
}

//修改数组中的单个值
static inline int set_element(const void *array_p, const int index, int new_value) {
	array_t *at = (array_t*)array_p;
	int retval = 0;

	pthread_mutex_lock(&at->mutex);
	if (index >= at->length) {
		pthread_mutex_unlock(&at->mutex);
		retval = -1;
		errno = EINVAL;
	}
	else {
		at->array[index] = new_value;
		pthread_mutex_unlock(&at->mutex);
	}
	return (retval);
}

//修改数组中的多个值
static inline int set_elements(const void *array_p, void *(*oper_elements)(void *), void *argv) {
	array_t *at = (array_t*)array_p;
	int *ret = NULL, retval = 0;

	pthread_mutex_lock(&at->mutex);
	ret = oper_elements(argv);
	if (*ret == -1) {
		if (errno != 0) {
			perror("set_elements");
			retval = -1;
		}
	}
	pthread_mutex_unlock(&at->mutex);

	return (retval);
}


