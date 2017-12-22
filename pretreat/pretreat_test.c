#include"pretreat.h"

#define MAX 50
#define ADD(a,b) (a+b)
void main (void)
{
	int a=MAX;
	int b=MAX+1;
	printf("\033[40;32ma+b=%d\n\033[0m",a+b);
	printf("\033[41;30ma+b=%d\n\033[0m",ADD(a,b));
}

