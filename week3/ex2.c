#include "stdio.h"
#include "stdlib.h"
void bubble_sort(int arr[], int arr_length);
void swap(int *var1, int *var2);

int main(int argc, char const *argv[])
{
	int arr_length;
	printf("Input length of array:\n");
	scanf("%d/n",&arr_length);
	printf("Input elements:\n");
	int *arr = (int*)malloc(sizeof(int)*arr_length);
	for (int i = 0; i < arr_length; ++i)
	{
		scanf("%d/n",&arr[i]);
	}
	
	bubble_sort(arr,arr_length);

	printf("The array after sort -");
	for (int i = 0; i < arr_length; ++i)
	{
		printf(" %d",arr[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void bubble_sort(int arr[], int arr_length)
{
	for (int i = 0; i < arr_length; ++i)
	{
		for (int j = 0; j < arr_length - i - 1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}