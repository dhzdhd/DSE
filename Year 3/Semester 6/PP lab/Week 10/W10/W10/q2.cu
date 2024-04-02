
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

__global__ void rowKernel(int* c, const int* a, const int* b)
{
    int i = blockDim.y * blockIdx.y + threadIdx.y;

    if (i < SIZE) {
        for (int j = 0; j < SIZE; j++) {
            int buf = 0;
            for (int k = 0; k < SIZE; k++) {
                buf += a[i * SIZE + k] * b[k * SIZE + j];
            }
            c[i * SIZE + j] = buf;
        }
    }
}

__global__ void colKernel(int* c, const int* a, const int* b)
{
    int j = blockDim.x * blockIdx.x + threadIdx.x;

    if (j < SIZE) {
        for (int i = 0; i < SIZE; i++) {
            int buf = 0;
            for (int k = 0; k < SIZE; k++) {
                buf += a[i * SIZE + k] * b[k * SIZE + j];
            }
            c[i * SIZE + j] = buf;
        }
    }
}

__global__ void allKernel(int* c, const int* a, const int* b)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    int j = blockDim.y * blockIdx.y + threadIdx.y;

    int buf = 0;

    if (i < SIZE && j < SIZE) {
        for (int k = 0; k < SIZE; k++) {
             buf += a[i * SIZE + k] * b[k * SIZE + j];
        }
        c[i * SIZE + j] = buf;
    }
}

int main()
{

    int* a = (int*)calloc(SIZE * SIZE, sizeof(int));
    int* b = (int*)calloc(SIZE * SIZE, sizeof(int));
    int* c = (int*)calloc(SIZE * SIZE, sizeof(int));

    for (int i = 0; i < SIZE * SIZE; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;

        printf("%d,%d  ", a[i], b[i]);
        if ((i + 1) % SIZE == 0 && i != 0) {
            printf("\n");
        }
    }
    printf("\n");

    int* dev_a, * dev_b, * dev_c;
    cudaMalloc((int**)&dev_a, SIZE * SIZE * sizeof(int));
    cudaMalloc((int**)&dev_b, SIZE * SIZE * sizeof(int));
    cudaMalloc((int**)&dev_c, SIZE * SIZE * sizeof(int));

    cudaMemcpy(dev_a, a, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice);

    dim3 row_threads(SIZE, SIZE, 1);
    dim3 row_blocks(1, 1, 1);

    rowKernel << <row_blocks, row_threads >> > (dev_c, dev_a, dev_b);

    cudaMemcpy(c, dev_c, SIZE * SIZE * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < SIZE * SIZE; i++) {
        printf("%d  ", c[i]);
        if ((i + 1) % SIZE == 0 && i != 0) {
            printf("\n");
        }
    }

    printf("\n");

    dim3 col_threads(SIZE, SIZE, 1);
    dim3 col_blocks(1, 1, 1);

    colKernel << <col_blocks, col_threads >> > (dev_c, dev_a, dev_b);

    cudaMemcpy(c, dev_c, SIZE * SIZE * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < SIZE * SIZE; i++) {
        printf("%d  ", c[i]);
        if ((i + 1) % SIZE == 0 && i != 0) {
            printf("\n");
        }
    }

    printf("\n");

    dim3 all_threads(SIZE, SIZE, 1);
    dim3 all_blocks(1, 1, 1);

    allKernel << <all_blocks, all_threads >> > (dev_c, dev_a, dev_b);

    cudaMemcpy(c, dev_c, SIZE * SIZE * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < SIZE * SIZE; i++) {
        printf("%d  ", c[i]);
        if ((i + 1) % SIZE == 0 && i != 0) {
            printf("\n");
        }
    }

    return 0;
}

