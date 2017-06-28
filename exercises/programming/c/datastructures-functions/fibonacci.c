#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare array and loop variable
   int f[20];
   int i;

   // initialize necessary array elements and write the for loop

   printf("First 20 Fibonacci numbers are:\n");
   for (i=0; i < 20; i++) {
	if (i == 0) {f[i] = 0;}
	else if (i == 1) {f[i] = 1;}
	else {
	f[i] = f[i - 1] + f[i -2];
	}
       	printf("%d ", f[i]);

   }

   printf("\n"); 

   return 0;
}
