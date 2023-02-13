#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter size of array\n";
	cin >> n;
	
	int *arr = new int[n];
	
	cout << "Enter elements\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	
	cout << "Sorted array\n";
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
