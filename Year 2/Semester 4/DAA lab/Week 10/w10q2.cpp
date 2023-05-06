// Horspool's algorithm

#include <iostream>
#include <cstdio>
using namespace std;

void shiftTable(int table[500], char pattern[100], int m) {
    for (int i = 0; i < m - 1; i++) {
        table[pattern[i]] = m - 1 - i;
    }
}

int horspool(int table[500], char pattern[100], char text[100], int m, int n) {
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i = i + table[text[i]];
        }
    }
    return -1;
}

int main() {
    char text[100], pattern[100];
    int n, m;

    cout << "Enter text & pattern size\n";
    cin >> n >> m;

    int table[500] = {m};

    cout << "Enter text and pattern\n";
    gets(text);
    gets(pattern);

    cout << text;

    shiftTable(table, pattern, m);
    int index = horspool(table, pattern, text, m, n);

    cout << "Matched index is " << index << endl;

    return 0;
}
