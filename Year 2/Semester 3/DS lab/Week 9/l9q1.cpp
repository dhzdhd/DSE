#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node *previous;
};

void insertRear(Node *head, int data) {
	Node *temp = head;
	head->data++;
	
	while (temp->next != head->previous) {
		temp = temp->next;
	}
	
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = temp;

	temp->next = newNode;
	head->previous = newNode;
}
 
void deleteRear(Node *head) {
	if (head->next == NULL) {
		cout << "List empty!\n";
		return;
	}

	Node *temp = head->previous;
	temp->previous->next = NULL;
	
	head->data--;
	
	temp = temp->previous;
	delete head->previous;
	head->previous = temp;	
}

void display(Node *head) {
	Node *temp = head;
	
	while (temp->next != head->previous) {
		temp = temp->next;
		cout << temp->data << " ";
	}
	cout << endl;
}

int main() {
	Node *head = new Node;
	head->next = NULL;
	head->previous = NULL;
	head->data = 0;
	
	cout << "1) Insert element at rear\n";
	cout << "2) Delete element at rear\n";
	cout << "3) Insert element at given position\n";
	cout << "4) Delete element at given position\n";
	cout << "5) Insert element after another\n";
	cout << "6) Delete element after another\n";
	cout << "7) Print list\n";
	cout << "8) Exit\n";
	
	int n = 0;
	while (true) {
		cout << "Enter choice\n";
		cin >> n;
		
		switch (n) {
			case 1: {
				int n;
				cout << "Enter element\n";
				cin >> n;
				
				insertRear(head, n);
				
				break;
			}
			case 2: {
				deleteRear(head);
				break;
			}
			case 7: {
				display(head);
				break;
			}
			case 8: {
				exit(0);
				break;
			}
			default: {
				break;
			}
		}
	}
	
	return 0;
}
