
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	printf("pid -> %d\nppid -> %d\n", getpid(), getppid());
	while(1);
	return 0;

}

