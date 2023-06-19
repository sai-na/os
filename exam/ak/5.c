#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
	printf("Process ID=%d\n", getpid());
	printf("Parent Process ID=%d\n", getppid());
}
