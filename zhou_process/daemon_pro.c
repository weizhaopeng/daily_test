#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int ret = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid > 0)
		exit(0);
	if (child_pid == 0) {
		for(int i = 0; i < 5; i++) {
			printf("你好，杨晓涵YANGXIAOHAN\n");
			sleep(1);
		}
	}
	child_pid = daemon(0, 0);
	return 0;
}
