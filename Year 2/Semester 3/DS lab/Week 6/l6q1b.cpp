#include <iostream>
#include <string.h>
using namespace std;

char stack[100];
int top = -1;
int size_ = 100;

void push(char x)
{
	if (top >= size_ - 1)
		cout << "Stack overflow";
	else
	{
		stack[++top] = x;
	}
}

char pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

int precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	if (x == '^')
		return 3;
	return 0;
}

bool isAlpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int main()
{
	char exp[100];
	char revexp[100];
	char result[100];
	char x;

	cout << "Enter the expression : \n";
	gets(exp);
	cout << "Prefix expression: ";

	int k = 0;
	for (int i = strlen(exp) - 1; i >= 0; i--)
	{
		revexp[k++] = exp[i];
	}
	revexp[k] = '\0';
	k = 0;

	for (int i = 0; revexp[i] != '\0'; i++)
	{
		// if (revexp[i] != '\0')
		// {
		if (isAlpha(revexp[i]))
			result[k++] = revexp[i];
		else if (isDigit(revexp[i]))
		{
			result[k++] = ' ';
			while (isDigit(revexp[i]))
				result[k++] = revexp[i++];
			result[k++] = ' ';
			i -= 1;
		}
		else if (revexp[i] == ')')
		{
			push(revexp[i]);
		}
		else if (revexp[i] == '(')
		{
			while ((x = pop()) != ')')
			{
				result[k++] = x;
			}
		}
		else
		{
			while (precedence(stack[top]) >= precedence(revexp[i]))
				result[k++] = pop();
			push(revexp[i]);
			// }
		}
	}
	while (top != -1)
	{
		result[k++] = pop();
	}
	result[k] = '\0';
	for (int j = strlen(result) - 1; j >= 0; j--)
	{
		cout << result[j];
	}
	return 0;
}
