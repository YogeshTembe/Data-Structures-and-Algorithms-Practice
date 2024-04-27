#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* prev;
    Node* next;
    Node(int d):val(d),prev(NULL),next(NULL){}
};

Node* insertAtHead(Node* head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        newnode->prev=newnode;
        newnode->next=newnode;
        return newnode;
    }
    newnode->prev=head;
    newnode->next=head->next;
    head->next=newnode;
    int tempval=head->val;
    head->val=newnode->val;
    newnode->val=tempval;
    return head;
}

Node* insertAtEnd(Node* head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
    }
    newnode->next=head->prev->next;
    head->prev->next=newnode;
    newnode->prev=head->prev;
    head->prev=newnode; 
    return head;  
}

void printList(Node* head){
    Node* temp=head;
    cout<<head->val<<" ";
    head=head->next;
    while(head!=temp){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(33);
    Node* temp2=new Node(76);
    head->next=temp1;
    head->prev=temp2;
    temp1->next=temp2;
    temp1->prev=head;
    temp2->next=head;
    temp2->prev=temp1;
    printList(head);
    head=insertAtHead(head,29);
    printList(head);
    head=insertAtEnd(head,45);
    printList(head);
    return 0;
}