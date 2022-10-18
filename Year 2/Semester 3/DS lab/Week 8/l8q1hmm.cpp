#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void insertBeginning(Node *head, int element)
{
	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = head->next;

	head->data++;
	head->next = newNode;

	//	cout << head->next << endl;
}

void insertEnd(Node *head, int element)
{
	Node *ptr = new Node;
	ptr = head;

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = NULL;

	ptr->next = newNode;

	head->data++;
}

void insertBefore(Node *head, int data, int element)
{
	Node *ptr = head;

	while (ptr->next->data != data)
	{
		if (ptr->next == NULL)
		{
			cout << "Not found!\n";
			return;
		}
		ptr = ptr->next;
	}

	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = ptr->next;

	ptr->next = newNode;

	head->data++;
}

void insertAfter(Node *head, int data, int element)
{
	Node *ptr = new Node;
	ptr = head;

	while (ptr
			   ->data != data)
	{
		if (ptr->next == NULL)
		{
			cout << "Not found!\n";
			return;
		}
		ptr = ptr->next;
	}

	Node *newNode = new Node;
	newNode->data = element;
	newNode->next = ptr->next;

	ptr->next = newNode;

	head->data++;
}

void delete_(Node *head, int element)
{
	Node *ptr = new Node;
	ptr = head;

	while (ptr->next != NULL && ptr->next->data != element)
	{
		ptr = ptr->next;
	}

	Node *temp = ptr->next->next;
	delete ptr->next;
	ptr->next = temp;

	head->data--;
}

void print(Node *head)
{
	Node *ptr = new Node;
	ptr = head;

	//	cout << ptr << endl;
	//	cout << ptr->next << endl;
	cout << "List is \n";
	while (ptr->next != NULL)
	{

		cout << ptr->next->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main()
{
	int choice = 0;

	Node *head = new Node;
	head->data = 0;
	head->next = NULL;

	cout << "1) Insert element at beginning\n";
	cout << "2) Insert element at the end\n";
	cout << "3) Insert element before another element\n";
	cout << "4) Insert element after another element\n";
	cout << "5) Delete element\n";
	cout << "6) Print list\n";
	cout << "7) Exit\n";

	while (true)
	{
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int x;
			cout << "Enter element to insert: ";
			cin >> x;

			insertBeginning(head, x);
			break;
		}
		case 2:
		{
			int x;
			cout << "Enter element to insert: ";
			cin >> x;

			insertEnd(head, x);
			break;
		}
		case 3:
		{
			int x;
			cout << "Enter element to insert: ";
			cin >> x;

			int y;
			cout << "Enter element for the input to be inserted before: ";
			cin >> y;

			insertBefore(head, x, y);
			break;
		}
		case 4:
		{
			int x;
			cout << "Enter element to insert: ";
			cin >> x;

			int y;
			cout << "Enter element for the input to be inserted after: ";
			cin >> y;

			insertAfter(head, x, y);
			break;
		}
		case 5:
		{
			int x;
			cout << "Enter element to delete: ";
			cin >> x;

			delete_(head, x);
			break;
		}
		case 6:
		{
			print(head);
			break;
		}
		case 7:
			exit(0);
		default:
			break;
		}
	}

	return 0;
}
