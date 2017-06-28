#include <stdio.h>

int main(int argc, char *argv[])
{
   int i;

   // write the control structure as described in the exercise
   // and run the code with different values for i

int j;
i = -110;
j = 3;

if (i == 0) {j=0;}
else if (i < 0) {j=1;}
else if (i > 100) {j=2;}; 

switch(j){
	case 0:
	printf("i is zero \n");
	break;
	case 1:
	printf("i is negative \n");
	break;
	case 2:
	printf("i is larger than 100 \n");
	break;
	default:
	printf("i is between 1 and 100 \n");

}
   return 0;
}
