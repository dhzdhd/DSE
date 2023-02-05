#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

void preOrder(Node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void inOrder(Node *temp)
{
    if (temp != NULL)
    {
        inOrder(temp->left);
        cout << " " << temp->data;
        inOrder(temp->right);
    }
}

void postOrder(Node *temp)
{
    if (temp != NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        cout << " " << temp->data;
    }
}

Node *create()
{
    int data;
    Node *p;

    cout << "Enter data , -1 if the Node has no child \n";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    p = new Node;
    p->data = data;

    cout << "Enter the left child of : " << data << endl;
    p->left = create();

    cout << "Enter the right child of : " << data << endl;
    p->right = create();

    return p;
}

bool ifNodeExists(Node *temp, int key)
{
    if (temp == NULL)
        return false;
    if (temp->data == key)
        return true;
    bool res1 = ifNodeExists(temp->left, key);
    if (res1)
        return true;
    bool res2 = ifNodeExists(temp->right, key);
    return res2;
}

Node *insertion(Node *root, int item) /*Insert a Node*/
{
    if (root == NULL)
    {
        root = new Node;
        root->data = item;
        root->left = root->right = NULL;
    }
    else if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);
    return root;
}

int main()
{
    Node *bintree;
    Node *bst = NULL;
    int key, choice, tr;
    cout << "Creating the binary tree \n";
    bintree = create();
    cout << "1)Enter key \n";
    cout << "2)inorder\n";
    cout << "3)preorder \n";
    cout << "4)postOrder \n";
    cout << "5)Exit \n";
    do
    {
        cout << "Enter choice :\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a key\n";
            cin >> key;
            if (ifNodeExists(bintree, key))
            {
                cout << "Element present \n";
            }
            else
            {
                bst = insertion(bst, key);
            }
            break;
        case 2:
            cout << "Binary tree:\n";
            inOrder(bintree);
            cout << "\nBST\n";
            inOrder(bst);
            break;
        case 3:
            cout << "Binary tree:\n";
            preOrder(bintree);
            cout << "BST\n";
            preOrder(bst);
            cout << endl;
            break;
        case 4:
            cout << "Binary tree:\n";
            postOrder(bintree);
            cout << "BST\n";
            postOrder(bst);
            break;
        case 5:
            break;
        default:
            cout << "Enter a valid number \n";
        }

    } while (choice != 5);
    return 0;
}
