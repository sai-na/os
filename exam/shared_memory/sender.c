#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/shm.h> 
#include<string.h> 
int main() { 
int i,shmid; 
void *shared_memory; 
char buffer[25]; 
shmid = shmget((key_t)1122,1024,0666|IPC_CREAT); 
printf("Shared memory id is %d\n",shmid); 
shared_memory = shmat(shmid,NULL,0); 
printf("Process attatched the shared segment at %p\n",shared_memory); 
printf("Enter some data\n"); 
read(0,buffer,25); 
strcpy(shared_memory,buffer); 
printf("Written : %s\n",(char *)shared_memory); 
return 0; 
}