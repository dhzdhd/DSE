#include <iostream>
using namespace std;

char stack[100];
int top = -1;
int size_ = 100;

void push(char x)
{
    if (top >= size_ - 1)
        cout << "Stack overflow";
    else
        stack[++top] = x;
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
    char x;
    cout << "Enter the expression: \n";
    gets(exp);
    cout << "Postfix expression: ";

    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] != ' ')
        {
            if (isAlpha(exp[i]))
                cout << exp[i];
            else if (isDigit(exp[i]))
            {
                while (isDigit(exp[i]))
                    cout << exp[i++];
                cout << " ";
                i--;
            }
            else if (exp[i] == '(')
                push(exp[i]);
            else if (exp[i] == ')')
            {
                while ((x = pop()) != '(')
                    cout << x;
            }
            else
            {
                while (precedence(stack[top]) >= precedence(exp[i]))
                    cout << pop();
                push(exp[i]);
            }
        }
        i++;
    }

    while (top != -1)
    {
        cout << pop();
    }
    return 0;
}
