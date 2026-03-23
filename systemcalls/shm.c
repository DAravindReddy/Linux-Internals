
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#define KEY 0xA


int main()
{

	//Create shmid
	int shmid = shmget(KEY, 100, 0);	//int shmget(int key, sszie_t size, int shmflg);
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
	
	
	printf("Data from shm: %s\n", (char *)ptr);

	//delete shm    //      int shmctl(int shmid, int cmd, struct shmid_ds *buf);
        shmctl(shmid, IPC_RMID, NULL);
	sleep(50);
	//Detach shm
	shmdt(ptr);       //	int shmdt(const void *shmaddr);

	return 0;
}
       	
