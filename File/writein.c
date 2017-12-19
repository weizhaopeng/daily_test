#include"test.h"
int main (void)
{
	FILE *fp;
	int a[3]={1,2,3},b[3];
	fp=fopen("file","w");

	for(int i=0;i<3;i++)
	{
		fprintf(fp,"%d",a[i]);
	}
	
	
	fclose(fp);
	return 0;
}



