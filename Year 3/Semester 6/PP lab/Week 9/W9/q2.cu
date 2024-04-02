#include "cuda_runtime.h"
#include <stdio.h>
#include "cudart_platform.h"
#include "device_launch_parameters.h"
#include "cuda.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

__global__ void produce(char *str, char *res, int *indices) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;

	int index = indices[x];
	for (int i = 0; i < 4 - x; i++) {
		res[index + i] = str[i];
	}
}

int main() {
	int len;

	printf("Enter size of string\n");
	scanf("%d", &len);
	getchar();

	char* str = (char*)malloc(len * sizeof(char));
	char *res = (char*)malloc(len * len * sizeof(char));
	int* indices = (int*)malloc(len * sizeof(int));

	printf("Enter string\n");
	gets_s(str, len);

	memset(indices, 0, len * sizeof(int));
	for (int i = 1; i < len - 1; i++) {
		indices[i] = indices[i - 1] + len - i;
	}

	char* device_str, * device_res;
	int* device_indices;

	cudaMalloc((void **) & device_str, len * sizeof(char));
	cudaMalloc((void**)&device_res, len * len * sizeof(char));
	cudaMalloc((void**)&device_indices, len * sizeof(int));

	cudaMemcpy(device_str, str, len * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(device_indices, indices, len * sizeof(int), cudaMemcpyHostToDevice);

	produce << <1, len - 1 >> > (device_str, device_res, device_indices);

	cudaMemcpy(res, device_res, len * len * sizeof(char), cudaMemcpyDeviceToHost);
	
	printf("%s", res);

	cudaFree(device_str);
	cudaFree(device_res);
	cudaFree(device_indices);

	free(str);
	free(res);
	free(indices);

	return 0;
}
