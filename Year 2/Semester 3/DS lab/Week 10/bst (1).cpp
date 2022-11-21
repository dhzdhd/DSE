#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *create(int item)
{
    Node *node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}
/*Inorder traversal of the tree formed*/
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);         // traverse left subtree
    cout << root->data << "   "; // traverse root node
    inorder(root->right);        // traverse right subtree
}
Node *findMinimum(Node *cur) /*To find the inorder successor*/
{
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}
Node *insertion(Node *root, int item) /*Insert a node*/
{
    if (root == NULL)
        return create(item); /*return new node if tree is empty*/
    if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);
    return root;
}
void searchForDel(Node *cur, int item, Node *parent)
{
    if (cur == NULL)
    {
        cout << "Given element not found \n";
        return;
    }
    while (cur != NULL && cur->data != item)
    {
        parent = cur;
        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void search(Node *cur, int item)
{
    Node *parent = NULL;
    if (cur == NULL)
    {
        cout << "Given element not found \n";
        return;
    }
    while (cur != NULL && cur->data != item)
    {
        parent = cur;
        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    cout << "Parent of given child \n";
    if (parent != NULL)
        cout << parent->data << endl;
    else
        cout << "No parent \n";

    cout << "The children of the given element are : \n";
    if (cur->left != NULL)
        cout << cur->left->data << endl;
    else
        cout << "No left child \n";

    if (cur->right != NULL)
        cout << cur->right->data << endl;
    else
        cout << "No right child \n";
}
void deletion(Node *root, int item) /*function to delete a node*/
{
    Node *parent = NULL;
    Node *cur = root;
    searchForDel(cur, item, parent); /*find the node to be deleted*/
    if (cur == NULL)
        return;
    if (cur->left == NULL && cur->right == NULL) /*When node has no children*/
    {
        if (cur != root)
        {
            if (parent->left == cur)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;
        delete (cur);
    }
    else if (cur->left && cur->right)
    {
        Node *succ = findMinimum(cur->right);
        int val = succ->data;
        deletion(root, succ->data);
        cur->data = val;
    }
    else
    {
        Node *child = (cur->left) ? cur->left : cur->right;
        if (cur != root)
        {
            if (cur == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
        delete (cur);
    }
}
int main()
{
    Node *root = NULL;
    Node *cur = NULL;
    Node *parent = NULL;
    int choice, data;
    cout << "1)insert into the bst \n";
    cout << "2)delete an element \n";
    cout << "3)Search \n";
    cout << "4)Inorder display \n";
    cout << "5)Exit \n";
    do
    {
        cout << "Enter your choice \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element \n";
            cin >> data;
            root = insertion(root, data);
            break;
        case 2:
            cout << "Enter the element to delete \n";
            cin >> data;
            deletion(root, data);
            break;
        case 3:
            cout << "Enter the element to search \n";
            cin >> data;
            search(root, data);
            break;
        case 4:
            inorder(root);
            cout << endl;
            break;
        case 5:
            break;
        default:
            cout << "Enter a valid choice\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
