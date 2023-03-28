#include <iostream>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	int data;
};

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

int max(int a, int b) {
	return a >= b ? a : b;
}

int height(Node *node) {
	if (node == NULL) {
		return -1;
	}
	return max(height(node->left), height(node->right)) + 1;
}

int main() {
	int n;
	
	Node *root;
	
	root = insert();
	
	cout << "Height is\n";
	cout << height(root);
	
	return 0;
}

