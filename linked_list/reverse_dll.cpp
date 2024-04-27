#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d):data(d),next(NULL),prev(NULL){}
};

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* nextnode=NULL;
    Node* prevnode=NULL;
    while(curr!=NULL){
        nextnode=curr->next;
        curr->next=curr->prev;
        curr->prev=nextnode;
        prevnode=curr;
        curr=nextnode;
    }
    head=prevnode;
    return head;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    printList(head);
    head=reverse(head);
    printList(head);
    return 0;
}