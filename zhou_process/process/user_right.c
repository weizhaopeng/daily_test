#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	int   ret = 0;

	/*
	printf("group = %d\n", getegid());
	ret = setegid(1000);
	if (ret == -1) {
		perror("setegid");
		return -1;
	}
	printf("group = %d\n", getegid());
	*/

	uid_t user  = geteuid();

	printf("user = %d\ngroup = %d\n", user, 0);
	printf("sizeof(uid_t) = %ld\nsizeof(gid_t) = %ld\n", sizeof(uid_t), sizeof(gid_t));
	ret = seteuid(1002);
	if (ret == -1) {
		perror("seteuid");
		return -1;
	}
	user  = geteuid();
	printf("user = %d\ngroup = %d\n", user, 0);

	return 0;
}

