#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"

void f(int sig_number){
	printf("\nHello! YOLO!\n");
}

int main(int argc, char const *argv[])
{
	signal(2,f);
	sleep(10);
	return 0;
}