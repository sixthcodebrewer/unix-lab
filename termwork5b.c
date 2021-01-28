#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int ch;
	if(argc!=3)
	printf("usage %s <source file><destination file>",argv[0]);
	printf("\n 1.hard link	2.soft link\n");
	scanf("%d",&ch);
		if(ch==1)
		{
			if(link(argv[1],argv[2])==-1)
			{
			perror("link");
			return 1;
			}
		else
		printf("hard link created succesfully");
		}
	else
	{
		if(symlink(argv[1],argv[2])==-1)
		{
		perror("link");
		return 1;
		}
		else
		printf("soft link created succesfully");	
	}
}
