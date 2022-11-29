#include <iostream>
using namespace std;

class flight
{
	int m_flight_no;
	string m_des;
	float m_dis;
	float m_fuel;

public:
	void set_fuel()
	{
		m_fuel = 13.2;
	}
	void calculate_fuel()
	{
		if (m_dis <= 1000)
		{
			m_fuel = 500;
		}

		else if (m_dis > 1000 && m_dis <= 2000)
		{
			m_fuel = 1100;
		}
		else if (m_dis > 2000)
		{
			m_fuel = 2200;
		}
	}

	void display_info()
	{
		cout << "The flight number is " << m_flight_no << "\nTHe destination is:" << m_des << "\nThe distance is " << m_dis << "\nThe fuel required is" << m_fuel;
	}
	void information_entry(int flight_no, string des, float dis)
	{
		m_flight_no = flight_no;
		m_des = des;
		m_dis = dis;

		calculate_fuel();
		display_info();
	}
};

int main()
{
	int flight_no;
	string des;
	float dis;

	flight flight;
	flight.set_fuel();

	cout << "Enter Flight no:\n ";
	cin >> flight_no;

	cout << "Enter destination:\n";
	cin >> des;

	cout << "Enter distance:\n";
	cin >> dis;
	flight.information_entry(flight_no, des, dis);
	return 0;
}
