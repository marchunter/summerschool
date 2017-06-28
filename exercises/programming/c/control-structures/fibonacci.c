#include <stdio.h>

int main(int argc, char *argv[])
{
   int f0, f1, f2;
  
   // initialize variables and write the while loop
   // Remember to update all variables within the loop

f0 = 0; f1 = 1;
do {
	printf("Fibonacci number %d \n",f2);
	f2 = f1 + f0; 
	f0 = f1; 
	f1 = f2;
} 
while (f2 < 100);

/*
while (f2 < 100) {
	f2 = f1 + f0;
	f0 = f1;
	f1 = f2;
	printf("Fibonacci number %d \n",f2);
} */
return 0;
}
