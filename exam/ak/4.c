#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(){
	pid_t created_process = fork();
	
	if(created_process < 0){
		printf("Fork failed\n");
	}
	else if(created_process == 0){
		printf("Child process created\n");
	}
	else{
		printf("Parent process created\n");
	}

	printf("process ID: %d\n", created_process);
}

