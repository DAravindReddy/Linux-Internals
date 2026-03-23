#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
	int fd = open("dup.txt", O_WRONLY);
	

	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	int backup = dup(1);
	close(1);
	dup(fd);
	printf("Print this msg into file\n");
	fflush(stdout);
	
	close(1);
	dup(backup);
	printf("Print this msg in to stdout\n");

	return 0;
}
