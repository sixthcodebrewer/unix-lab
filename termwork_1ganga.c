#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<stdio.h>
#include<limits.h>
int main()
{
    printf("==================================\n");
    printf("compile time limits\n");
    printf("==================================\n");
    #ifdef _POSIX_CHILD_MAX
        printf("Maximum number of child process: %d\n", _POSIX_CHILD_MAX);
    #else
        printf("Not defined\n");
    #endif

    #ifdef _POSIX_OPEN_MAX
        printf("Maximum number of files opened simultaneosly: %d\n", _POSIX_OPEN_MAX);
    #else
        printf("Not defined\n");
    #endif

    #ifdef _POSIX_NAME_MAX
        printf("Maximun number of characters in file name: %d\n", _POSIX_NAME_MAX);
    #else
        printf("Not defined\n");
    #endif

    #ifdef _POSIX_PATH_MAX
        printf("Maximun number of characters in path name: %d\n", _POSIX_PATH_MAX);
    #else
        printf("Not defined\n");
    #endif

    printf("==================================\n");
    printf("run time limits\n");
    printf("==================================\n");
    int res;
    if((res = sysconf(_SC_OPEN_MAX)) == -1)
        perror("sysconf");
    else
        printf("Maximum no of open files: %ld\n", sysconf(_SC_OPEN_MAX));

    if((res = sysconf(_SC_CLK_TCK)) == -1)
        perror("sysconf");
    else
        printf("No of clock ticks: %ld\n", sysconf(_SC_CLK_TCK));

    if((res = pathconf("/",_PC_PATH_MAX)) == -1)
        perror("sysconf");
    else
        printf("Maximum path length: %ld\n", pathconf("/", _PC_PATH_MAX));


    if((res = pathconf("/",_PC_NAME_MAX)) == -1)
        perror("sysconf");
    else
        printf("Maximun characters in a file name: %ld\n", pathconf("/", _PC_NAME_MAX));
    return 0;
}
