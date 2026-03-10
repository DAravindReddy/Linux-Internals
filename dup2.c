#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd = open("dup2.txt", O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}

	//dup2 = dup + close

	int backup = dup2(1, 4);

	dup2(fd, 1);
	printf("Print this message in file\n");
	fflush(stdout);

	//close(1);

	dup2(backup, 1);
	
	printf("Print this message in stdout\n");
	return 0;
}
