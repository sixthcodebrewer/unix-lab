#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>


void wakeup ()
{


printf("Hello \n");
printf("---------------------\n");

}

int main()
{
signal(SIGALRM,&wakeup); 
while(1)
	{
	alarm(5);
	pause();
	printf("waiting for alarm\n");
	}
	return 0;


}
