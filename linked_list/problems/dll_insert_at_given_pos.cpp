#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

void printList(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node *newnode=new Node(data);
   
   int count=0;
   Node *curr=head;
   while(count<pos){
       curr=curr->next;
       count++;
   }
   cout<<curr->data<<endl;
   Node *temp=curr->next;
   curr->next=newnode;
   newnode->prev=curr;
   newnode->next=temp;
   if(temp){
    temp->prev=newnode;
   }
}

int main(){
    Node *head=new Node(2);
    Node *temp1=new Node(4);
    Node *temp2=new Node(5);
    head->next=temp1;
    head->prev=NULL;
    temp1->next=temp2;
    temp1->prev=head;
    temp2->next=NULL;
    temp2->prev=temp1;
    printList(head);
    addNode(head,1,34);
    printList(head);
    return 0;
}