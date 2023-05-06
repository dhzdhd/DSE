#include <iostream>
using namespace std;

int main() {
	int n, arr[100], countArr[100];

	cout << "Enter size of array\n";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		countArr[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				countArr[i]++;
			} else {
				countArr[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[countArr[i]] << " ";
	}
	cout << endl;

	return 0;
}
