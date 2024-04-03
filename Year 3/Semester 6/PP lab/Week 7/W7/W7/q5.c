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
	int len, *arr, val;

	if (rank == 0) {
		scanf_s("%d", &len);	
	}

	MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);

	arr = (int *)calloc(len, sizeof(int));

	if (rank == 0) {
		for (int i = 0; i < len; i++) {
			scanf_s("%d", arr + i);
		}
	}

	MPI_Scatter(arr, 1, MPI_INT, &val, 1, MPI_INT, 0, MPI_COMM_WORLD);

	// Check prime
	int flag = 1;
	for (int i = 2; i <= val / 2; i++) {
		if (val % i == 0) {
			flag = 0;
			break;
		}
	}

	if (val == 1) flag = 0;

	if (flag) {
		printf("Rank: %d, Value: %d is a prime", rank, val);
	}
	else {
		printf("Rank: %d, Value: %d is not a prime", rank, val);
	}

	MPI_Finalize();

	return 0;
}
