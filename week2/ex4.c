#include "stdio.h"

void swap(int *num1, int *num2);

int main(int argc, char const *argv[])
{
	int number1,number2;
	scanf("%d\n", &number1);
	scanf("%d\n", &number2);

	swap(&number1,&number2);
	printf("number1 - %d, number2 -  %d\n",number1, number2);
	return 0;
}
void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}