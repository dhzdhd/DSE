#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <stdlib.h>

__global__ void add_arrays_gpu(int* a, int* b, int* c)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	c[index] = a[index] + b[index];
}

int main()
{
	int count;
	std::cout << "Enter length\n";
	std::cin >> count;

	int* host_a = new int[count];
	int* host_b = new int[count];
	int* host_c = new int[count];

	for (int i = 0; i < count; i++) {
		*(host_c + i) = 0;

		int r = rand() / 100;
		*(host_a + i) = r;
		r = rand() / 100;
		*(host_b + i) = r;
	}

	int* device_a, * device_b, * device_c;

	const int size = count * sizeof(int);

	cudaMalloc(&device_a, size);
	cudaMalloc(&device_b, size);
	cudaMalloc(&device_c, size);
	cudaMemcpy(
		device_a, host_a,
		size,
		cudaMemcpyHostToDevice
	);
	cudaMemcpy(
		device_b, host_b,
		size,
		cudaMemcpyHostToDevice
	);

	add_arrays_gpu <<< count / 256 + 1, 256 >>> (device_a, device_b, device_c);

	cudaMemcpy(
		host_c, device_c,
		size,
		cudaMemcpyDeviceToHost
	);

	for (auto i = 0; i < count; i++)
	{
		std::cout << host_a[i] << "+" << host_b[i] << "=" <<host_c[i] << "\n";
	}
	getchar();
	return 0;
}