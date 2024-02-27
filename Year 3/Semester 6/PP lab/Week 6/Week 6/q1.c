#include <stdio.h>
#include "mpi.h"
#include <math.h>

int main(int argc, char * argv[])
{
    int rank, size, n = 5;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Process: %d | Result: %0.0f", rank, pow(n, rank));

    MPI_Finalize();

    return 0;
}
