#include "stdio.h"
#include "unistd.h"

char *st = "hello!";


int main(int argc, char const *argv[])
{
	int pips[2];
	char read_message[7];
	pipe(pips);

	if (fork() != 0)
	{
		close(pips[0]);
		write(pips[1], st, sizeof(st));
		printf("Parent with id =%d  has sent to pipe - %s\n",getpid(),st);
		close(pips[1]);
 	}else{
 		close(pips[1]);
		read(pips[0], read_message, sizeof(read_message));
		printf("Child with id =%d  has receiced from pipe - %s\n",getpid(),read_message);
		close(pips[0]);
	}

	return 0;
}

