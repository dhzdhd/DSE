// Insertion sort

#include <iostream>
using namespace std;

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

	int v;
	for (int i = 0; i < n; i++)
	{
		v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
	}

	cout << "Sorted array\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
