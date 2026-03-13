
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#define KEY 0xA

int main()
{
	//Create shmid

	int shmid = shmget(KEY, 100, IPC_CREAT | 0666 );	//int shmget(int key, sszie_t size, int shmflg);
	if(shmid == -1)
	{
		perror("shmget");
		return -1;
	}

	//Attach shm
	void *ptr = shmat(shmid, NULL, 0);	//void *shmat(int shmid, const void *shmaddr, int shmflg);
	if(ptr == (char *)-1)
	{
		perror("shmat");
		return -1;
	}

	//read and write using pointer
	char str[100];
	printf("Enter your string: ");
	scanf("%[^\n]", str);

	strcpy((char *)ptr, str);

	printf("writting successfuly\n");



	//Detach shm
	//
	shmdt(ptr);       //	int shmdt(const void *shmaddr);
	



	//delete shm	//	int shmctl(int shmid, int cmd, struct shmid_ds *buf);
	shmctl(shmid, IPC_STAT, NULL);

	return 0;
}
       	
