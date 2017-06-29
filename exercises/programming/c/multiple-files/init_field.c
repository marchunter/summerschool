#include "init_field.h"
// This routine initializes the values of field structure
void init_field(field * f, int nx, int ny)
{
    int i, j;

    f->nx = nx;
    f->ny = ny;
    f->dx = DX;
    f->dy = DY;
    f->dx2 = DX * DX;
    f->dy2 = DY * DY;

    // First zero out the inner part of the array
    for (i = 1; i < f->nx + 1; i++)
        for (j = 1; j < f->ny + 1; j++)
            f->data[i][j] = 0.0;

    // Initial conditions for top and bottom
    for (i = 0; i < f->nx + 2; i++) {
        f->data[i][0] = 30.0;
        f->data[i][f->ny + 1] = -10.0;
    }
    // and left and right boundaries
    for (j = 0; j < f->ny + 2; j++) {
        f->data[0][j] = 15.0;
        f->data[f->nx + 1][j] = -25.0;
    }
}
