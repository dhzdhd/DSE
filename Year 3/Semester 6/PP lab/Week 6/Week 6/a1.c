#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

int reverse(int num) {
    int buf = 0;
    while (num > 0) {
        buf = buf * 10 + num % 10;
        num /= 10;
    }

    return buf;
}

int main(int argc, char* argv[])
{
    int rank, size;
    int arr[] = { 18, 523, 301, 1234, 2, 14, 108, 150, 1928};
    int* res = calloc(9, sizeof(int));

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    arr[rank] = reverse(arr[rank]);

    MPI_Gather(arr, 9, MPI_INT, res, 9, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < 9; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}
