#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int arg,char *argv[],char *env[])
{
	printf("\n\n**BY COMMAND LINE ARGUMENT env***\n\n");
	int i;
	for(i=0;env[i]!=NULL;i++)
		printf("\n %s",env[i]);

printf("\n\n**BY COMMAND LINE ARGUMENT environ***\n\n");
	extern char **environ;
	for(i=0;environ[i]!=NULL;i++)
		printf("\n %s",environ[i]);

// printf("\n\n**BY COMMAND LINE ARGUMENT getenv***\n\n");
// char en[]="PATH";
// printf("%s=%s\n",en,getenv(en));
// char envA[10][10]={"HOME","USER","SHELL","LOGNAME"};
// for(i=0;i<4;i++)
// printf("%s=%s\n",envA[i],getenv(envA[i]));


return 0;

	
}
