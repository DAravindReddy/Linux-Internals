
#include<stdio.h>
#include<sys/time.h>

int main()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);//system call
	
	//display time'
	printf("%lu\n", tv.tv_sec);
	printf("%lu\n", tv.tv_usec);
	return 0;
}
