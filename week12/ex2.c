#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main(int argc, char *argv[])
{
	int a = 0;
	
	if(argc > 1 && strcmp(argv[1], "-a") == 0)
		a = 1;
	
	int file_count = argc - a - 1;
	FILE **files = malloc(file_count * sizeof(FILE*));

	if(files == NULL)
	{
		printf("An error occurred allocating memory\n");
		return 1;
	}

	const char *mode = a ? "a" : "w";
	
	for(int i=0; i<file_count; i++)
	{
		files[i] = fopen(argv[i+a+1], mode);
		if(files[i] == NULL)
		{
			printf("Error occurred opening file %s\n", argv[i+a+1]);
			return 2;
		}
	}
	
	char buffer[128];
	while(fgets(buffer, 127, stdin) != NULL)
	{
		printf("%s", buffer);
		for(int i=0; i<file_count; i++)
		{
			fprintf(files[i], "%s", buffer);
		}
	}
	
	for(int i=0; i<file_count; i++)
	{
		fclose(files[i]);
	}
	
	free(files);
	
	return 0;
}