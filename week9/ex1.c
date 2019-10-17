#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <limits.h>
int *arr_address;
int *arr_age;
int hits;
int misses;

int miss(int page,int n){
	
	for (int i = 0; i < n; ++i)
	{
		if (arr_address[i] == 0)
		{
			arr_address[i] = page;
			arr_age[i] = 1<<31;
			return 1;
		}
	}
	return 0;
}

int hit(int page,int n){

	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		arr_age[i] = arr_age[i] >> 1; // tik
		if (temp != 1 && arr_address[i] == page) 
		{
			arr_age[i] += (1<<31);
			temp = 1;
			return 1;

		}
	}
	return 0;
}

void replace(int page, int n){

	int min_page_age = arr_age[0];
	int min_page_ind = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr_age[i] < min_page_age)
		{
			min_page_age = arr_age[i];
			min_page_ind = i;
		}
	}
	arr_age[min_page_ind] = 1<<31;
	arr_address[min_page_ind] = page;
	
}
int main(int argc, char const *argv[])
{
	
	FILE *input_file;
	input_file = fopen("Lab_09_input.txt","r");
	int input;
	
	int n;
	printf("Input number of page frames:\n");
	scanf("%d/n",&n);
	arr_address = (int*)malloc(n*sizeof(int));
	arr_age = (int*)malloc(n*sizeof(int));
	
	hits = 0;
	misses = 0;
	int i = 0; 

	while(fscanf(input_file,"%i",&(input)) != EOF){
		int h = hit(input,n);
		if (h == 1)
		{
			hits++;
		}else{
			int m = miss(input,n);
			if (m == 1)
			{
				misses++;
			}else{
				replace(input,n);
				misses++;
			}
		}	
		
	}
	printf("Hitrates/Missrates ratio: %d/%d = %f\n",hits,misses,(double)hits/(double)misses );
	fclose(input_file);
	return 0;
}