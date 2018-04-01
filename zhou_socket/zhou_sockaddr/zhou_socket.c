#include "zhou_socket.h"

int main(int argc, char **argv)
{
	struct sockaddr    sa;
	struct sockaddr_in sa_in;

	printf("sockaddr is :%ld bits\n", 	 sizeof(struct sockaddr));
	printf("sockaddr_t is : %ld bits\n", sizeof(struct sockaddr_in));
	
	return 0;
}

