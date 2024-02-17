// Arithmetic operations

#include <stdio.h>

int main()
{
	int a, b;

	printf("Enter num1, num2\n");
	scanf("%d%d", &a, &b);

	printf("Sum %d\n", a + b);
	printf("Difference %d\n", a - b);
	printf("Product %d\n", a * b);
	printf("Quotient %f\n", (double)a / b);

	return 0;
}
