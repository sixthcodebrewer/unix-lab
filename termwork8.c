#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	int pid;
	pid = fork();
	if(pid<0)
	{
	printf("fork error");
	exit(0);
	}
	
	if(pid==0) {
	//first child 
	pid = fork();
		if(pid<0)
		{	
			printf("fork error");
			exit(0);
		}
		if (pid == 0) 
		{
		//second child
		sleep(1);
		printf("second Child: My parent PID is %d \n", getppid());
		}
	}
	else
	{
	//parent process 
	wait(NULL);
	sleep(2);
	system("ps -0 pid,ppid,state,tty,command");
	}
	return 0;
	 
}
