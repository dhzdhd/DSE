// Merge sort

#include <iostream>
using namespace std;

void swap(int arr[100], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void merge(int arr[100], int l, int m, int r)
{
	int nl = m - l + 1;
	int nr = r - m;
	int larr[100], rarr[100];

	for (int i = 0; i < nl; i++)
	{
		larr[i] = arr[l + i];
	}
	for (int j = 0; j < nr; j++)
	{
		rarr[j] = arr[m + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < nl && j < nr)
	{
		if (larr[i] <= rarr[j])
		{
			arr[k] = larr[i];
			i++;
		}
		else
		{
			arr[k] = rarr[j];
			j++;
		}
		k++;
	}
	while (i < nl)
	{
		arr[k] = larr[i];
		i++;
		k++;
	}
	while (j < nr)
	{
		arr[k] = rarr[j];
		j++;
		k++;
	}
}

void mergesort(int arr[100], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int arr[100];
	int n;

	cout << "Enter the size of the array\n";
	cin >> n;

	cout << "Enter the elements\n";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	mergesort(arr, 0, n - 1);

	cout << "Sorted array\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
