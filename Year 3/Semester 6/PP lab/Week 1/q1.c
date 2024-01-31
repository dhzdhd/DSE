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
	int arr[100], n;

	printf("Enter num of elements\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	int i = 0;
	for (; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = rev(arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
