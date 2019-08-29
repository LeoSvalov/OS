#include "stdio.h"

int main(int argc, char const *argv[])
{

	int n;
	int counter = 1;
	scanf("%d\n", &n);
	int width = 2*n-1;
	int half;
	for (int i = 0; i < n; ++i)
	{
		half = (width - counter)/2;
		for (int j = 0; j < half; j++) printf("%s"," ");
		for (int j = 0; j < counter; j++) printf("%s","*");
		for (int j = 0; j < half; j++) printf("%s"," ");
		printf("\n");
		counter+=2;	
	}
	return 0;
}