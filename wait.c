
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
int main()
{
	pid_t ret = fork();
	if(ret == 0)
	{
		printf("this is child process, pid : %d and parent pid: %d\n", getpid(), getppid());
		sleep(15);
		printf("Child terminated\n");
	}
	else if(ret > 0)
	{
		 printf("this is parent process, pid : %d and parent pid: %d\n", getpid(), getppid());
                int status;
		pid_t wait_ret = wait(&status);
		printf("Child %d terminated with exit code %d\n", wait_ret, status);
                printf("Parent terminated\n");
	}

	else
	{
		perror("fork");
		return -1;
	}
}
