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
	
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
 		}
	}
	
	cout << "Sorted array\n";
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
