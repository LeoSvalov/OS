#include "sys/resource.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pthread.h"
#include "unistd.h"


int main(int argc, char const *argv[])
{
	struct rusage *usage = (struct rusage*)malloc(sizeof(struct rusage));
	int error;
	int size = 10*1024*1024;
	for (int i = 0; i < 10; ++i)
	{
		char* a = (char*)malloc(size);
		memset(a,'0',size);
		error = getrusage(RUSAGE_SELF, usage);
  		printf("%ld\n", (*usage).ru_maxrss);
		sleep(1);
	}
	
	return 0;
}
 
