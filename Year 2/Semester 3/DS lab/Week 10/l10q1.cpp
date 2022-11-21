#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

void inOrderTraversal(Node *node)
{
	if (node != NULL)
	{
		inOrderTraversal(node->left);
		cout << node->data << " ";
		inOrderTraversal(node->right);
	}
}

void preOrderTraversal(Node *node)
{
	if (node != NULL)
	{
		cout << node->data << " ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}

void postOrderTraversal(Node *node)
{
	if (node != NULL)
	{
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout << node->data << " ";
	}
}

void insert(Node *head, int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	int arr[100];

	head->data++;

	if (head->left == NULL)
	{
		head->left = temp;
	}
	else if (head->right == NULL)
	{
		head->right = temp;
	}
	else
	{
		int index = head->data;
		int parent = index / 2 - 1;
	}
}

void countLeafNumber(Node *head)
{
	cout << 2 * head->data - 1 << "\n";
}

int main()
{
	Node *head = new Node;
	head->data = 0;
	head->left = NULL;
	head->right = NULL;

	int choice = 0;
	cout << "1) Insert element into binary tree\n";
	cout << "2) Inorder traversal\n";
	cout << "3) Postorder traversal\n";
	cout << "4) Preorder traversal\n";
	cout << "5) Count leaf nodes\n";
	cout << "6) Exit\n";

	while (true)
	{
		cout << "Enter choice\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int data;
			cout << "Enter data\n";
			cin >> data;

			insert(head, data);
			break;
		}
		case 2:
		{
			inOrderTraversal(head);
			cout << endl;
			break;
		}
		case 3:
		{
			postOrderTraversal(head);
			cout << endl;
			break;
		}
		case 4:
		{
			preOrderTraversal(head);
			cout << endl;
			break;
		}
		case 5:
		{
			countLeafNumber(head);
			break;
		}
		default:
		{
			exit(0);
			break;
		}
		}
	}

	return 0;
}
