#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<stdio.h>
int main()
{
#ifdef _POSIX_JOB_CONTOL
	printf("system supports job control\n");
#else 
	printf("system doesnt supports job control\n");
#endif

#ifdef _POSIX_SAVED_IDS
	printf("system supports saved set-uid and set-gid \n");
#else 
	printf("system doesnt supports saved set-uid and set-gid\n");
#endif

#ifdef _POSIX_CHOWN_RESTRICTED
	printf("chown_restricted option is :%d\n",_POSIX_CHOWN_RESTRICTED);
#else 
	printf("system doesnt supports chown restricted option\n");
#endif

#ifdef _POSIX_NO_TRUNC
	printf("pathname trunc option is:%d\n",_POSIX_NO_TRUNC);
#else 
	printf("system doesnt supports SYSTEM WIDE PATHNAME:%d\n",_POSIX_NO_TRUNC);
#endif

#ifdef _POSIX_VDISABLE
	printf("disable characted for terminal files is:%d\n",_POSIX_VDISABLE);
#else 
	printf("system doesnt supports chown restricted option\n";
#endif

}


