// 1. Conversion of infix expression to postfix and prefix forms

#include <iostream>
using namespace std;

struct StackRepr
{
    char stack[100];
    int top;
    int size;
};

bool isFull(StackRepr *inst)
{
    return inst->top == inst->size;
}

bool isEmpty(StackRepr *inst)
{
    return inst->top == 0;
}

void push(StackRepr *inst, char element)
{
    if (isFull(inst))
    {
        cout << "Overflow, Stack is full!" << endl;
        return;
    }
    inst->stack[inst->top] = element;
    inst->top++;
}

char pop(StackRepr *inst)
{
    if (isEmpty(inst))
    {
        // cout << 'e';
        return 0;
    }
    return inst->stack[--inst->top];
}

bool isAlphaNum(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    else if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

void postfix(char str[100])
{
    StackRepr inst;
    inst.top = 0;
    inst.size = 100;
    char res[100];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {

        for (i; isAlphaNum(str[i]); i++)
        {
            res[count++] = str[i];
        }

        if (str[i] != ' ')
        {
            res[count++] = ' ';
            if (str[i] == '(')
            {
                push(&inst, str[i]);
            }
            else if (str[i] == ')')
            {
                while (inst.stack[inst.top - 1] != '(')
                {
                    res[count++] = pop(&inst);
                }
                pop(&inst);
            }
            else
            {
                while (!isEmpty(&inst) && precedence(str[i]) <= precedence(inst.stack[inst.top]))
                {
                    res[count] = pop(&inst);
                    count++;
                }
                push(&inst, str[i]);
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << res[i];
    }
}

int length(char s[100])
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char s[100])
{
    int len = length(s);
    int n = len / 2;
    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    s[len] = '\0';
}

void prefix(char str[100])
{
    char rev[100];
    int k = 0;
    for (int i = length(str) - 1; i >= 0; i--)
    {

        rev[k++] = str[i];
    }
    rev[k] = '\0';

    StackRepr inst;
    inst.top = 0;
    inst.size = 100;
    char res[100];

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {

        for (i; isAlphaNum(str[i]); i++)
        {
            res[count++] = str[i];
        }

        if (str[i] != ' ')
        {
            if (str[i] == ')')
            {
                push(&inst, str[i]);
            }
            else if (str[i] == '(')
            {
                while (inst.stack[inst.top - 1] != ')')
                {
                    res[count++] = pop(&inst);
                }
                pop(&inst);
            }
            else
            {
                while (!isEmpty(&inst) && precedence(str[i]) <= precedence(inst.stack[inst.top]))
                {
                    res[count] = pop(&inst);
                    count++;
                }
                push(&inst, str[i]);
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << res[i];
    }
}

int main()
{
    char str[100];
    cout << "Enter the expression" << endl;
    gets(str);

    postfix(str);
    // prefix(str);
};
