#include <stdio.h>

#include <unistd.h>

#include <sys/wait.h>

int main() {
  int pid = fork();
  if (pid == 0) {
    printf("child pid = %d\n", getpid());
    printf("my parent's pid =%d\n", getppid());
  } else if (pid > 0) {
    printf("parent PID = %d \n", getpid());
    printf("my child PID = %d \n", pid);
    int staus;
    wait( & staus);

    printf("child is terminated with status %d \n", staus);

  } else {
    printf("fork failed \n");
    return -1;

  }
  return 0;

}
