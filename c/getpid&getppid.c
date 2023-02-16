#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  int ret;
  ret=fork();
  if(ret==0)
  {
    printf("the underlying process is child process\nthe child id:%d\n",getpid());
    printf("parent id:%d\n",getppid());
    }
   else
   {
   
    printf("\nthe underlying process is the parent process\nprocess id:%d\n",getpid());
    printf("parent id:%d\n",getppid());
    }
  return 0;
 }
    
