
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{

	int fd = open("f2.txt", O_CREAT | O_WRONLY);
	char buf[100] = "Hello world";
	ssize_t ret = write(fd, buf, 500);
	printf("ret -> %ld\n", ret);

	return 0;
}
