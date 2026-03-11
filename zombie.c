
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	pid_t ret = fork();
	if(ret == 0)
	{
		printf("this is child process, pid : %d and parent pid: %d\n", getpid(), getppid());
		sleep(5);
		printf("Child terminated\n");
	}
	else if(ret > 0)
	{
		 printf("this is parent process, pid : %d and parent pid: %d\n", getpid(), getppid());
                sleep(20);
                printf("Parent terminated\n");
	}

	else
	{
		perror("fork");
		return -1;
	}
}
