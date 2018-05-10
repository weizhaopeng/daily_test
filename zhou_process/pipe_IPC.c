#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	pid_t cpid;
	char  buf[100];
	int   fd[2], ret;
	
	ret = pipe(fd);
	
	//子进程将从父进程接收到的数据写到屏幕上
	cpid = fork();
	if (cpid == 0) {
		char child[13] = "childprocess";
		int  num;
		close(fd[1]);
		while (num = read(fd[0], buf, 100) > 0) {
			write(STDOUT_FILENO, buf, 10);
			bzero(buf, sizeof(buf));
			printf("%s\n%ld\n", child, sizeof(child));
		}
		exit(0);
	}
	//父进程将键盘读入的数据传送给子进程
	if (cpid > 0) {
		int  num;
		close(fd[0]);
		while(num = read(STDIN_FILENO, buf, 100) > 0) {
			write(fd[1], buf, 100);
			bzero(buf, sizeof(buf));
		}
	}
	return 0;
}
