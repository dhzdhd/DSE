// AVL

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* newnode(int data){
    Node* node = new Node;
    node->data = data;

    node->left = node->right = NULL;
    node->height =1;

    return node;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        return newnode(key);
    }

    if (key < node->data) {
        node->left = insert(node->left, key);
    }
    else if (key > node->data) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main() {
    Node *root = NULL;
    int n,m;
    cout<<"Enter the number of element in the avl tree \n";
    cin>>n;
    cout<<"Enter elements \n";

    for(int i = 0;i<n;i++ ){
        cin>>m;
        root = insert(root,m);
    }

    cout << "Inorder traversal of the constructed AVL tree is: ";
    inorder(root);

    return 0;
}
