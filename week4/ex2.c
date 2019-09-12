#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i)
	{
		fork();
		sleep(5);
	}
	return 0;
}

