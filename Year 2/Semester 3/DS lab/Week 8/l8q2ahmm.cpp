#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void insertBeginning(Node *head, int element) {
	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = head->next;
	
	head->data++;
	head->next = newNode; 
	
//	cout << head->next << endl;
}

void insertEnd(Node *head, int element) {
	Node *ptr = new Node;
	ptr = head;
	
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	
	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = NULL;
	
	ptr->next = newNode;
	
	head->data++;
}

void insertBefore(Node *head, int element, int positionElement) {
	Node *ptr = new Node;
	ptr = head;
	
	while (ptr->next != NULL && ptr->data == positionElement) {
		ptr = ptr->next;
	}
	
	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = ptr->next;
	
	ptr->next = newNode;

	head->data++;
}

void insertAfter(Node *head, int element, int positionElement) {
	Node *ptr = new Node;
	ptr = head;
	
	while (ptr->next != NULL && ptr->data < element) {
		ptr = ptr->next;
	}
	
	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = ptr->next;
	
	head->data++;
}

void delete_(Node *head, int element) {
	Node *ptr = new Node;
	ptr = head;
	
	while (ptr->next != NULL && ptr->next->data != element) {
		ptr = ptr->next;
	}
	
	Node *temp = ptr->next->next;
	delete ptr->next;
	ptr->next = temp;
	
	head->data--;
}

void print(Node *head) {
	Node *ptr = new Node;
	ptr = head;
	
//	cout << ptr << endl;
//	cout << ptr->next << endl;
	cout << "List is \n";	
	while (ptr->next != NULL) {
		
		cout << ptr->next->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main() {
	int choice = 0;
	
	Node *head = new Node;
	head->data = 0;
	head->next = NULL;
}

