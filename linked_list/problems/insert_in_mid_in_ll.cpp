#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) {
    data = x;
    next = NULL;
}
};

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

Node* insertInMiddle(Node* head, int x)
{
	// Code here
    Node *newnode=new Node(x);
    if(head==NULL){return newnode;}
    if(head->next==NULL){
        head->next=newnode;
        return head;
    }
    Node *slow=head;
    Node *fast=head;
    while(fast && fast->next){
        fast=fast->next;
        if(fast->next){
        fast=fast->next;
        slow=slow->next;
        }
    }
    Node *temp=slow->next;
    
    slow->next=newnode;
    newnode->next=temp;
    return head;
}

int main(){
    Node *head=new Node(1);
    Node *temp1=new Node(2);
    Node *temp2=new Node(3);
    Node *temp3=new Node(4);
    //Node *temp4=new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    head=insertInMiddle(head,34);
    printList(head);
    return 0;
}