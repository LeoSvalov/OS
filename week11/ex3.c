#include <stdio.h>
#include <unistd.h>


void var1(){

	printf("Hello");
	 fork(); 
	printf("\n");

}

void var2(){

	printf("Hello\n"); 
	fork(); 
	printf("\n"); 
	
}


int main(int argc, char const *argv[])
{
	// var1();
	var2();
	return 0;
}