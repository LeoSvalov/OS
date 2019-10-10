#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pthread.h"
#include "unistd.h"

int main(int argc, char const *argv[])
{
	int size = 10*1024*1024;
	for (int i = 0; i < 10; ++i)
	{
		char* a = (char*)malloc(size);
		memset(a,'0',size);
		sleep(1);
	}
	
	return 0;
}