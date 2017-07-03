#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int n_rows = 8;
    int n_cols = 8;
    int array[n_rows][n_cols];
    //TODO: Declare a variable storing the MPI datatype 
    MPI_Datatype coltype;
    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    // Initialize arrays
    if (rank == 0) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = 0;
            }
        }
    }


    //TODO: Create datatype that describes one column. Use MPI_Type_vector.
    MPI_Type_vector(n_rows, 1, n_cols, MPI_INT, &coltype);
    MPI_Type_commit(&coltype);
    //TODO: Send first column of matrix form rank 0 to rank 1
    // Send only one element of coltype
    if (rank == 0) MPI_Send(array, 1, coltype, 1, 42, MPI_COMM_WORLD);

    else MPI_Recv(array, 1, coltype, 0, 42, MPI_COMM_WORLD, &status);

    /*MPI_Sendrecv(array, 1, coltype, 1, 42, 
        array, 1, coltype, 0, 42, 
        MPI_COMM_WORLD, &status);
    */
    //TODO: free datatype
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Type_free(&coltype);
    // Print out the result on rank 1
    // The application is correct if the first column has the values of rank 0
    if (rank == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);

    if (rank == 0) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }


    MPI_Finalize();

    return 0;
}
