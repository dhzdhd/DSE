// Delete min element from heap

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void deleteMin(int arr[], int& n) {
    if (n == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }

    arr[0] = arr[n-1];
    n--;

    heapify(arr, n, 0);
}

int main() {
    int arr[100];
    int n;

    cout << "Enter the number of elements \n";
    cin >> n;
    cout << "Enter elements\n";

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    deleteMin(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
