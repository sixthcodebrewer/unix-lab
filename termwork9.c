#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h>
void mySystem(const char *command) {
    pid_t pid;
    if((pid = fork()) == 0)
        execl("/bin/bash", "bash", "-c", command, NULL);
        
    else
        waitpid(pid, NULL, 0);    
}
int main(int argc, char *argv[]) {
    for(int i; i<argc; ++i){
        mySystem(argv[i]);
        printf("\n");
    }
    mySystem("ps -o pid, ppid, stat, tty, command");
    exit(0);

}