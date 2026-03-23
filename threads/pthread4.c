

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

struct structure
{
	int i;
	char ch;
};

void *thread_function(void *arg)
{
        int *ptr = (int *)arg;
	printf("Print first two elements in an array: %d, %d\n", ptr[0], ptr[1]);
        return NULL;
}
void *thread_function1(void *arg)
{
	struct structure *s1 = (struct structure *)arg;
	printf("Roll no: %d\nGrade: %d\n", s1->i, s1->ch);
	return NULL;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	struct structure s1 = {123, 'A'};

        pthread_t tid1, tid2;
        if(pthread_create(&tid1, NULL, thread_function, (int *)arr) != 0)
        {
                printf("Thread is not created\n");
                return -1;
        }
        //sleep(5);
	if(pthread_create(&tid2, NULL, thread_function1, (void *)&s1) != 0)
        {
                printf("Thread is not created\n");
                return -1;
        }

        pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
        printf("Back in main thread\n");


}
