#include <iostream>
using namespace std;

struct SparseRepr
{
	int i;
	int j;
	int val;
};

int main()
{
	int n;
	int matrix[50][50];
	int new_matrix[50][50];
	SparseRepr sparse[50];

	cout << "Enter order of matrix\n";
	cin >> n;

	cout << "Enter matrix elements\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "\nThe matrix is\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nThe sparse matrix is\n";

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] != 0)
			{
				sparse[count] = (SparseRepr){i, j, matrix[i][j]};
				count++;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << sparse[i].i << " " << sparse[i].j << " " << sparse[i].val;
		cout << "\n";
	}
	count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sparse[count].i == i && sparse[count].j == j)
			{
				new_matrix[i][j] = sparse[count].val;
				count++;
			}
			else
			{

				new_matrix[i][j] = 0;
			}
		}
	}

	cout << "\nThe Original Matrix is\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
