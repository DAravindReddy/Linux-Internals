#include<errno.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	
	pid_t ret_pid = fork();
	if(ret_pid == 0)
	{
		//child process
		printf("This child process pid: %d and parent pid: %d\n", getpid(), getppid());
		sleep(5);
		printf("child process terminated\n");
	}
	else if(ret_pid > 0)
	{
		//parent process
		printf("This is parent process pid: %d and parent pid: %d\n", getpid(), getppid());
		sleep(20);
		printf("parent process terminated\n");
	}
	
	else
	{
		perror("fork");
		return -1;
	}
	return 0;
}
