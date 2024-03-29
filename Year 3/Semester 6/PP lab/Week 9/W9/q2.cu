#include "cuda_runtime.h"
#include <stdio.h>
#include "cudart_platform.h"
#include "device_launch_parameters.h"
#include "cuda.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

__device__ void cu_strcpy(char* dest, char* src, int dest_index, int src_index) {
	dest[dest_index] = src[src_index];
}

__global__ void produce(char *str, char *res, int *indices) {
	int x = threadIdx.x;

	int index = indices[x];
	for (int i = 0; i < 4 - x; i++) {
		res[index + i] = str[i];
		//cu_strcpy(res, str, index + i, i);
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
	for (int i = 1; i < len -1; i++) {
		indices[i] = indices[i - 1] + 5 - i;
	}

	char* device_str, * device_res;
	int* device_indices;
	const int int_size = len * sizeof(int);
	const int char_size = len * sizeof(char);

	cudaMalloc(&device_str, char_size);
	cudaMalloc(&device_res, char_size * len);
	cudaMalloc(&device_indices, int_size);

	cudaMemcpy(device_str, str, char_size, cudaMemcpyHostToDevice);
	cudaMemcpy(device_indices, indices, int_size, cudaMemcpyHostToDevice );

	produce << <1, len - 1>> > (str, res, indices);

	cudaMemcpy(res, device_res, char_size * len, cudaMemcpyDeviceToHost);
	
	printf("%s", res);

	return 0;
}