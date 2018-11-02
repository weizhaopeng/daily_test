/*测试线程同步：互斥量的方法
 *创建两个线程，同时访问一个数据，并且访问数据的时候需要等待几秒才推出解锁
 *后面的线程进行等待，查看相应的数据的值
 */
#include "thread.h"
//测试结构体是否可以定义的时候初始化
typedef struct array_t {
	int array[100];
	int length;
	pthread_mutex_t mutex;
} array_t;

void *function(void *argv);

int main(void) {
	array_t at;
	int		ret = 0;
	//初始化数组
	puts("初始化数组内容:");
	for (int i = 0; i < LENGTH_ARRAY; i++) {
		at.array[i] = 1+(int)random()%100;
		printf("%d ", at.array[i]);
	}
	puts("");
	at.length = LENGTH_ARRAY;
	at.mutex = PTHREAD_MUTEX_INITIALIZER;
	//pthread_mutex_init(&at.mutex, NULL);
	
	//创建线程
	pthread_t th1, th2;
	ret = pthread_create(&th1, NULL, function, NULL);
	if (ret != 0){
		strerror(ret);
		return -1;
	}
	puts("线程1创建成功");

	ret = pthread_create(&th2, NULL, function, NULL);
	if (ret != 0){
		strerror(ret);
		return -1;
	}
	puts("线程2创建成功");
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	return 0;
}

void *function(void *argv) {
	array_t *at = (array_t*)argv;
	int		 ret = 0;

	ret = pthread_mutex_lock(&at->mutex);
	if (ret != 0) {
		printf("加锁出错");
		strerror(ret);
		return (void*)-1;
	}
	for (int i = 0; i <at->length; i++) {
		at->array[i]++;
		printf("%d ", at->array[i]);
	}
	printf("\n");
	sleep(5);

	ret = pthread_mutex_unlock(&at->mutex);
	if (ret != 0) {
		printf("解锁出错");
		strerror(ret);
		return (void*)-1;
	}
	return argv;
}


	


	
	

