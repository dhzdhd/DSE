#include <iostream>
using namespace std;

void insert_(char str[50], char sub[50], int index)
{
	char buffer[50];

	int count = 0;
	for (int i = index; str[i] != '\0'; i++)
	{
		buffer[count] = str[i];
		count++;
	}
	buffer[count] = '\0';

	int count_ = 0;
	for (int i = 0; sub[i] != '\0'; i++)
	{
		str[index + i] = sub[i];
		count_++;
	}

	int count__ = 0;
	for (int i = index + count_; buffer[count__] != '\0'; i++)
	{
		str[i] = buffer[count__];
		count__++;
	}

	for (int i = 0; i < str[i] != '\0'; i++)
	{
		cout << str[i];
	}
}

int main()
{
	char str[50];
	char sub_str[50];
	int index;

	cout << "Enter the first string\n";
	gets(str);
	cout << "Enter the sub string\n";
	gets(sub_str);
	cout << "Enter index to enter sub string\n";
	cin >> index;

	insert_(str, sub_str, index);

	return 0;
}
