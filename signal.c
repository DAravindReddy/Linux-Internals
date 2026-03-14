
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig_handler(int signum)
{
	printf("SIGINT Arrived\n");
}

int main()
{
	signal(SIGINT, sig_handler);
	while(1)
	{
		printf("Inside main\n");
		sleep(1);
	}
}
