#include "zhou_chat_cli.h"

int zhou_chat_cli(FILE *fp, const int connfd)
{
	int    maxfdp1, ret, inputfd = fileno(fp);
	fd_set rset, wset;
	char   rbuf[MAXSIZE], wbuf[MAXSIZE];

	FD_ZERO(&rset);
	FD_ZERO(&wset);
	maxfdp1 = max(connfd, inputfd)+1;

	select(maxfdp1, &rset, &wset, NULL, NULL);
	for ( ; ; ) {
		FD_SET(connfd, &rset);
		FD_SET(inputfd, &rset);
		FD_SET(connfd, &wset);

		if (FD_ISSET(connfd, &rset)) {
			if (ret = read(connfd, rbuf, MAXSIZE) == 0) {
			  	if (errno == EINTR)
					continue;
			}
			else if (ret < 0)
				return -1;
			write(stdout, rbuf, MAXSIZE);
		}

		if (FD_ISSET(inputfd, &rset)) {
			if (read(inputfd, wbuf, MAXSIZE) == 0) {
					shutdown(connfd, SHUT_WD);
					FD_CLR(inputfd, &rset);
					continue;
		

			if (read(stdin, rbuf, MAXSIZE) < 0)
				continue;
	}
	return 0;
}
	
