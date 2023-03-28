#include <iostream>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	int data;
};

void preorder(Node *node) {
	if (node != NULL) {
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(Node *node) {
	if (node != NULL) {
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
}

void postorder(Node *node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		cout << node->data << " ";
	}
}

Node *create(int item)
{
    Node *node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, int item)
{
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->left = insert(root->left, item);
    else
        root->right = insert(root->right, item);
    return root;
}

int main() {
	int data;
	
	Node *root = NULL;
	
	while (true) {
		cout << "Enter element, -1 to break\n";
		cin >> data;
		
		if (data == -1) break;
		
		root = insert(root, data);
	}
	
	cout << "\nPreorder\n";
	preorder(root);
	cout << "\nInorder\n";
	inorder(root);
	cout << "\nPostorder\n";
	postorder(root);
	
	return 0;
}
