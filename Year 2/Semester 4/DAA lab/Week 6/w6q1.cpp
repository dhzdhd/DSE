// Quick sort

#include <iostream>
using namespace std;

void swap(int arr[100], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[100], int l, int r, int pivot)
{
	int i = l;
	int j = l;

	while (i <= r)
	{
		if (arr[i] > pivot)
		{
			i++;
		}
		else
		{
			swap(arr, i, j);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quicksort(int arr[100], int l, int r)
{
	if (l < r)
	{
		int pivot = arr[r];
		int s = partition(arr, l, r, pivot);
		quicksort(arr, l, s - 1);
		quicksort(arr, s + 1, r);
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

	quicksort(arr, 0, n - 1);

	cout << "Sorted array\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
