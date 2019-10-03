#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MIN(x,y) (((x)<(y)) ? (x) : (y))

void* my_realloc(void* ptr, size_t new)
{
	if (ptr == NULL)
	{
		return malloc(new);
	}
	if (new == 0)
	{
		free(ptr);
	}
	void* newPtr = malloc(new);
	size_t current = ((size_t*)ptr)[-1];
    memcpy(ptr, newPtr, MIN((int) current,new));
    free(ptr);
    return newPtr;
}

int main(int argc, char const *argv[])
{

	int n = 3;  // set size

	int* a = (int*)malloc(n*sizeof(int));
	printf("before realloc:\n");
	for (int i = 0; i < n; ++i)
	{
		*(a+i) = i;
		printf("%d\n",*(a+i));
	}
	int new_size = 5; // set another size
	my_realloc(a,5);
	printf("after realloc:\n");
	for (int i = 0; i < new_size; ++i)
	{
		*(a+i) = 0;
		printf("%d\n", *(a+i));
	}

	return 0;
}