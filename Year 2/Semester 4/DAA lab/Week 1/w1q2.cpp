#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* create(int item) {
    Node* node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

void preorder(Node *root) {
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

Node* insertion(Node* root, int item) {
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);
    return root;
}

void search(Node* cur, int data) {
    Node* temp = cur;
    while (temp!=NULL) {
        if(temp->data==data) {
            cout<<"Key found\n";
            return;
        }
        else if(temp->data>data) {
            temp=temp->left;

        }
        else if(temp->data<data) {
            temp=temp->right;
        }
    }
    cout<<"Element not found \n";
    insertion(cur, data);
}

int main() {
    Node* root = NULL;
    int choice,data;
    cout<<"1)Insert \n";
    cout<<"2)Search \n";
    cout<<"3)Inorder display \n";
    cout<<"4)Preorder display \n";
    cout<<"5)Postorder display \n";
    cout<<"6)Exit \n";
    do{
        cout<<"Enter your choice \n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the element \n";
                cin>>data;
                root = insertion(root,data);
                break;
            case 2:
                cout<<"Enter the element to search \n";
                cin>>data;
                search(root,data);
                break;
            case 3:
                inorder(root);
                cout<<endl;
                break;
            case 4:
                preorder(root);
                cout<<endl;
                break;
            case 5:
                postorder(root);
                cout<<endl;
                break;
            case 6:
                break;
            default:
                cout<<"Enter a valid choice\n";
                break;
        }
    } while(choice != 6);

    return 0;
}
