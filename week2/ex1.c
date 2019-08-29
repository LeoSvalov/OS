#include "stdio.h"
#include "limits.h"
#include "float.h"

int main(int argc, char const *argv[])
{
	
	int variable1 = INT_MAX;
	double variable2 = DBL_MAX;
	float variable3 = FLT_MAX;
	printf("%d\n%e\n%e",variable1,variable2,variable3);
	return 0;
}