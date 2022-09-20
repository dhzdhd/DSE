#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else if (a == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main()
{
	int a, b;

	cout << "Enter two numbers\n";
	cin >> a >> b;

	cout << "The GCD of the two is " << gcd(a, b);

	return 0;
}
