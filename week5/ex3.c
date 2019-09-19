#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_SIZE 5

int buffer = 2;
void* Producer(int *a)
{
    // for (;;)
    for (int i = 0; i < 10; ++i)
    {
        if (buffer < BUFFER_SIZE)
        {
            buffer++;
        }
        printf("Amount of items:%d\n \n",buffer);
        sleep(1);
    }
}
void* Consumer(int *a)
{
    // for (;;)
    for (int i = 0; i < 10; ++i)
    {
        if (buffer > 0)
        {
            buffer--;
        }
        printf("Amount of items:%d\n \n",buffer);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    
    pthread_t producer_tid,consumer_tid;          
    pthread_create(&producer_tid,NULL,Producer,NULL);
    pthread_create(&consumer_tid,NULL,Consumer,NULL);
    pthread_join(producer_tid,NULL);  
    pthread_join(consumer_tid,NULL);
	return 0;
}


