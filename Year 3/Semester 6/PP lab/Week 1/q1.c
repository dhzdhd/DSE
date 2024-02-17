// Reverse digits

#include <stdio.h>
#include <math.h>

int rev(int num)
{
	int buf = 0;
	while (num > 0)
	{
		buf = (10 * buf) + num % 10;
		num = num / 10;
	}

	return buf;
	printf("%d\n", buf);
}

int main()
{
	int arr[] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928}, n = 9;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rev(arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
