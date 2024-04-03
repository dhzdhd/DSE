#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

int main(int argc, char* argv[])
{
    int rank, size;
    char *s = argv[1];
    char *res = calloc(6, sizeof(char));
    char buf;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (s[rank] < 'a') {
        buf = tolower(s[rank]);
    }
    else {
        buf = toupper(s[rank]);
    }

    MPI_Gather(&buf, 1, MPI_CHAR, res, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("%s", res);
    }
    
    MPI_Finalize();

    return 0;
}
