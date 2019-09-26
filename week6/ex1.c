#include "stdio.h"
#include "unistd.h"

char *st = "hello!";


int main(int argc, char const *argv[])
{
	int pips[2];
	char read_message[7];
	pipe(pips);
	printf("Write to pipe - %s\n", st);
	write(pips[1],st, sizeof(st));
	read(pips[0],read_message,sizeof(read_message));
	printf("Read from pipe - %s\n",read_message);
	return 0;
}

