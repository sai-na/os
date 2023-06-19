#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/shm.h> 
#include<string.h> 
#include<sys/ipc.h> 
int main() { 
void *shared_memory; 
char buffer[25]; 
int shmid; 
shmid = shmget((key_t)1122,1024,0666); 
printf("The key of the shared memory is %d",shmid); 
shared_memory = shmat(shmid,NULL,0); 
printf("Process attatched the shared segment at %p\n",shared_memory); 
printf("Data from the memory is\n%s\n",(char *)shared_memory); 
return 0; 
} 
