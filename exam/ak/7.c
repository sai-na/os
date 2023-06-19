#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	if(fork() == 0){
		printf("Child: Hello from Child!\n");
	}
	else{
		printf("Parent: Hello from Parent!\n");
		wait(NULL);
		printf("Child: Child has terminated!\n");
	}

	printf("Bye!\n");
}
