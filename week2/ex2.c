#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{

   int length, temp;
   char string[1000];
   char reverse[1000];
   printf("String:\n");
   fgets(string,1000,stdin);
 
   length = strlen(string); 
   temp = length - 1;

   for (int i = 0; i < length; i++)
   {
   		reverse[i] = string[temp];
   		temp--;
   }
 
   reverse[strlen(reverse)] = '\0';
   printf("Reverse:%s\n", reverse);
 
   return 0;
}