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

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    if (s[rank] < 'a') {
        s[rank] = tolower(s[rank]);
    }
    else {
        s[rank] = toupper(s[rank]);
    }

    MPI_Gather(s, 5, MPI_CHAR, res, 5, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < 5; i++) {
            printf("%c", res[i]);
        }
        printf("\n");
    }
    
    MPI_Finalize();

    return 0;
}
