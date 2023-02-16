#include<stdio.h>

#include<unistd.h>

#include<sys/types.h>

pid_t created_process;
int main()

{

  created_process = fork();
  if (created_process < 0) {
    printf("fork failed \n");
  } else if (created_process == 0) {
    printf("child process created \n");
  } else {
    printf("parent process created \n");
  }
}
