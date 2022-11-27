#include <iostream>
using namespace std;

struct Node
{
	Node *next;
	Node *previous;
	int data;
};

void insertRear(Node *head, int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;

	Node *cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = temp;
	temp->previous = cur;
}

void deleteRear(Node *head)
{
	Node *cur = head;

	if (cur->next == NULL)
	{
		cout << "Underflow\n";
		return;
	}

	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}

	Node *temp = cur->next;
	cur->next = NULL;
	delete temp;
}

void insertAfter(Node *head, int data, int element)
{
	Node *cur = head;
	Node *temp = new Node;
	temp->data = data;

	while (cur != NULL && cur->data != element)
	{
		cur = cur->next;
	}

	if (cur == NULL)
	{
		cout << "Not found!\n";
		return;
	}

	temp->next = cur->next;
	temp->previous = cur;
	cur->next->previous = temp;
	cur->next = temp;
}

void insertBefore(Node *head, int data, int element)
{
	Node *cur = head;
	Node *temp = new Node;
	temp->data = data;

	while (cur->next != NULL && cur->next->data != element)
	{
		cur = cur->next;
	}

	if (cur->next == NULL)
	{
		cout << "Not found!\n";
		return;
	}

	temp->next = cur->next;
	temp->previous = cur;
	cur->next->previous = temp;
	cur->next = temp;
}

void print(Node *head)
{
	Node *cur = head->next;

	if (cur == NULL)
	{
		cout << "Empty\n";
		return;
	}

	while (cur->next != NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << cur->data << endl;
}

int main()
{
	Node *head = new Node;
	head->next = NULL;
	head->previous = NULL;

	insertRear(head, 10);
	insertRear(head, 20);
	insertAfter(head, 50, 10);
	insertBefore(head, 59, 20);
	print(head);
	deleteRear(head);
	print(head);

	return 0;
}
