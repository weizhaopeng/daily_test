#include "zhou_time.h"

int main(int argc, char **argv)
{
	int    listenfd, connectfd, ret;
	struct sockaddr_in server_sa;
	char   time_buf[MAXSIZE+1];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0 )
		return 0;
	
	bzero(&server_sa, sizeof(struct sockaddr_in));
	server_sa.sin_family = AF_INET;
	server_sa.sin_addr.s_addr = htonl(INADDR_ANY);
	server_sa.sin_port   = htons(13);

	ret = bind(listenfd, (struct sockaddr *)&server_sa, sizeof(struct sockaddr_in));
	if (ret = -1)
		exit(-1);

	ret = listen(listenfd, LISTEN_NUM);
	if (ret = -1)
		exit(-1);

	while (1) {
		connectfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
		if (connectfd < 0)
			exit(-1);
		ticks = time(NULL);
		snprintf(time_buf, MAXSIZE+1, "%.24s\r\n", ctime(&ticks));
		ret  = write(connectfd, time_buf, MAXSIZE+1);
		if (ret < 0)
			exit(-1);

		close(connectfd);
	}
}

