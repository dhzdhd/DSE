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
	int* arr = (int*)calloc(size, sizeof(int));
	int val;
	int* buf = (int*)calloc(size, sizeof(int));
	int buf_size = size + MPI_BSEND_OVERHEAD;

	if (rank == 0) {
		for (int i = 1; i < size; i++) {
			MPI_Buffer_attach(buf, buf_size);
			scanf_s("%d", arr + i);
			MPI_Bsend(arr + i, 1, MPI_INT, i, i, MPI_COMM_WORLD);
			MPI_Buffer_detach(&buf, &buf_size);
		}
	}
	else if (rank % 2 == 0) {
		MPI_Recv(&val, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		printf("Rank: %d, Square: %d\n", rank, val * val);
	}
	else {
		MPI_Recv(&val, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		printf("Rank: %d, Cube: %d\n", rank, val * val * val);
	}

	MPI_Finalize();

	return 0;
}
