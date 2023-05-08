// Closed hashing

#include <iostream>
using namespace std;

int main() {
    int n, m, table[100] = {-1};

    cout << "Enter size of hash table & number of elements\n";
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        table[i] = -1;
    }

    cout << "Enter elements\n";
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;

        int counter = 0;
        int h = data % n;

        while (table[h] != -1) {
            counter++;
            h = (data + counter) % n;
        }

        table[h] = data;
    }

    cout << "The linear probed hash table is\n";
    for (int i = 0; i < n; i++) {
        cout << table[i] << " ";
    }
    cout << endl;

    return 0;
}
