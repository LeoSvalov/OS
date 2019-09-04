#include "stdio.h"

void quick_sort(int arr[],int left, int right)
{
	int pivot;
	int temporary;
	if (left < right)
	{
		pivot = left;
		int i = left;
		int j = right;

		while(i < j)
		{
			while(arr[i] <= arr[pivot] && i < right)
			{
				i++;
			}
			while(arr[j] > arr[pivot])
			{
				j--;
			}
			if(i < j)
			{
				temporary = arr[i];
				arr[i] = arr[j];
				arr[j] = temporary;
			}
		}
		temporary = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temporary;
		quick_sort(arr,left,j-1);
		quick_sort(arr,j+1,right);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Input number of elements of an array:\n");
	scanf("%d/n",&n);
	int arr[n];
	printf("Input elements:\n");
	int temporary;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d/n",&arr[i]);
	}

	quick_sort(arr,0,n-1);

	printf("The sorted array:");
	for (int i = 0; i < n; ++i)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	
	return 0;
}
