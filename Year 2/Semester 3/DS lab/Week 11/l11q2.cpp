#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int arr[],int n){
	for(int i =0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void bubbleSort(int arr[],int n){
	for(int i= 0;i<n;i++){
		for(int j =0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	cout<<"After bubble sort :\n";
	printArray(arr,n);
}
void selectionSort(int arr[],int n){
	int min;
	for(int i =0;i<n;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min])
				min = j;
				
			if(min != i)
			swap(&arr[min],&arr[i]);
		}
		
	} 
	cout<<"After selection sort \n";
	printArray(arr,n);
	
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
    	cout<<"After insertion sort \n";
		printArray(arr,n);
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i= (low- 1);
  	for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[],int low,int high){
	  if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
	int arr[100];
	int n,choice;
	
	cout<<"Enter the size of the array \n";
	cin>>n;
	cout<<"Enter the elements of the array \n";
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}
	
	
	cout<<"1) Selection Sort \n";
	cout<<"2) Insertion Sort \n";
	cout<<"3) Quick Sort \n";
	cout<<"4) Bubble Sort \n";
	cout<<"5) Exit \n";
	
	do{
		cout<<"Enter your choice : \n";
		cin>>choice;
		
		switch(choice){
			case 1:
				selectionSort(arr,n);
				break;
			case 2:
				insertionSort(arr,n);
				break;
			case 3:
				quickSort(arr,0,n-1);
				cout<<"After quick sort : \n";
				printArray(arr,n);
				break;
			case 4:
				bubbleSort(arr,n);
				break;
				
		}
		
	}while(choice != 4);
return 0;
}
