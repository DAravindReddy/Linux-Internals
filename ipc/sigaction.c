
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signum)
{
	printf("SIGINT Arrived\n");
}

int main()
{
	struct sigaction act, oldact;
	act.sa_handler = sig_handler;
	sigaction(SIGINT, &act, &oldact);
	while(1)
	{
		printf("INSIDE MAIN\n");
		sleep(1);
	}
}
