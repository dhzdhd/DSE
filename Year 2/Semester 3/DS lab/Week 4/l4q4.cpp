#include <iostream>
#include <math.h>
using namespace std;

void toh(string src, string aux, string dest, int n)
{
	if (n == 1)
	{
		cout << "Move disc 1 from " << src << " to " << dest << endl;
		return;
	}

	toh(src, dest, aux, n - 1);
	cout << "Move disc " << n << " from " << src << " to " << dest << endl;

	toh(aux, src, dest, n - 1);
}

int main()
{
	int n;

	cout << "Enter total number of towers\n";
	cin >> n;

	cout << "Total number of moves is " << pow(2, n) - 1 << endl;

	toh("source", "auxiliary", "destination", n);
	return 0;
}
