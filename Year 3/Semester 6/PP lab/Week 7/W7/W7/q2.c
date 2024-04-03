#include <stdio.h>
#include "mpi.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, int* argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int num = 5;
	int buf;
	MPI_Status status;

	if (rank == 0) {
		for (int i = 1; i < size; i++) {
			MPI_Send(&num, 1, MPI_INT, i, i, MPI_COMM_WORLD);
		}
	}
	else {
		MPI_Recv(&buf, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		printf("Rank: %d, %d\n", rank, buf);
	}

	MPI_Finalize();

	return 0;
}
