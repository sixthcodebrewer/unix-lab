#include <stdio.h>
#include <limits.h>
#include <unistd.h>
// #include <iostream.h>
// #define _POSIX_SOURCE
// #define _POSIX_C_SOURCE 199309L
int main()
{
	printf("compile time values \n");
//	printf("No of clock ticks is: %d \n",_POSIX_CLK_TCK);
	printf("No of max child processes that can be created simultaneously is: %d \n", _POSIX_PATH_MAX);
	printf("No of max child processes that can be created simultaneously is: %d	\n",_POSIX_CHILD_MAX);
	printf("No of files/processes that can be opened simultaneously is : %d	\n",_POSIX_OPEN_MAX);
	printf("No of max characters in a file: %d	\n",_POSIX_NAME_MAX);
//	printf("The max runitme path length : %ld \n",pathconf("termwork_1.c",_PC_PATH_MAX));
//printf("The max characters in a file name : %ld \n",pathconf("termwork_1.c",_PC_NAME_MAX));

	printf("Runtime values \n");
	printf("The max number of clock ticks : %ld \n",sysconf(_SC_CLK_TCK));
	printf("The max runtime child processes : %ld \n",sysconf(_SC_CHILD_MAX));
	printf("The max number of opened files : %ld \n",sysconf(_SC_OPEN_MAX));
	return 0;

}
