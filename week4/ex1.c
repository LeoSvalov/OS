#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int n;
	if(n = fork())
	{
		printf("Hello from child [PID = %d]\n",n);
	}else{
		printf("Hello from parent [PID = %d]\n\n\n",n);
	}
	return 0;
}