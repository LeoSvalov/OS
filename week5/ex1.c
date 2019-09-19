#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"

void *thread_function(void *var)
{
	int *thread_id = (int*) var;

	printf("Thread ID:%d\n",*thread_id );
	printf("Some text.\n");
	return NULL;
}
	
int main(int argc, char const *argv[])
{
	int n;
	printf("Input n:\n");
	scanf("%d/n",&n);
	pthread_t thread;
	for (int i = 0; i < n; ++i)
	{
		pthread_create(&thread, NULL, thread_function, (void*)&thread);

		pthread_join(thread,NULL); // this line forces the order of threads
	}
	pthread_exit(NULL);

	return 0;
}