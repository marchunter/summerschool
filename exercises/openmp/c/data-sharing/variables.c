#include <stdio.h>
#include <omp.h>

int main(void)
{
    int var1 = 1, var2 = 2;
    int var3 = 3, var4 = 4;
    /* TODO:
     *   Test the effect of different data sharing clauses here
     */
#pragma omp parallel shared(var1) private(var3) firstprivate(var2)
    {
        printf("Region 1: var1=%i, var2=%d\n", var1, var2);
#pragma omp atomic
        var1++;
        var2++;
    }
    printf("After region 1: var1=%i, var2=%d\n\n", var1, var2);

    return 0;
}
