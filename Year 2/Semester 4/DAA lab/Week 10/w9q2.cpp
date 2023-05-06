// Horspool's algorithm

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void shiftTable(int table[500], char pattern[100], int m) {
    for (int i = 0; i < 200; i++) {
        table[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        table[(int)pattern[i]] = m - 1 - i;
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
            i = i + table[(int)text[i]];
        }
    }
    return -1;
}

int main() {
    char text[100], pattern[100];
    int table[500];

    cout << "Enter text and pattern\n";
    cin >> text;
    cin >> pattern;

    int n = strlen(text);
    int m = strlen(pattern);

    shiftTable(table, pattern, m);
    int index = horspool(table, pattern, text, m, n);

    cout << "Matched index is " << index << endl;

    return 0;
}
