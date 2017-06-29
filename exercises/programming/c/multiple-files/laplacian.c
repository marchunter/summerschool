#include "laplacian.h"
//This function computes the Laplacian of the field
void laplacian(field * f)
{
    // Array where we store the result
    double laplacian[NX + 2][NX + 2];
    int i, j;

    // Evaluate the Laplacian
    // *INDENT-OFF*
    for (i = 1; i < f->nx + 1; i++) {
        for (j = 1; j < f->ny + 1; j++) {
            laplacian[i][j] =
                (f->data[i-1][ j ] - 2.0 * f->data[i][j] + f->data[i+1][ j ]) / (f->dx * f->dx) +
                (f->data[ i ][j-1] - 2.0 * f->data[i][j] + f->data[ i ][j+1]) / (f->dy * f->dy);
        }
    }
    // *INDENT-ON*

    // Copy the results back to the struct
    for (i = 1; i < f->nx + 1; i++)
        for (j = 1; j < f->ny + 1; j++)
            f->data[i][j] = laplacian[i][j];
}

