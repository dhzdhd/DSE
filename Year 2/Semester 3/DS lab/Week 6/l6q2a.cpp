#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int stack[100];
int top = -1;
int size_ = 100;

void push(int x)
{
	if (top >= size_ - 1)
		cout << "Stack overflow";
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
int isOperator(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
		return 1;
	else
		return 0;
}
bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}
int main()
{
	char exp[100], op[50];
	int k = 0;
	double result;
	cout << "enter postfix expression: ";
	gets(exp);
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (isDigit(exp[i]))
		{
			k = 0;
			while (isDigit(exp[i]))
				op[k++] = exp[i++];
			i -= 1;
			op[k] = '\0';
			string str = op;
			int num = stoi(str);
			push(num);
		}
		else if (isOperator(exp[i]))
		{
			int op1 = pop();
			int op2 = pop();
			switch (exp[i])
			{
			case '+':
				result = op2 + op1;
				push(result);
				break;
			case '-':
				result = op2 - op1;
				push(result);
				break;
			case '*':
				result = op2 * op1;
				push(result);
				break;
			case '/':
				result = op2 / op1;
				push(result);
				break;
			case '^':
				result = pow(op2, op1);
				push(result);
				break;
			}
		}
	}
	cout << pop();
	return 0;
}
