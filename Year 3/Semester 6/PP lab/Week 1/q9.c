// Matrix pattern

#include <stdio.h>

int main()
{
	int m[100][100];
	char c[100][100];
	char s[1000];
	int m1, m2;

	printf("Enter mat dims\n");
	scanf("%d%d", &m1, &m2);

	printf("Enter matrix\n");
	int i, j, k;
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			getchar();
			scanf("%c ", &c[i][j]);
			scanf("%d", &m[i][j]);
		}
	}

	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			for (k = 0; k < m[i][j]; k++)
			{
				printf("%c", c[i][j]);
			}
		}
	}

	return 0;
}
