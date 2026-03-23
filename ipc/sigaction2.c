
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
	

void sigaction_handler(int signum, siginfo_t *info, void *dummy)
{
	printf("SIGINT arrived and sender PID %d\n", info->si_pid);
	exit(0);
}	
int main()
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigaction_handler;
	sigaction(SIGINT, &act, NULL);
	while(1)
	{
		printf("Inside main\n");
		sleep(1);
	}
}
