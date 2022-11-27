// #include <iostream>
// using namespace std;
// struct node
// {
//    int data;
//    struct node *next;
// };
// struct node *front = NULL;
// struct node *rear = NULL;
// struct node *temp;
// void Insert()
// {
//    int val;
//    cout << "Insert the element in queue : " << endl;
//    cin >> val;
//    if (rear == NULL)
//    {
//       node *temp = new node;
//       rear = temp;
//       rear->next = NULL;
//       rear->data = val;
//       front = rear;
//    }
//    else
//    {
//       node *newNode = new node;
//       temp = newNode;
//       rear->next = temp;
//       temp->data = val;
//       temp->next = NULL;
//       rear = temp;
//    }
// }
// void Delete()
// {
//    temp = front;
//    if (front == NULL)
//    {
//       cout << "Underflow" << endl;
//       return;
//    }
//    else if (temp->next != NULL)
//    {
//       temp = temp->next;
//       cout << "Element deleted from queue is : " << front->data << endl;
//       delete front;
//       front = temp;
//    }
//    else
//    {
//       cout << "Element deleted from queue is : " << front->data << endl;
//       delete front;
//       front = NULL;
//       rear = NULL;
//    }
// }
// void Display()
// {
//    temp = front;
//    if ((front == NULL) && (rear == NULL))
//    {
//       cout << "Queue is empty" << endl;
//       return;
//    }
//    cout << "Queue elements are: ";
//    while (temp != NULL)
//    {
//       cout << temp->data << " ";
//       temp = temp->next;
//    }
//    cout << endl;
// }
// int main()
// {
//    int ch;
//    cout << "1) Insert element to queue" << endl;
//    cout << "2) Delete element from queue" << endl;
//    cout << "3) Display all the elements of queue" << endl;
//    cout << "4) Exit" << endl;
//    do
//    {
//       cout << "Enter your choice : " << endl;
//       cin >> ch;
//       switch (ch)
//       {
//       case 1:
//          Insert();
//          break;
//       case 2:
//          Delete();
//          break;
//       case 3:
//          Display();
//          break;
//       case 4:
//          cout << "Exit" << endl;
//          break;
//       default:
//          cout << "Invalid choice" << endl;
//       }
//    } while (ch != 4);
//    return 0;
// }

#include <iostream>
using namespace std;

struct Node
{
   Node *next;
   int data;
};

void enqueue(Node *head, int data)
{
   Node *temp = new Node;
   temp->data = data;
   temp->next = NULL;

   Node *cur = head;
   while (cur->next != NULL)
   {
      cur = cur->next;
   }

   cur->next = temp;
}

void dequeue(Node *head)
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

   enqueue(head, 5);
   enqueue(head, 6);
   enqueue(head, 7);
   print(head);
   dequeue(head);
   print(head);
   dequeue(head);
   print(head);
   dequeue(head);
   print(head);

   return 0;
}
