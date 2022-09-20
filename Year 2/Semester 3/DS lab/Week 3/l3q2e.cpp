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

void delete_(char str[50], char sub[50])
{
	char new_str[50];
	int j = 0, k = 0, n = 0, flag = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		k = i;

		while (str[i] == sub[j])
		{
			i++, j++;
			if (j == get_len(sub))
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			i = k;
		else
			flag = 0;

		new_str[n++] = str[i];
	}

	new_str[n] = '\0';

	cout << new_str;
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

	delete_(str, sub_str);

	return 0;
}
