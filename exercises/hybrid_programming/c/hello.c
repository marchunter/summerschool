// Hello world with mpi and openmp

#include <omp.h>
#include <mpi.h>
#include <stdio.h>

void main(int argc, char *argv[]) {

	int rank;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

#pragma omp parallel 
	{	
	int thread;	
	thread = omp_get_thread_num();

	printf("Hello, world - signed by process %d, thread %d.\n", rank, thread);
	}

	MPI_Finalize();

}	