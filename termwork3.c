 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
 int main(int argc,char *argv[])
 {
        int fd;
        char buffer[255];
        struct flock fvar;
        if(argc==1)
        {
                printf("usage: %s filename\n",argv[0]);
                return -1;
        }
        
        // open the file that is passed as the command line argument to the program in read and write mode
        if((fd=open(argv[1],O_RDWR))==-1) // if open is not successful exit from the program
        {
                perror("open");
                exit(1);
        }
        fvar.l_type=F_WRLCK; // ltype
        fvar.l_whence=SEEK_END; //lwhence
        fvar.l_start=SEEK_END-100;// lstart
        fvar.l_len=100; //llen
        printf("press enter to set lock\n");
        getchar(); //any key stroke ,even enter is accepted
        printf("trying to get lock..\n");
        //IF the file is already locked print 
        if((fcntl(fd,F_SETLK,&fvar))==-1)
        {     fcntl(fd,F_GETLK,&fvar);
              printf("\nFile already locked by process (pid):\t %d \n",fvar.l_pid);        
              return -1;        
        }
        printf("locked\n");
        //finding the offset value of the last 50 bytes
        if((lseek(fd,SEEK_END-50,SEEK_END))==-1)
        {
                perror("lseek");
                exit(1);
        }
        // reading the last 50 bytes
        if((read(fd,buffer,100))==-1)
        {
                perror("read");
                exit(1);
        }
        printf("data read from file..\n");
        // printing 50 bytes of the buffer
        puts(buffer);
        printf("press enter to release lock\n");
        getchar();
        fvar.l_type = F_UNLCK; // REPLACING f_WRLCK TO F_UNLCK FOR VARIALE FVAR to unlock the file
        fvar.l_whence = SEEK_SET; //REPLACING PROCESS ID FROM O TO CURRENT PROCESS ID FOR THE VARIABLE FL
        fvar.l_start = 0;
        fvar.l_len = 0;
        if((fcntl(fd,F_UNLCK,&fvar))==-1)
        {
                perror("fcntl");
                exit(0);
        }
        printf("Unlocked\n");
        close(fd);
        return 0;
 }
