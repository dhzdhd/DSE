#include <stdio.h>
#include "mpi.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, int *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	char word[] = "Hello";
	char* buf = calloc(6, sizeof(char));
	char* buf2 = calloc(6, sizeof(char));
	MPI_Status status;

	if (rank == 0) {
		MPI_Ssend(word, 6, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
	}
	if (rank == 1) {
		MPI_Recv(buf, 6, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);

		for (int i = 0; i < 6; i++) {
			if (buf[i] >= 'a') {
				buf[i] = toupper(buf[i]);
			}
			else {
				buf[i] = tolower(buf[i]);
			}
		}

		MPI_Ssend(buf, 6, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
	}
	if (rank == 0) {
		MPI_Recv(buf2, 6, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &status);

		printf("%s\n", buf2);
	}

	MPI_Finalize();

	return 0;
}
