//read.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
	int i,shmid;
	void *sharedMemory;
	char buff[50];
	key_t key=32270;
	printf("Key of shared memory:%d\n",key);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	sharedMemory=shmat(shmid,NULL,0);
	printf("Process attached at %p\n",sharedMemory);
	printf("Data read from the shared memory is %s\n",(char*)sharedMemory);
}

--------------------------------
  //write.c
  #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
	int i,shmid;
	void *sharedMemory;
	char buff[50];
	key_t key=32270;
	printf("Key of shared memory:%d\n",key);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	sharedMemory=shmat(shmid,NULL,0);
	printf("Process attached at %p\n",sharedMemory);
	printf("Enter data that is to be written:");
	scanf("%s",buff);
	strcpy(sharedMemory,buff);
	printf("Data is written!\n");
}
