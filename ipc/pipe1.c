
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd[2];
	if(pipe(fd) == -1)
	{
		perror("pipe");
		return -1;
	}

	
	int ret = fork();
	if(ret == 0)
	{
		dup2(fd[1], 1);

		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls -l", NULL);
		
	}
	else if(ret > 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		execlp("wc", "wc", NULL);
	}
	else
	{
		perror("fork");
		return -1;
	}
}
