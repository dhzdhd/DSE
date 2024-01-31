// 1's complement matrix
// FIXME: bin_to_int includes trailing zeroes => inaccuracy

#include <stdio.h>
#include <stdlib.h>

int binary_to_int(char *str)
{
	int val = 0;
	int power = 1;
	int len = strlen(str);

	for (int i = len - 1; i >= 0; i--)
	{
		val += (str[i] - '0') * power;
		power *= 2;
	}

	return val;
}

int main()
{
	int m[100][100], res[100][100], ress[100][100];
	int m1, m2;

	printf("Enter mat dims\n");
	scanf("%d%d", &m1, &m2);

	printf("Enter matrix\n");
	int i, j, k;
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			scanf("%d", &m[i][j]);
		}
	}

	printf("B\n");
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			if (i == 0 || i == m1 - 1 || j == 0 || j == m2 - 1)
			{
				printf("%d ", m[i][j]);
			}
			else
			{
				char *buf = calloc(sizeof(int) * 8 + 1, sizeof(int));
				itoa(m[i][j], buf, 2);

				for (int z = 0; z < sizeof(int) * 8; z++)
				{
					buf[z] = (buf[z] == '0') ? '1' : '0';
				};

				printf("%d ", binary_to_int(buf));
			}
		}
		printf("\n");
	}

	printf("C\n");
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			if (i == 0 || i == m1 - 1 || j == 0 || j == m2 - 1)
			{
				printf("%d ", m[i][j]);
			}
			else
			{
				char *buf = calloc(sizeof(int) * 2 + 1, sizeof(int));
				itoa(m[i][j], buf, 2);

				for (int z = 0; z < sizeof(int) * 8; z++)
				{
					buf[z] = (buf[z] == '0') ? '1' : '0';
				};

				printf("%s ", buf);
			}
		}
		printf("\n");
	}

	return 0;
}
