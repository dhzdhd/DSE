#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

__global__ void sine_gpu(double* a, double* b)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	b[index] = __sinf(a[index]);
}

int main()
{
	int count;
	std::cout << "Enter length of array\n";
	std::cin >> count;

	double* host_a = new double[count];
	double* host_b = new double[count];

	for (int i = 0; i < count; i++) {
		*(host_b + i) = 0.0;

		int r = (double)rand() / 100;
		*(host_a + i) = r;
	}

	double * device_a, * device_b;

	const int size = count * sizeof(int);

	cudaMalloc(&device_a, size);
	cudaMalloc(&device_b, size);
	cudaMemcpy(
		device_a, host_a,
		size,
		cudaMemcpyHostToDevice
	);

	int blocks = count / 100 + 1;
	int threads = 100;
	sine_gpu << < blocks, threads >> > (device_a, device_b);

	cudaMemcpy(
		host_b, device_b,
		size,
		cudaMemcpyDeviceToHost
	);

	for (auto i = 0; i < count; i++)
	{
		std::cout << "sine " << host_a[i] << " = " << host_b[i] << "\n";
	}
	getchar();
	return 0;
}
