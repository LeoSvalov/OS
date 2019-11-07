#include "stdio.h"
#include "stdlib.h"



int main(int argc, char const *argv[])
{
	
	FILE *f = fopen("/dev/random", "r");
    char *file_open = (char *) malloc(sizeof(char));
    fgets(file_open, 20, f);
    puts(file_open);

	return 0;
}