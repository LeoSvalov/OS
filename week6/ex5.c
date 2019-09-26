#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	
	if (fork() == 0)
	{
		for(;;)
		{
			printf("I am alive\n");
			sleep(1);
		}
	}else{
		sleep(10);
		kill(0, SIGTERM);
	}
	return 0;
}