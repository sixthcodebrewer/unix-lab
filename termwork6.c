#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void charatatatime(char *);

int main()
{
	int pid;
	pid = fork();
/*	if(pid<0)
	printf("\n nfork error");
	else if(pid==0)
		charatatatime("Output from child \n");
	else
		charatatatime("Output from Parent \n");
	exit(0);r
	*/
	
	if(pid==0)
	{
	charatatatime("Output from child \n");
	}
	else
	{
	charatatatime("Output from parent \n");
	}
	
}

static void charatatatime(char * str)
{
char *ptr;
int c;
setbuf(stdout,NULL);
for(ptr = str ;(c =*ptr++)!=0;)
	putc(c,stdout);

}
