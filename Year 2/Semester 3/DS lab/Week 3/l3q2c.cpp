#include <iostream>
using namespace std;

int get_len(char str[50])
{
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return count;
}

int compare_(char str1[50], char str2[50])
{
	int len1 = get_len(str1);
	int len2 = get_len(str2);

	int length = len1 >= len2 ? len1 : len2;

	for (int i = 0; i < length; i++)
	{
		if (str1[i] != str2[i])
		{
			return -1;
		}
	}

	return 0;
}

int main()
{
	char str[50];
	char other_str[50];

	cout << "Enter the first string\n";
	gets(str);
	cout << "Enter the second string\n";
	gets(other_str);

	if (compare_(str, other_str) != 0)
	{
		cout << "Strings are not equal";
	}
	else
	{
		cout << "Strings are equal";
	}

	return 0;
}
