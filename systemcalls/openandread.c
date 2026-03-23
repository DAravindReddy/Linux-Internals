#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
	int fd = open("f1.txt", O_RDONLY);
	char buf[100];
	ssize_t ret;
	do
	{
		ret = read(fd, buf, 20);
		printf("ret -> %ld\n", ret);

	}while(ret == 20);
	return 0;
}
