#include <stdio.h>
#include "mpi.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Status status;
	int val = 10;

	if (rank == 0) {
		scanf_s("%d", &val);
	}

	MPI_Barrier(MPI_COMM_WORLD);

	if (rank == 0) {
		MPI_Send(&val, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else {
		MPI_Recv(&val, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &status);
		
		val += 1;
		printf("Rank: %d, Sending: %d\n", rank, val);

		if (rank == size - 1) {
			MPI_Send(&val, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
		else {
			MPI_Send(&val, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
		}
	}

	if (rank == 0) {
		MPI_Recv(&val, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, &status);
		printf("Rank: %d, Root recieved: %d\n", rank, val);
	}

	MPI_Finalize();

	return 0;
}
