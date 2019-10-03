#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	int N;
	printf("Input N:\n");
	scanf("%d/n",&N);

	int *a;
	a = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; ++i)
	{
		*(a+i)= i;
		printf("%d\n",*(a+i));
	}

	free(a);
	return 0;
}