#include <stdio.h>
#include "mpi.h"
#include <math.h>

int main(int argc, char* argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int a = (int)*argv[1] - (int)'0';
    int b = (int)*argv[2] - (int)'0';

    if (rank == 0) {
        printf("Sum: %d\n", a + b);
    }
    else if (rank == 1) {
        printf("Difference: %d\n", a - b);
    }
    else if (rank == 2) {
        printf("Product: %d\n", a * b);
    }
    else {
        printf("Quotient: %f\n", (float)a / b);
    }

    MPI_Finalize();

    return 0;
}
