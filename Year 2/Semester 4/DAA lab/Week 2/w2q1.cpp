#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;
	
	while (a != 0) {
		c = b % a;
		b = a;
		a = c;
	}
	
	return b;
} 

int main() {
	int a, b;
	
	cout << "Enter two numbers\n";
	cin >> a;
	cin >> b;
	
	cout << "GCD is " << gcd(a, b);
	
	return 0;
}

