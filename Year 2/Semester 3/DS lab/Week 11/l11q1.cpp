#include <iostream>
using namespace std;
void linearSearch(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			cout << "Element found through linear search \n";
			cout << "index :" << i << endl;
			return;
		}
	}
	cout << "Element not found through linear search \n";
	return;
}
void sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void binarySearch(int arr[], int l, int h, int x)
{

	sort(arr, h);

	while (l != h)
	{
		int mid = (l + h) / 2;
		if (x == arr[mid])
		{
			cout << "Element found using binary search \n";
			cout << "index :" << mid << endl;
			return;
		}
		else if (x > arr[mid])
		{
			l = mid + 1;
		}
		else
		{
			h = mid - 1;
		}
	}
	cout << "Element not found using binary search \n";
	return;
}

int main()
{
	int arr[50];
	int n;
	cout << "Enter the size of array :\n";
	cin >> n;
	cout << "Enter the elements of the array :\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "1)linear search \n";
	cout << "2)Binary search \n";
	cout << "3)Exit \n";
	int choice = 0;
	int x;
	do
	{
		cout << "Enter your choice \n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter element to search \n";
			cin >> x;
			linearSearch(arr, n, x);
			break;
		case 2:
			cout << "Enter element to search \n";
			cin >> x;
			binarySearch(arr, 0, n, x);
			break;
		case 3:
			break;

		default:
			cout << "Enter a valid choice \n";
			break;
		}
	} while (choice != 3);

	return 0;
}
