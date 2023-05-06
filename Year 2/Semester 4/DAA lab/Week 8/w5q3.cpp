// Diameter of a binary tree

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

int height(Node *node) {
	if (node == NULL) {
		return 0;
	}
	return max(height(node->left), height(node->right)) + 1;
}

int diameter(Node* tree)
{
    if (tree == NULL)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}

int main() {
	Node *root;
	root = insert();

	cout << "Diameter is\n";
	cout << diameter(root);

	return 0;
}
