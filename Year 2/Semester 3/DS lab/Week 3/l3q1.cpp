#include <iostream>
using namespace std;

struct PolynomialRepr
{
    int coeff, exp;
};

int read(PolynomialRepr p[])
{
    int n;
    cout << "\nEnter the number of terms in polynomial:\n";
    cin >> n;

    cout << "\nEnter the coefficient and exponent of the polynomial\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].coeff >> p[i].exp;
    }
    return n;
}

int add(PolynomialRepr p1[], PolynomialRepr p2[], PolynomialRepr p3[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (p1[i].exp > p2[j].exp)
        {
            p3[k] = p1[i];
            i++;
            k++;
        }
        else if (p2[j].exp > p1[i].exp)
        {
            p3[k] = p2[j];
            j++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff + p1[i].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
            i++;
        }
    }
    if (i < n1)
    {
        while (i < n1)
        {
            p3[k] = p1[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j < n2)
        {
            p3[k] = p2[j];
            j++;
            k++;
        }
    }
    return k;
}

void print(PolynomialRepr p[], int n)
{
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (p[i].coeff == 0)
        {
            continue;
        }
        else if (p[i].exp == 0)
        {
            cout << p[i].coeff;
        }
        else
        {
            cout << p[i].coeff << " " << p[i].exp << "\n";
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (p[i].coeff == 0)
        {
            continue;
        }
        else if (p[i].exp == 0)
        {
            cout << p[i].coeff;
        }
        else
        {
            cout << p[i].coeff << "x^" << p[i].exp << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n1, n2, n3;
    PolynomialRepr p1[100], p2[100], p3[100];

    cout << "Enter first polynomial:\n";
    n1 = read(p1);
    cout << "Enter second polynomial:\n";
    n2 = read(p2);

    cout << "First polynomial is\n";
    print(p1, n1);

    cout << "Second polynomial is\n";
    print(p2, n2);

    n3 = add(p1, p2, p3, n1, n2);

    cout << "Sum of the polynomial is :\n";
    print(p3, n3);

    return 0;
}
