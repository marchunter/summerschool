#include <stdio.h>
#include <omp.h>

#define NX 1024000

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i+1;
    }

    sum = 0.0;
    /* TODO: Parallelize computation */
long internal_sum = 0;
#pragma omp parallel firstprivate(internal_sum) 
{    for (i = 0; i < NX; i++) 
	{
        internal_sum += vecA[i];
	
    	}
#pragma omp critical
        sum += internal_sum;
}
    printf("Sum: %ld\n",sum);
        
    long S = ((long) NX)* ((long) (NX+1)) / 2;
    printf("Reference: %ld\n", S);
    return 0;
}
