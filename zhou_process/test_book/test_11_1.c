#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
	int a, b, c, d;
} foo;

static inline void printfoo(const foo* f);
static inline void *fun1(void *argv);
static inline void *fun2(void *argv);

int main(void) {
	pthread_t th1, th2;
	foo 	 *ret_foo = NULL;
	int		  ret = 0;

	ret = pthread_create(&th1, NULL, fun1, NULL);
	if (ret != 0) {
		strerror(ret);
		return(-1);
	}
	ret = pthread_join(th1, (void*)&ret_foo);
	if (ret != 0) {
		strerror(ret);
		return(-1);
	}

	ret = pthread_create(&th2, NULL, fun2, NULL);
	if (ret != 0) {
		strerror(ret);
		return(-1);
	}
	
	ret = pthread_join(th2, NULL);
	if (ret != 0) {
		strerror(ret);
		return(-1);
	}

	printf("main thrad:\n\t");
	printfoo(ret_foo);

	free(ret_foo);
	return(0);
}

static inline void printfoo(const foo* f) {
	printf("the content is: %d %d %d %d\n", f->a,
		f->b, f->c, f->d);
	return;
}

static inline void *fun1(void *argv) {
	foo *foo1 = calloc(1, sizeof(foo));
	
	foo1->a = 1;
	foo1->b = 2;
	foo1->c = 3;
	foo1->d = 4;

	printf("thread1:\n\t");
	printfoo(foo1);
	pthread_exit((void*)foo1);
}

static inline void *fun2(void *argv) {
	printf("thread2:\n\t");
	printf("the thread2 id = %lu\n", (unsigned long)pthread_self());
	
	pthread_exit((void*)0);
}

