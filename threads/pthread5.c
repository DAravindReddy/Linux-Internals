
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>



void *thread_function(void *arg)
{
 	int a = 10, b = 20;
   	int *ptr = malloc(sizeof(int));
	*ptr = a+b;
	return (void *)ptr;
}


int main()
{
	pthread_t tid;
	int data = 10;

	int *result;
        if(pthread_create(&tid, NULL, thread_function, NULL) != 0)
        {
                printf("Thread is not created\n");
                return -1;
        }
        

        pthread_join(tid,(void **)&result);
        printf("Back to main thread and result : %d\n", *result);
	return 0;


}

