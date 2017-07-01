#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int i, myid, ntasks, rc;
    int size = 100000;
    int *message;
    int *receiveBuffer;
    MPI_Status status;
    
    int testnum = 5;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++) {
        message[i] = myid;
    }


    /* TODO: */
    /* Send and receive messages as defined in exercise */
    if (myid == 0) {
    rc = MPI_Recv(receiveBuffer, size, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    rc = MPI_Send(message, size, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Rank %i received %i\n", myid, receiveBuffer[0]);
    } else if (myid == 1) {
    rc = MPI_Send(message, size, MPI_INT, 0, 0, MPI_COMM_WORLD);
    rc = MPI_Recv(receiveBuffer, size, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        printf("Rank %i received %i\n", myid, receiveBuffer[0]);
    }


    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
