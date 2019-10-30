#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main(int argc, char const *argv[])
{
	
	struct stat bufstat;
	int f = open("ex1.txt", O_RDWR);
	void* map;
	int status = fstat(f, &bufstat);
	map = mmap(0,bufstat.st_size,PROT_READ | PROT_WRITE ,MAP_SHARED, f , 0);
	memcpy(map,"This a nice day!\n",bufstat.st_size);

	return 0;
}