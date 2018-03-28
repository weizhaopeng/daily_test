#include "zhou_process.h"

int main(int argc, char **argv)
{
	pid_t pid, pid_ret;
	int   status;

	printf("创建子进程\n");

	pid = fork();
	if (pid < 0) {
		puts("创建子进程失败\n");
		exit(-1);
	}
	else {
		if (pid == 0) {
			puts("创建子进程成功\n");
			printf("当前进程的进程号是：%d\n", getpid());
			printf("当前进程的父进程号是：%d\n", getppid());
		}
		if (pid > 0) {
			pid_ret = waitpid(pid, &status, 0);
			if (pid_ret == -1) {
				perror("error!");
				exit(-1);
			}

			puts("当前进程是父进程\n");
			printf("当前进程的进程号是：%d\n", getpid());
			printf("当前进程的父进程号是：%d\n", getppid());
		}	
	}
	puts("程序总该是要执行结束的\n")
	return 0;
}
	
	
