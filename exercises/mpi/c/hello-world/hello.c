#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
int rank, rc, size;


        printf("Initializing MPI!!!!\n");

MPI_Init(&argc, &argv);

rc = MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello world! - MPI size: %d\n", size);
rc = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
if (rank == 2) {
    printf("Hello world! - process with rank %d\n", rank);
    printf("command line argument 1 %s\n, 2 is %s\n", &argv[1][0],&argv[2][0] );
}
MPI_Finalize();

//#pragma omp parallel
    {
        printf("X\n");
    }

    return 0;
}
