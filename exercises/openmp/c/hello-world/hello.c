#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char author[5] ="Marc";
	int shared_num = 42;
	int omp_rank;
	int init_num = 5;
    printf("Hello world!\n");
#pragma omp parallel shared(author, shared_num) private(omp_rank) firstprivate(init_num)
    {
	#pragma omp single
	{
	int omp_threads = omp_get_num_threads(); 
	printf("Number of active threads: %d\n", omp_threads);
	}
	omp_rank = omp_get_thread_num();
	init_num += omp_rank;
        printf("Hello by thread %d, shared number: %d, init_num + omp_rank = %d, -Yours sincerely %s\n", omp_rank, shared_num, init_num, author);
    }

    return 0;
}
