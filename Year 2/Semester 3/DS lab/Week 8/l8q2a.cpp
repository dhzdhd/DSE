// #include <iostream>
// using namespace std;
// struct Node {
//    int data;
//    struct Node *next;
// };
// struct Node* top = NULL;
// void push(int val) {
//    Node* newnode = new Node;
//    newnode->data = val;
//    newnode->next = top;
//    top = newnode;
// }
// void pop() {
//    if(top==NULL)
//    cout<<"Stack Underflow"<<endl;
//    else {
//       cout<<"The popped element is "<< top->data <<endl;
//       top = top->next;
//    }
// }
// void display() {
//    struct Node* ptr;
//    if(top==NULL)
//    cout<<"stack is empty";
//    else {
//       ptr = top;
//       cout<<"Stack elements from top to bottom are: ";
//       while (ptr != NULL) {
//          cout<< ptr->data <<" ";
//          ptr = ptr->next;
//       }
//    }
//    cout<<endl;
// }
// int main() {
//    int ch, val;
//    cout<<"1) Push in stack"<<endl;
//    cout<<"2) Pop from stack"<<endl;
//    cout<<"3) Display stack"<<endl;
//    cout<<"4) Exit"<<endl;
//    do {
//       cout<<"Enter choice: "<<endl;
//       cin>>ch;
//       switch(ch) {
//          case 1: {
//             cout<<"Enter value to be pushed:"<<endl;
//             cin>>val;
//             push(val);
//             break;
//          }
//          case 2: {
//             pop();
//             break;
//          }
//          case 3: {
//             display();
//             break;
//          }
//          case 4: {
//             cout<<"Exit"<<endl;
//             break;
//          }
//          default: {
//             cout<<"Invalid Choice"<<endl;
//          }
//       }
//    }while(ch!=4);
//    return 0;
// }

#include <iostream>
using namespace std;

struct Node
{
   Node *next;
   int data;
};

void push(Node *head, int data)
{
   Node *temp = new Node;
   temp->data = data;
   temp->next = head->next;

   head->next = temp;
}

void pop(Node *head)
{
   Node *cur = head;

   if (head->next == NULL)
   {
      cout << "Underflow \n";
      return;
   }

   Node *temp = cur->next;
   cur->next = temp->next;
   delete temp;
}

void print(Node *head)
{
   Node *cur = new Node;
   cur = head->next;

   if (head->next == NULL)
   {
      cout << "Empty \n";
      return;
   }

   while (cur->next != NULL)
   {
      cout << cur->data << " ";
      cur = cur->next;
   }
   cout << cur->data << " " << endl;
}

int main()
{
   Node *head = new Node;
   head->next = NULL;
   head->data = 0;

   push(head, 5);
   push(head, 6);
   push(head, 7);
   print(head);
   pop(head);
   pop(head);
   print(head);
   pop(head);
   print(head);

   return 0;
}
