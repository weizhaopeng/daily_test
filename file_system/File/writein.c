#include"test.h"
int main (void)
{
	FILE *fp;
	int a[3]={1,2,3},b[3];
	fp=fopen("file","a");
	printf("%d\n",fseek(fp,10L,0));

	for(int i=0;i<3;i++)
	{
		fputc(41,fp);
	}
	
	
	fclose(fp);
	return 0;
}



