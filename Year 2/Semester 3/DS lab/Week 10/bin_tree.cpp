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
int leafNode(node* root){
	
	if(root ==NULL){
		return 0;
	}
	else if(root->left==NULL && root->right ==NULL){
		return 1;
	}
	else{
		return leafNode(root->left) + leafNode(root->right);
	}
	
}

void PreOrder( node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    PreOrder(temp->left);
    PreOrder(temp->right);
  }
}

// Traverse Inorder
void InOrder( node *temp) {
  if (temp != NULL) {
    InOrder(temp->left);
    cout << " " << temp->data;
    InOrder(temp->right);
  }
}

// Traverse Postorder
void PostOrder( node *temp) {
  if (temp != NULL) {
    PostOrder(temp->left);
    PostOrder(temp->right);
    cout << " " << temp->data;
  }
}


int main(){
	node* root =NULL;
	int choice;
	cout<<"1) insert into the binary tree \n";
	cout<<"2) preorder display \n";
	cout<<"3) inorder display \n";
	cout<<"4) post order display \n";
	cout<<"5) no of leaf nodes \n";
	cout<<"6) Exit \n";
	do{
		cout<<"Enter your choice \n";
		cin>>choice;
		
		switch(choice){
			case 1:
				root = insert();
				break;
			case 2:
				PreOrder(root);
				cout<<endl;
				break;
			case 3:
				InOrder(root);
				cout<<endl;
				break;
			case 4:
				PostOrder(root);
				cout<<endl;
				break;
			case 5:
				cout<<"The no of leaf nodes are :\n";
				cout<<leafNode(root)<<endl;
				break;
			case 6:
				break;
		}
		
	}while(choice != 6);
	
	
	
	
	return 0;
}
