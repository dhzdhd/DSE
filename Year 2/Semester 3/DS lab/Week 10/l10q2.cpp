#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *insert()
{
    int data;
    node *p;

    cout << "Enter data , -1 if the node has no child \n";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    p = new node;
    p->data = data;

    cout << "Enter the left child of : " << data << endl;
    p->left = insert();

    cout << "Enter the right child of : " << data << endl;
    p->right = insert();

    return p;
}

int leafNode(node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return leafNode(root->left) + leafNode(root->right);
    }
}

// Search Inorder
void bfs(node *temp, int element)
{
    node *queue[100];

    int count = 0;
    int front = 0;
    int rear = 1;

    queue[0] = temp;
    while (temp->data != element)
    {
        if (temp->left != NULL)
        {
            queue[rear] = temp->left;
            rear++;
        }
        if (temp->right != NULL)
        {
            queue[rear] = temp->right;
            rear++;
        }
        count++;

        temp = queue[front];
        front++;
    }
}

void printParent(node *temp, int element)
{
}

void printDepth(node *temp)
{
}

void printAncestors(node *temp, int element)
{
}

int main()
{
    node *root = NULL;
    int choice;
    cout << "1) insert into the binary tree \n";
    cout << "2) print parent of element \n";
    cout << "3) print depth of tree \n";
    cout << "4) print ancestors of a node \n";
    cout << "5) Exit \n";
    do
    {
        cout << "Enter your choice \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            root = insert();
            break;
        case 2:
            InOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "The no of leaf nodes are :\n";
            cout << leafNode(root) << endl;
            break;
        case 6:
            break;
        }

    } while (choice != 6);

    return 0;
}
