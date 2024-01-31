// Diagonal matrix manipulation

#include <stdio.h>

int main()
{
	int m[100][100], res[100][100];
	int max[100], min[100];
	int m1 = 5, m2 = 5;

	printf("Enter matrix\n");
	int i, j;
	for (i = 0; i < m1; i++)
	{
		int maxx = 0;
		int minn = 9999999;
		for (j = 0; j < m2; j++)
		{
			scanf("%d", &m[i][j]);
			if (m[i][j] > maxx)
			{
				maxx = m[i][j];
			}
			if (m[i][j] < minn)
			{
				minn = m[i][j];
			}
		}
		max[i] = maxx;
		min[i] = minn;
	}

	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			if (i == j)
			{
				res[i][j] = 0;
			}
			else if (i < j)
			{
				res[i][j] = min[i];
			}
			else
			{
				res[i][j] = max[i];
			}
		}
	}

	printf("Result\n");
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}
