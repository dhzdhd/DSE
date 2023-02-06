#include <iostream>
using namespace std;

void intersection(int arr1[100], int arr2[100], int c1, int c2) {
	int c = c1 < c2 ? c1 : c2;
	int gcd = 1;
	
	int j = 0; int i = 0;
	while (i < c1 && j < c2) {
		if (arr1[i] == arr2[j]) {
			gcd = gcd * arr1[i];
			i++; j++;
		} else {
			j++;
		}
	}
	
	cout << "GCD " << gcd << endl;
} 

void gcd(int a, int b) {	
	int arr1[100], arr2[100];
	int div = 2;
	int count1 = 0;
	
	while (a != 0 && div <= a) {
		if (a % div == 0) {
			arr1[count1] = div;
			count1++;
			a = a / div;
		} else {
			div++;
		}
	}
	
	div = 2; 
	int count2 = 0;
	while (b != 0 && div <= b) {
		if (b % div == 0) {
			arr2[count2] = div;
			count2++;
			b = b / div;
		} else {
			div++;
		}
	}
	intersection(arr1, arr2, count1, count2);
}

int main() { 
	int a, b;
	
	cout << "Enter two numbers\n";
	cin >> a;
	cin >> b;
	
	if (a > b) gcd(a, b);
    else gcd(b, a);
		
	return 0;
}
