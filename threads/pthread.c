
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread_function(void *arg)
{
	int i = 5;
	while(i--)
	{
		printf("Thread is executiong and tid: %ld\n", pthread_self());
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	if(pthread_create(&tid, NULL, thread_function, NULL) != 0)
	{
		printf("Thread is not created\n");
		return -1;
	}
	//sleep(5);
	pthread_join(tid, NULL);
	printf("Back in main thread\n");

}
