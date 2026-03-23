

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#include<errno.h>	

void *thread_function1(void *arg)
{
       while(1){
	       printf("X\n");
       }
       return NULL;
}

void *thread_function2(void *arg)
{
	while(1)
	{
		printf("0\n");
		exit(0);
	}
	return NULL;
}

int main()
{
        pthread_t tid1, tid2;
        pthread_create(&tid1, NULL, thread_function1, NULL);
	pthread_create(&tid2, NULL, thread_function2, NULL);
        
	pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        printf("Back in main thread\n");

}

