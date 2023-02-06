#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int t = a > b ? b : a;
	
	while (true) {
		if (a % t == 0 && b % t == 0) {
			return t;
		} else {
			t--;
		}
	}
}

int main() {
	int a, b;
	
	cout << "Enter two numbers\n";
	cin >> a;
	cin >> b;
	
	cout << "GCD is " << gcd(a, b);
	
	return 0;
}

