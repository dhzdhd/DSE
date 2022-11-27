#include <iostream>
using namespace std;

bool linearSearch(int arr[], int length, int element)
{
    for (int i = 0; i < length; i++)
    {
        return arr[i] == element;
    }
}

void sort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}

bool binarySearch(int arr[], int length, int element)
{
    sort(arr, length);
}

int main()
{
    int arr[] = {1, 2, 3, 3, 4, 7, 23, 2, 5, 63, 2, 3, 5, 5};

    cout << linearSearch(arr, 14, 3) << endl;
}
