#include <iostream>
#include <locale>
#include <string.h>
#include <math.h>
#include <string>
#include <ctype.h>
using namespace std;
int stack[100];
int top = -1;
int n = 100;

void push(int x)
{
	if (top >= n - 1)
		cout << "stack overflow";
	else
	{
		stack[++top] = x;
	}
}

int pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}
int isoperator(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
		return 1;
	else
		return 0;
}
int main()
{
	char exp[100], str[100];
	double result;
	int k = 0;
	char op[50];
	cout << "enter postfix expression: ";
	gets(exp);
	int i = strlen(exp);
	for (; i >= 0; i--)
	{
		if (isdigit(exp[i]))
		{
			k = 0;
			while (isdigit(exp[i]))
				op[k++] = exp[i--];
			i += 1;

			cout << op << endl;

			op[k] = '\0';
			int j = 0;

			for (int z = strlen(op) - 1; z >= 0; z--)
			{
				str[j++] = op[z];
			}

			// convert
			string newstr = str;
			int num = stoi(str);
			push(num);
		}

		else if (isoperator(exp[i]))
		{
			int op1 = pop();
			int op2 = pop();
			switch (exp[i])
			{
			case '+':
				result = op1 + op2;
				push(result);
				break;
			case '-':
				result = op1 - op2;
				push(result);
				break;
			case '*':
				result = op1 * op2;
				push(result);
				break;
			case '/':
				result = op1 / op2;
				push(result);
				break;
			case '^':
				result = pow(op1, op2);
				push(result);
				break;
			}
		}
	}
	cout << pop();
	return 0;
}
