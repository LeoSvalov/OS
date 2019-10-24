#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>



struct file
{
	unsigned long inode;
	char filenames[50][10];
	int file_count;
};

int main(int argc, char const *argv[])
{
	DIR *dir = opendir("./tmp");
	if(dir == NULL)
	{
		printf("Error occurred opening folder\n");
		return 1;
	}
	
	struct file files[50];
	int file_count = 0;
	for(int i=0; i<50; i++)
	{
		files[i].inode = 0;
		files[i].file_count = 0;
	}
	
	//???
	
	
	return 0;
}