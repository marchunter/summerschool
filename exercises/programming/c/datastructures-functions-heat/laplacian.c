#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 258
#define NY 258

#define DX 0.01
#define DY 0.01

typedef struct {
	int nx;
	int ny;
	double dx;
	double dy;
	double dx2;
	double dy2;
	double t_2d[NX][NY];
	double laplacian[NX][NY];
} field;

field t_init(field f, int nx, int ny, double dx, double dy) {
	f.nx = nx;
	f.ny = ny;
	f.dx = dx;
	f.dy = dy;
	f.dx2 = f.dx * f.dx;
	f.dy2 = f.dy * f.dy;
    int i,j;

    // First initalize the inner values to zero
    for (i = 1; i < f.nx - 2; i++) {
        for (j = 1; j < f.ny - 2; j++) {
            f.t_2d[i][j] = 0.0;
        }
    }

    // Zero out the outer boundary of laplacian
    for (i = 0; i < f.nx; i++)
        f.t_2d[i][0] = f.t_2d[i][f.ny - 1] = 0.0;
    for (j = 0; i < f.ny; j++)
        f.t_2d[0][j] = f.t_2d[f.nx - 1][j] = 0.0;

    // Initial conditions for top and bottom
    for (i = 0; i < f.nx; i++) {
        f.t_2d[i][0] = 30.0;
        f.t_2d[i][f.ny - 1] = -10.0;
    }
    // left and right
    for (j = 0; j < f.ny; j++) {
        f.t_2d[0][j] = 15.0;
        f.t_2d[f.nx - 1][j] = -25.0;
    }
return f;
};

field t_lapl(field f) {
int i,j;
    for (i = 1; i < f.nx - 2; i++) {
        for (j = 1; j < f.ny - 2; j++) {
            f.laplacian[i][j] =
                (f.t_2d[i-1][ j ] - 2.0 * f.t_2d[i][j] + f.t_2d[i+1][ j ]) / (f.dx2) +
                (f.t_2d[ i ][j-1] - 2.0 * f.t_2d[i][j] + f.t_2d[ i ][j+1]) / (f.dy2);
        }
    }


return f;
};


int main(void)
{
    int i, j, error_code;
    double array[NX][NY];
    double laplacian[NX][NY];

field X;
field initialised_field = t_init(X, NY, NY, DX, DY);

/*
    // First initalize the inner values to zero
    for (i = 1; i < NX - 2; i++) {
        for (j = 1; j < NY - 2; j++) {
            array[i][j] = 0.0;
        }
    }

    // Zero out the outer boundary of laplacian
    for (i = 0; i < NX; i++)
        laplacian[i][0] = laplacian[i][NY - 1] = 0.0;
    for (j = 0; i < NY; j++)
        laplacian[0][j] = laplacian[NX - 1][j] = 0.0;

    // Initial conditions for top and bottom
    for (i = 0; i < NX; i++) {
        array[i][0] = 30.0;
        array[i][NY - 1] = -10.0;
    }
    // left and right
    for (j = 0; j < NY; j++) {
        array[0][j] = 15.0;
        array[NX - 1][j] = -25.0;
    }
*/
    // Evaluate the Laplacian
    // *INDENT-OFF*


field calc_laplacian = t_lapl(initialised_field);
/*
    for (i = 1; i < NX - 2; i++) {
        for (j = 1; j < NY - 2; j++) {
            laplacian[i][j] =
                (array[i-1][ j ] - 2.0 * array[i][j] + array[i+1][ j ]) / (DX * DX) +
                (array[ i ][j-1] - 2.0 * array[i][j] + array[ i ][j+1]) / (DY * DY);
        }
    }
*/
/*        for (i=1; i<NX -1; i++) {
        for (j=1; j<NY -1; j++) {
        laplacian[i][j] += laplacian[i -1][j] - 2 * laplacian[i][j] + laplacian[i + 1][j] / (DX * DX) + laplacian[i][j - 1] - 2 * laplacian[i][j] + laplacian[i][j + 1] / (DY * DY);
	//printf("laplacian updated %f \n", laplacian[i][j]);

}};
*/

    // *INDENT-ON*

    // Call the png writer routine
    error_code = save_png((double *) initialised_field.t_2d, NX, NY, "datastructures_functions_heat-a_b.png", 'c');
    error_code = save_png((double *) calc_laplacian.laplacian, NX, NY, "datastructures_functions_heat-a_b.png", 'c');

    if (error_code == 0) {
        printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
    } else {
        printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
    }


    return 0;
}
