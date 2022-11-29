#include <iostream>
using namespace std;
class Employee
{
	int regno;
	char name[20];
	int marks;
	float basic;
	float da;
	float it;
	float net_sal;
	float gross_sal;

public:
	void read_data()
	{
		cout << "\nEnter Employee no:\n";
		cin >> regno;
		cout << "Enter the Employee name:\n";
		cin >> name;
		cout << "Enter basic:\n";
		cin >> basic;

		da = (12 / 100.) * basic;
	}
	void calc_gross_salary()
	{
		gross_sal = basic + da;
	}
	void calc_net_salary()
	{
		da = (12 / 100.) * basic;
		it = (18 / 100.) * gross_sal;
		net_sal = (basic + da) - it;
	}

	void display_data()
	{
		calc_gross_salary();
		calc_net_salary();
		calc_gross_salary();
		cout << "The Net salary is " << net_sal << " and the gross salary is " << gross_sal;
	}
};
int main()
{
	int n;
	cout << "Enter the number of employees:\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Employee employee;
		employee.read_data();
		employee.display_data();
	}
	return 0;
}
