#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
	int ret;
	ret = fork();
	
	if(ret == 0){
		printf("The Underlying process is Child process\n");
		printf("Process ID: %d\n", getpid());
		printf("Parent ID: %d\n", getppid());
	}
	else{
		printf("The Underlying process is the Parent process\n");
		printf("Process ID: %d\n", getpid());
		printf("Parent ID: %d\n", getppid());
	}
}
