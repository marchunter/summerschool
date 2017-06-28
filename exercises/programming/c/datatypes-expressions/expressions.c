#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare integers, floats, and doubles


   // evaluate expressions, e.g. c = a + 2.5 * b
   // and print out results. Try to combine integers, floats
   // and doubles and investigate what happens in type conversions

float c=4;
float a=2;
float b=3;
float *pa, *pb, *pc;
pa = &a;
pb = &b;
pc = &c;


c = a + 2.5 * b;

printf("c is %f \n", c);
printf("a is %f \n", a);
printf("b is %f \n", b);

//c = 5 / 2;
//a = 5 / 2;

//printf("integer division %f \n", c);

//c = 5 / 2.0;
//a = 5 / 2.0;

//printf("float division %f \n", c);


//c = sin((double) a*M_PI);


//printf("sin of PI %f \n", c);

*pc = a * (*pb);
*pc = *pa * (*pb);


printf("pointer multiplication %f \n", c);



   return 0;
}
