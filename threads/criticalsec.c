
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int count;
pthread_mutex_t lock;
void *thread_function(void * arg)
{
	while(count < 20)
	{

		pthread_mutex_lock(&lock);
		count++;
		printf("count = %d\n", count);
		sleep(1);
		pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, thread_function, NULL);
	pthread_create(&tid2, NULL, thread_function, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("Back to main\n");
	return 0;
}
