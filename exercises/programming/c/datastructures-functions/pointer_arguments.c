#include <stdio.h>

// function of type void is defined (doesn't return anything), takes inputs which are defined pointers to integers 
void add_one_to_both(int *a, int *b) {

*a +=1;
*b +=1;

}

int main(void) {
// values initialised
int a = 10;
int b = 20;

// function is called
add_one_to_both(&a, &b);

printf("a is %d and b is %d \n", a,b);


return 0;
} 
