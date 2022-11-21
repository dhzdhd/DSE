#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* insert(){
	int data;
	node* p;
	cout<<"Enter data , -1 if the node has no child \n";
	cin>>data;
	if(data == -1){
		return NULL;
	}
	p = new node;
	p->data = data;
	cout<<"Enter the left child of : "<<data<<endl;
	p->left = insert();
	cout<<"Enter the right child of : "<<data<<endl;
	p->right = insert();
	return p;	
}
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        if (maxDepth(node->left) > maxDepth(node->right))
            return (maxDepth(node->left) + 1);
        else
            return (maxDepth(node->right) + 1);
    }
}
void findParent(node* node,int val, int parent){
    if (node == NULL)
        return;
    if (node->data == val) {
        cout << parent;
    }
    else {
        findParent(node->left, val, node->data);
        findParent(node->right, val, node->data);
    }
}
int printAncestorsOfNode(struct node* root, int num) {
  if (root == NULL)
     return 0;
  
  if (root->data == num)
     return 1;
  
  if (printAncestorsOfNode(root->left, num) ||
       printAncestorsOfNode(root->right, num) ) {
      cout<<root->data<<" ";
      return 1;
  } else {
      return 0;
  }
}
void InOrder( node *temp) {
  if (temp != NULL) {
    InOrder(temp->left);
    cout << " " << temp->data;
    InOrder(temp->right);
  }
}
int main(){
	node* root =NULL;
	int data;
	int choice;
	int parent;
	cout<<"1) create binary tree \n";
	cout<<"2) parent of an element \n";
	cout<<"3) depth of the tree \n";
	cout<<"4) ancestors of the given node \n";
	cout<<"5) Inorder display \n";
	cout<<"6) Exit \n";
	do{
		cout<<"Enter your choice \n";
		cin>>choice;
		
		switch(choice){
			case 1:
				root = insert();
				break;
			case 2:
				cout<<"Enter a element to find the parent : \n";
				cin>>data;
				cout<<"The parent of the given element is : \n";
				findParent(root,data,parent);
				cout<<endl;
				break;
			case 3:
				cout<<"The depth of the tree is : \n";
				cout<<maxDepth(root)<<endl;
				break;
			case 4:
				cout<<"Enter the element whose ancestors are to be found \n";
				cin>>data;
				cout<<"The ancestors of the given element are : \n";
				printAncestorsOfNode(root,data);
				break;
			case 5:
				InOrder(root);
				cout<<endl;
				break;;
			case 6:
				break;
		}
		
	}while(choice != 6);
	
	return 0;
	
}
