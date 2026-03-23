
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{
	struct stat my_stat;
	int fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	if(fstat(fd, &my_stat) == -1)
	{
		perror("fstat");
		return -1;
	}
	printf("File %s size -> %lu\n", argv[1], my_stat.st_size);
	return 0;
}
