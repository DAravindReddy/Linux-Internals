
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>


void *thread_function(void *arg)
{
        int num = 5;
	while(num--)
	{
		printf("Thread is executing\n");
		sleep(1);
	}
        pthread_exit(NULL);
}
int main()
{
        pthread_t tid;
        pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_create(&tid, &attr, thread_function, NULL);


	//pthread_join(tid, NULL);
	sleep(6);



        printf("Back to the main thread\n");

        pthread_attr_destroy(&attr);
	return 0;
}
