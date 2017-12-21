#include"pretreat.h"

#define MAX 50
void main (void)
{
	int a=MAX;
	int b=MAX+1;
	//printf("\033[47;36ma+b=%d\n\033[8m",a+b);
	printf("\033[32m我叫魏\033[7m朝鹏\033[2J之后呢");
	printf("\033[3;4H我叫杨晓涵\n");
	printf("\033[40;32ma+b=%d\n\033[0m",a+b);
	printf("\033[1A123\n\033[3B456\033[0m");
	return ;
	
}

