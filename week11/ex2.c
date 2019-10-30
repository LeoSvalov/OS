#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char buffer[BUFSIZ];
	FILE *file1 = fopen("ex2.txt", "w");
	
	setbuf(file1,buffer);
	fputs("H",file1);
	sleep(1);
	fputs("e",file1);
	sleep(1);
	fputs("l",file1);
	sleep(1);
	fputs("l", file1);
	sleep(1);
	fputs("o", file1);
	sleep(1);
	fflush(file1);

    fclose(file1);
	return 0;
}