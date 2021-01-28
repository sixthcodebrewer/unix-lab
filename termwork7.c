#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_pid;
	// create a child process
	child_pid = fork();
	if (child_pid == 0)
	{
	exit(0);
	//child process 
	}
	else{
	sleep(3);
	system("ps -o stat,pid,ppid,tty,command ");
 	exit(0);
	}


}
