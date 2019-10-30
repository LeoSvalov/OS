#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int f1 = open("ex1.txt", O_RDWR);
 	struct stat fileStat;
 	fstat(f1,&fileStat);
 	
    FILE *f_2 = fopen("ex1.memcpy.txt", "w");
    ftruncate(fileno(f_2), fileStat.st_size);
    fclose(f_2);

	void* map_1 = mmap(0, fileStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, f1, 0);
	close(f1);
	int f2 = open("ex1.memcpy.txt",O_RDWR);
	void* map_2 = mmap(0,fileStat.st_size,PROT_WRITE|PROT_READ, MAP_SHARED, f2,0);
	memcpy(map_2,map_1,fileStat.st_size);

	return 0;
}