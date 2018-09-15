#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/fs.h>
#include <sys/stat.h>
#include <linux/fs.h>

int main(int argc, char **argv) {
	pid_t child_pid;

	child_pid = fork();
	if (child_pid > 0)
		exit(0);
	else if (child_pid == 0) {
		for (int i = 0; i < 5; i++) {
			printf("你好，魏朝鹏\n");
			sleep(1);
		}
		exit(0);
	}

	child_pid = setsid();

	chdir("/root");

	for(int i = 0; i < 40; i++)
		close(i);
	
	open("/dev/null", O_RDWR);
	dup(0);
	dup(0);
	return 0;
}









