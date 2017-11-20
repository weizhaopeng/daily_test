#include"stdio.h"
struct stu
{
	int num;
	char name[20];
	char sex;
};
typedef struct stu STU;
int main (void)
{
	STU wzp={15011630,"weizhaopeng",'f'};
	printf("%s",wzp.name);
	return 0;
}

