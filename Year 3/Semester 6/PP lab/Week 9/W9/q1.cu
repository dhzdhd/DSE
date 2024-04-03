#include "cuda_runtime.h"
#include <stdio.h>
#include "cudart_platform.h"
#include "device_launch_parameters.h"
#include "device_atomic_functions.h"
#include "device_functions.h"
#include "cuda.h"
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

__global__ void count(char* str, char* pattern, int* res, int len_s, int len_p) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;
	int extent = len_s - len_p;

	bool isPresent = true;
	//if (x <= extent) {
		for (int i = 0; i < len_p; i++) {
			if (str[x + i] != pattern[i]) {
				isPresent = false;
				break;
			}
		}

		if (isPresent) {
			atomicAdd(res, 1);
		}
	//}
}

int main() {
	int len_s, len_p;

	printf("Enter size of string and pattern\n");
	scanf("%d%d", &len_s, &len_p);
	getchar();

	char* str = (char*)malloc(len_s * sizeof(char));
	char* pattern = (char*)malloc(len_p * sizeof(char));
	int res = 0;

	printf("Enter string\n");
	gets_s(str, len_s);

	printf("Enter pattern\n");
	gets_s(str, len_p);

	char* device_str, * device_pattern;
	int* device_res;

	cudaMalloc((void**)&device_str, len_s * sizeof(char));
	cudaMalloc((void**)&device_pattern, len_p * sizeof(char));
	cudaMalloc((void**)&device_res, sizeof(int));

	cudaMemcpy(device_str, str, len_s * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(device_pattern, pattern, len_p * sizeof(char), cudaMemcpyHostToDevice);
	//cudaMemcpy(device_res, &res, sizeof(int), cudaMemcpyHostToDevice);

	count << <1, len_s - len_p >> > (device_str, device_pattern, device_res, len_s, len_p);

	cudaMemcpy(&res, device_res, sizeof(int), cudaMemcpyDeviceToHost);

	printf("%d", res);

	return 0;
}
