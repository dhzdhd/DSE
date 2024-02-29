#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>

__global__ void add_arrays_gpu(int *a, int *b, int *c)
{
	c[threadIdx.x] = a[threadIdx.x] + b[threadIdx.x];
}

int main()
{
	int count;
	std::cout << "Enter length\n";
	std::cin >> count;

	std::cout << "Enter elements\n";
	int *host_a = new int[count];
	int *host_b = new int[count];
	int *host_c = new int[count];

	for (int i = 0; i < count; i++)
	{
		*(host_c + i) = 0;
		std::cin >> *(host_a + i);
		std::cin >> *(host_b + i);
	}

	int *device_a, *device_b, *device_c;

	const int size = count * sizeof(int);

	cudaMalloc(&device_a, size);
	cudaMalloc(&device_b, size);
	cudaMalloc(&device_c, size);
	cudaMemcpy(
		device_a, host_a,
		size,
		cudaMemcpyHostToDevice);
	cudaMemcpy(
		device_b, host_b,
		size,
		cudaMemcpyHostToDevice);

	add_arrays_gpu<<<1, count>>>(device_a, device_b, device_c);

	cudaMemcpy(
		host_c, device_c,
		size,
		cudaMemcpyDeviceToHost);

	for (auto i = 0; i < count; i++)
	{
		std::cout << host_c[i] << " ";
	}
	getchar();
	return 0;
}
