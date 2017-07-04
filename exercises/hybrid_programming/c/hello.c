// Hello world with mpi and openmp

void main(int *argc, char argv[]) {

	MPI_Init();
	MPI_Comm_rank(MPI_COMM_WORLD);

#pragma omp parallel
	int id;	
	id = get_omp_thread_num();

	printf("Hello, world - signed by process %d, thread %d.\n", rank, thread);


	MPI_Finalize();

}	