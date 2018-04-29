#include "zhou_chat_cli.h"

int zhou_chat_cli(FILE *fp, const int connfd)
{
	int    maxfdp1, ret; 
	int	   inputfd  = fileno(fp);
	int	   stdineof = 1;
	char   rbuf[MAXSIZE], wbuf[MAXSIZE];
	fd_set rset, wset;

	FD_ZERO(&rset);
	FD_ZERO(&wset);
	maxfdp1 = max(connfd, inputfd)+1;

	select(maxfdp1, &rset, &wset, NULL, NULL);
	for ( ; ; ) {
		FD_SET(connfd,  &rset);
		FD_SET(inputfd, &rset);
		FD_SET(connfd,  &wset);

		if (FD_ISSET(connfd, &rset)) {
			if (ret = read(connfd, rbuf, MAXSIZE) == 0) {
			  	if (errno == EINTR)
					continue;
			}
			else 
				if (ret < 0)
					return -1;
			write(stdout, rbuf, MAXSIZE);
		}

		if (FD_ISSET(inputfd, &rset)) {
			if (ret = read(inputfd, wbuf, MAXSIZE) == 0) {
					shutdown(connfd, SHUT_WD);
					FD_CLR(inputfd, &rset);
					break;
			}
			else {
				if (ret < 0) 
					return -1;
				else if (FD_ISSET(connfd, &wset))
					write(connfd, wbuf, MAXSIZE);
			}
		}
	}
	return 0;
}
	
