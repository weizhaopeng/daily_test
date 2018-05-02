#include "zhou_socket_cli.h"
#include "zhou_chat_cli.h"

int main(int argc, char *argv[]) 
{
	//init the variate
	struct sockaddr_in seraddr, cliaddr;
	socklen_t 		   seraddr_len, cliaddr_len;

	seraddr.sin_family 		= AF_INET;
	seraddr.sin_addr,s_addr = htonl(INADDR_ANY);
	seraddr.sin_port	    = htons(0);
	seraddr_len 			= sizeof(seraddr); 

	addrpair *ap = malloc(sizeof(addrpair));
	if (ap == NULL)
		return -1;
	ap->seraddr 	= &seraddr;
	ap->seraddr_len = &seraddr_len;
	ap->cliaddr 	= &cliaddr;
	ap->cliaddr_len = cliaddr_len;

	//tcp connect 
	int connfd1, connfd2;
	connfd1 = zhou_socket_ser(ap);
	if (connfd1 = -1)
		return -1;

	//new a process
	pid_t pid;
	pid = fork();

	//chat function 
	if (pid == 0) {
		int ret;
		ret = zhou_chat_ser(connfd1)
		if (ret == -1)
			exit(-1);
	}
	return 0;
}
