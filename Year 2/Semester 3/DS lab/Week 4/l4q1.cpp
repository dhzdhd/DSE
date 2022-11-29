#include <iostream>
using namespace std;

int factorial(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num * factorial(num - 1);
}

int main()
{
	int num;

	cout << "Enter a number\n";
	cin >> num;

	cout << "The factorial is: " << factorial(num);

	return 0;
}
