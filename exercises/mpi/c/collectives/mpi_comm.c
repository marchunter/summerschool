#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define NTASKS 4

void print_buffers(int *printbuffer, int *sendbuffer, int buffersize);
void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize);


int main(int argc, char *argv[])
{
    int ntasks, rank, color;
    int sendbuf[2 * NTASKS], recvbuf[2 * NTASKS];
    int printbuf[2 * NTASKS * NTASKS];

    MPI_Comm sub_comm;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (ntasks != NTASKS) {
        if (rank == 0) {
            fprintf(stderr, "Run this program with %i tasks.\n", NTASKS);
        }
        MPI_Abort(MPI_COMM_WORLD, -1);
    }

    /* Initialize message buffers */
    init_buffers(sendbuf, recvbuf, 2 * NTASKS);

    /* Print data that will be sent */
    print_buffers(printbuf, sendbuf, 2 * NTASKS);

    /* TODO: use a single collective communication call (and maybe prepare
     *       some parameters for the call) */

    int arr_size = 2 * NTASKS;
    int n_el_per_send = arr_size / NTASKS;
    //int arr_recvcounts[NTASKS] = {1,1,2,4};
    //int arr_displs[NTASKS] = {0,1,2,4};
    if (rank <= 1) {color = 1;}
    else               {color = 2;}
    
    
    int subcomm;    
    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &subcomm);
    // rank in subcommunicator
    int mysubid;
    MPI_Comm_rank(subcomm, &mysubid);
    
    // assignment of new ranks in order due to key in MPI_Comm_split
    int subcomm_root;
    subcomm_root = 0;
    // reduction to process with subrank 0
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(sendbuf, recvbuf, arr_size, MPI_INT, MPI_SUM, subcomm_root, subcomm);
    
    printf("I am rank %d in MPI_COMM_WORLD, but %d in Comm %d.\n", rank, mysubid, color);
    /* Print data that was received */
    /* TODO: add correct buffer */
    print_buffers(printbuf, recvbuf, 2 * NTASKS);

    MPI_Finalize();
    return 0;
}


void init_buffers(int *sendbuffer, int *recvbuffer, int buffersize)
{
    int rank, i;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 0; i < buffersize; i++) {
        recvbuffer[i] = -1;
        sendbuffer[i] = i + buffersize * rank;
    }
}


void print_buffers(int *printbuffer, int *sendbuffer, int buffersize)
{
    int i, j, rank, ntasks;

    MPI_Gather(sendbuffer, buffersize, MPI_INT,
               printbuffer, buffersize, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

    if (rank == 0) {
        for (j = 0; j < ntasks; j++) {
            printf("Task %i:", j);
            for (i = 0; i < buffersize; i++) {
                printf(" %2i", printbuffer[i + buffersize * j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}