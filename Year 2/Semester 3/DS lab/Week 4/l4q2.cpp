#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;
	}
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
