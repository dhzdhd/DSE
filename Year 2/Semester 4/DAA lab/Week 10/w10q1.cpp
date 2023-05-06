// Open hashing

#include <iostream>
using namespace std;

struct Node {
    Node *next;
    int data;
};

void display(Node *arr[100], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL) {
            Node *temp = arr[i];

            while (temp->next != NULL) {
                cout << temp->data << " > ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        } else {
            cout << "NULL\n";
        }
    }
}

void insert(int data, int h, Node *arr[100]) {
    Node *p = new Node;
    Node *temp;
    p->data = data;
    p->next = NULL;

    if (arr[h] == NULL) {
        arr[h] = p;
    } else {
        temp = arr[h];

        while (temp -> next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

int main() {
    int n, m;
    Node *arr[100] = { NULL };

    cout << "Enter size of hash table & number of elements\n";
    cin >> n >> m;

    cout << "Enter elements\n";
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;

        int h = data % n;
        insert(data, h, arr);
    }

    cout << "The hash table is\n";
    display(arr, n);

    return 0;
}
