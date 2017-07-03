#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mpi.h>

#define DATASIZE   64
#define WRITER_ID   0

int ntasks;

void single_writer(int, int *, int);


int main(int argc, char *argv[])
{
    int my_id, i, localsize;
    int *localvector;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    if (ntasks > 64) {
        fprintf(stderr, "Datasize (64) should be divisible by number "
                "of tasks.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    if (DATASIZE % ntasks != 0) {
        fprintf(stderr, "Datasize (64) should be divisible by number "
                "of tasks.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    localsize = DATASIZE / ntasks;
    localvector = (int *) malloc(localsize * sizeof(int));

    for (i = 0; i < localsize; i++) {
        localvector[i] = i + 1 + localsize * my_id;
    }

    single_writer(my_id, localvector, localsize);

    free(localvector);

    MPI_Finalize();
    return 0;
}

void single_writer(int my_id, int *localvector, int localsize)
{
    FILE *fp;
    int *fullvector;

    /* TODO: Implement a function that will write the data to file so that
       a single process does the file io. Use rank WRITER_ID as the io rank */
    
    fullvector = (int *) malloc(DATASIZE * sizeof(int));

    MPI_Gather(localvector, localsize, MPI_INT, 
        fullvector, localsize, MPI_INT, 
        WRITER_ID, MPI_COMM_WORLD);

    if (my_id == WRITER_ID) {
        printf("Writing to singlewriter.dat\n");
        for (int i = 0; i < DATASIZE; i++) {
            printf("First entry looks like %d\n", fullvector[i]);
        }
        /*
        fp=fopen("singlewriter.dat", "wb");
        //fprintf(fp, "Don't forget to write stuff\n");
        for (int i = 0; i < DATASIZE; i++) {
            fprintf(fp, "%d ", fullvector[i]);
        }
        fclose(fp);
        */

        //fprintf(fp, fullvector);
        fp=fopen("singlewriter.dat", "wb");
        fwrite(fullvector, sizeof(int), DATASIZE, fp);
        fclose(fp);
        }

    printf("Writing to single files\n");
    for (int i = 0; i < ntasks; i++) {
        printf("Task %d is writing.\n", i);
        if (my_id == i) {
            char string[1024];
            sprintf(string, "task%d.dat", my_id);
            fp=fopen(string, "wb");
            fwrite(localvector, sizeof(int), localsize, fp);
            fclose(fp);
        }
    }
    free(fullvector);
}

