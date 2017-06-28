#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
	double arr[NX][NY];

    // Initialize first the zeros
	for (i=0; i<NX; i++) {
	for (j=0; j<NY; j++) {
	arr[i][j] = 0;
}};

    // Initial conditions for left and right
	for (i=0; i<NX; i++) {
	arr[i][0] = 20.0;
	arr[i][NY -1] = 70.0;
	};

    // and top and bottom boundaries
	for (j=0; j<NY; j++) {
	arr[0][j] = 85.0;
	arr[NX - 1][j] = 5.0;
	};


printf(" right: %f, upper: %f, center: %f. \n", arr[NX / 2][NY -1], arr[0][NX /2], arr[NX /2][NX /2]);  
    return 0;
}
