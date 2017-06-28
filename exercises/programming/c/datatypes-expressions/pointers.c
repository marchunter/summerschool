#include <stdio.h>

int main(int argc, char *argv[])
{
   int a, b, c;
   // declare a pointer variable and assign it to address of e.g. a
   
   // Evaluate expressions using both the original and the pointer variable
   // and investigate the value / value pointed to

a = 3;
b = 4;
c = 5;

int *pa, *pb, *pc;

pa = &a;
pb = &b;
pc = &c;

c = a + 2 * b;
*pc = *pa = *pb;


c = a + 2 * b;

printf("c is %d \n", c);

   return 0;
}
