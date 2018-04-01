#include "zhou_time.h"

int main(int argc, char **argv)
{
	int    sockfd, ret;
	char   time_buf[MAXSIZE+1];
	struct sockaddr_in server_sa;

	if (argc != 2)
		return 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		exit(-1);

	bzero(&server_sa, sizeof(struct sockaddr_in));
	server_sa.sin_family = AF_INET;
	server_sa.sin_port	 = 13;
	ret = inet_pton(AF_INET, argv[1], &server_sa.sin_addr);
	if (ret < 0)
		exit(-1);

	ret = connect(sockfd, (struct sockaddr *)&server_sa, sizeof(struct sockaddr));
	if (ret < 0)
		exit(-1);

	while ((ret = read(sockfd, time_buf, MAXSIZE)) >0) {	//read return the number of byte read
		time_buf[ret] = '\0';
		if (fputs(time_buf, stdout) == EOF)
			return 0;
	}

	if (ret < 0 )
		exit(-1);
	
	exit(0);
}

