#include<stdio.h>
#include<pthread.h>


typedef struct 
{
	int n1, n2, res;
}data_t;

void *thread_function(void *arg)
{
	data_t *d = (data_t *)arg;
	d->res = d->n1 + d->n2;
	return NULL;
}
int main()
{
	pthread_t tid;
	data_t d = {10, 20};
	pthread_create(&tid, NULL, thread_function, (void *)&d);
	pthread_join(tid, NULL);
	printf("Back to the main thread and res: %d\n", d.res);
	return 0;
}	
