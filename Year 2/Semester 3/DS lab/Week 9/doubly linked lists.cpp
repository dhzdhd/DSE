#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *prev;
	Node *next;
};
void insertRear(Node *head, int data)
{
	Node *newNode = new Node;
	Node *last = head;
	newNode->data = data;
	newNode->next = NULL;

	if (head->next == NULL)
	{
		newNode->prev = NULL;
		head->next = newNode;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = newNode;
	newNode->prev = last;
}

void insertAfter(Node *head, int element, int data)
{
	Node *temp = head->next;

	while (temp->data != element)
	{
		if (temp->next == NULL)
		{
			cout << "The given element is not present in the list\n";
			return;
		}
		temp = temp->next;
	}
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next->prev = newNode;
}
void insertBefore(Node *head, int element, int data)
{
	Node *temp = head->next;
	while (temp->data != element)
	{
		temp = temp->next;
	}
	Node *newNode = new Node;
	newNode->data = data;
	newNode->prev = temp->prev;
	temp->prev = newNode;
	newNode->next = temp;
	newNode->prev->next = newNode;
}
void printList(Node *head)
{
	Node *temp = head->next;
	cout << "Traversing forward :\n";
	while (temp->next != NULL)
	{
		cout << " " << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
	cout << "Traversing Backward:\n";
	while (temp->prev != NULL)
	{
		cout << " " << temp->data << " ";
		temp = temp->prev;
	}
	cout << temp->data << endl;
}
void deleteRear(Node *head)
{
	Node *temp = head->next;
	if (head->next == NULL)
	{
		cout << "The list is empty \n";
		return;
	}
	if (temp->next == NULL)
	{
		head->next = NULL;
		delete temp;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;
}
void deleteAfter(Node *head, int element)
{
	Node *temp = head->next;
	if (head->next == NULL)
	{
		cout << "The list is empty \n";
		return;
	}
	while (temp->data != element)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "Element is not present in the list\n";
			return;
		}
		else
		{
			continue;
		}
	}
	temp = temp->next;
	if (temp == NULL)
	{
		cout << "Nothing to delete after the element\n";
		return;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
}
void deleteBefore(Node *head, int element)
{
	Node *temp = head->next;
	if (temp == NULL)
	{
		cout << "List is empty \n";
		return;
	}
	while (temp->next->data != element)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			cout << "The element is not in the list \n";
			return;
		}
		else
		{
			continue;
		}
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
}
int main()
{
	int choice, data, element;
	Node *head = new Node;
	head->next = NULL;
	cout << "1.Insert Rear \n";
	cout << "2.Delete Rear \n";
	cout << "3.Insert After \n";
	cout << "4.Delete After \n";
	cout << "5.Insert Before \n";
	cout << "6.Delete Before \n";
	cout << "7.Display list\n";
	cout << "8.Exit\n";
	while (true)
	{
		cout << "Enter your choice\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter data :\n";
			cin >> data;
			insertRear(head, data);
			break;
		case 2:
			deleteRear(head);
			cout << "deleted rear\n";
			break;
		case 3:
			cout << "Enter data:\n";
			cin >> data;
			cout << "Enter the element after which the data is to be inserted\n";
			cin >> element;
			insertAfter(head, element, data);
			break;
		case 4:
			cout << "Enter the element after which the data is to be deleted\n";
			cin >> element;
			deleteAfter(head, element);
			cout << "Element deleted\n";
			break;
		case 5:
			cout << "Enter data:\n";
			cin >> data;
			cout << "Enter the element before which the data is to be inserted.\n";
			cin >> element;
			insertBefore(head, element, data);
			break;
		case 6:
			cout << "Enter the element after which the data is to be deleted\n";
			cin >> element;
			deleteBefore(head, element);
			cout << "Element deleted\n";
			break;
		case 7:
			printList(head);
			break;
		default:
			exit(0);
			break;
		}
	}
}
