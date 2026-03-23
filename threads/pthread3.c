
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread_function(void *arg)
{
        printf("Data from main is %d\n", *(int *)arg);
        return NULL;
}

int main()
{
        pthread_t tid;
	int data = 10;
        if(pthread_create(&tid, NULL, thread_function, (void *)&data) != 0)
        {
                printf("Thread is not created\n");
                return -1;
        }
        //sleep(5);
        pthread_join(tid, NULL);
        printf("Back in main thread\n");

}                          
