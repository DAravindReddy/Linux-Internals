
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>


int main()
{
	char buf[100];
	int fd = open("myfifo", O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	int ret = read(fd, buf, sizeof(buf) + 1);
	printf("%s\n", buf);

	close(fd);
	return 0;
}
