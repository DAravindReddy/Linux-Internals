
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	pid_t ret1 = fork();
	if(ret1 > 0)
	{
		pid_t ret2 = fork();
		if(ret2 > 0)
		{
			printf("This is parent process, pid : %d and parent pid : %d\n", getpid(), getppid());
		}
		else if(ret2 == 0)
		{
			printf("This is child2 process, pid : %d and parent pid : %d\n", getpid(), getppid());
		}
		else
		{
			perror("fork");
			return -1;
		}
	}
	else if(ret1 == 0)
	{
		printf("This is child1 process, pid : %d and parent pid : %d\n", getpid(), getppid());
	}
	else
	{
		perror("fork");
		return -1;
	}

}
