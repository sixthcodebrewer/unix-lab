#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
 cout<< "\n------\n"<<endl;
 cout<< "Using environment variables passed to program as command line arguments into environment variables = Value format\n\n"<<endl;
 
 for(int i=0;envp[i]!=(char *)0;i++)
 {
  cout<<envp[i]<<"\n";
 }
 
 cout<<"Using external variable environ\n"<<endl;
 
 extern char **environ;
 
 for(int i=0;environ[i]!=(char *)0;i++)
 {
  cout<<environ[i]<<"\n";
 }
 
 cout<<"\n----------\n";
 
 cout<<"Using getenv, stdlib.h\n"<<endl;
 
 char *env = getenv("HOME");
 cout<<"PATH = "<<env<<"\n";
 
 char envVar[10][10] = {"SHELL", "TERM", "USER", "PATH"};
 
 for(int i=0;i<4;i++)
 {
  cout<<envVar[i]<<" = "<<getenv(envVar[i])<<"\n";
 }
 
 cout<<"\n----------\n";
 return 0;
 }
