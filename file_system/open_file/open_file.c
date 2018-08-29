#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int fd;

	fd = open("/root/", O_RDONLY | O_DIRECTORY | O_CREAT);
	printf("%d\n", fd);

	write(fd, "nihao", 6);
	close(fd);
	return 0;
}
