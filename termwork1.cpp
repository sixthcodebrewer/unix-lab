#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<limits.h>
#include<iostream>

using namespace std;

int main()
{
 int res;
 
 cout << "--COMPILE TIME--"<<endl;
 
 #ifdef _POSIX_CLK_TCK
  cout<<"No of clock ticks is "<< _POSIX_CLK_TCK<<endl;
 #else
  cout<<"Clock ticks not supported"<<endl;
 #endif
 
 #ifdef _POSIX_CHILD_MAX
  cout<<"No of max child processes that can be created simultaneously is "<< _POSIX_CHILD_MAX<<endl;
 #else
  cout<<"Child max not supported"<<endl;
 #endif
 
 #ifdef _POSIX_PATH_MAX
  cout<<"No of max child processes that can be created simultaneously is "<< _POSIX_PATH_MAX<<endl;
 #else
  cout<<"Child max not supported"<<endl;
 #endif
 
 #ifdef _POSIX_NAME_MAX
  cout<<"Max number of characters in file name "<< _POSIX_NAME_MAX<<endl;
 #else
  cout<<"Name max not supported"<<endl;
 #endif
 
 #ifdef _POSIX_OPEN_MAX
  cout<<"No of files/processes that can be opened simultaneously is "<< _POSIX_OPEN_MAX<<endl;
 #else
  cout<<"Open max not supported"<<endl;
 #endif
 
 cout << "\n--RUN TIME--" <<endl;
 
 if((res=sysconf(_SC_CLK_TCK))==-1)
  cout << "Clock ticks not supported" << endl;
 else
  cout << "No of clock ticks is " <<res <<endl;
 
 if((res=sysconf(_SC_CHILD_MAX))==-1)
  cout << "Child max not supported" << endl;
 else
  cout << "No of max child processes that can be created simultaneously is " <<res <<" min value is " << _SC_CHILD_MAX<<endl;
 
 if((res=pathconf("/",_PC_PATH_MAX))==-1)
  cout << "Path max not supported" <<endl;
 else
  cout << "Max path length is " <<res <<endl;
 
 if((res=pathconf("/",_PC_NAME_MAX))==-1)
  cout << "Name max not supported" <<endl;
 else
  cout << "Max number of characters in file name " <<res <<endl;
 
 if((res=sysconf(_SC_OPEN_MAX))==-1)
  cout << "Open max not supported" <<endl;
 else
  cout << "No of files/processes that can be opened simultaneously is " <<res <<endl;
}
