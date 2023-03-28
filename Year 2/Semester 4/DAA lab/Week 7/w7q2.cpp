#include <iostream>
using namespace std;

int countt = 0;

struct Node {
	Node *left;
	Node *right;
	int data;
};

void inorder(Node *node) {
	if (node != NULL) {
		inorder(node->left);
		countt++;
		inorder(node->right);
	}
}

Node *insert() {
	int data;
	Node *p;
	
	cout << "Enter data, -1 for NULL\n";
	cin >> data;
	
	if (data == -1) {
		return NULL;
	}
	
	p = new Node;
	p->data = data;
	
	cout << "Left child\n";
	p->left = insert();
	
	cout << "Right child\n";
	p->right = insert();
	return p;
}

int main() {
	int n;
	
	Node *root;
	
	root = insert();
	
	inorder(root);
	cout << "Number of nodes is " << countt;
	
	return 0;
}

