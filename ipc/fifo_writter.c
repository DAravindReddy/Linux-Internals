
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>


int main()
{
	int fd = open("myfifo", O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	write(fd, "Hello\0", 6);
	printf("Write successfull\n");
	close(fd);
}
