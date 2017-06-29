#include "print_field.h"

// This function saves the field values to a png file
void print_field(field * f)
{
    int error_code;

    error_code =
        save_png((double *) f->data, f->nx + 2, f->ny + 2, "datastructures-functions-heat_c-d.png",
                 'c');
    if (error_code == 0) {
        printf("Wrote output file datastructures-functions-heat_c-d.png\n");
    } else {
        printf("Error while writing output file datastructures-functions-heat_c-d.png\n");
    }
}
