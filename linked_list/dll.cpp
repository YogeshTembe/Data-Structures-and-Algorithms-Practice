#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d):data(d),next(NULL),prev(NULL){}
};

//insert node at the begining of dll
Node* insertAtBegin(Node* head,int val){
    Node* newnode=new Node(val);
    if(!head){return newnode;}
    newnode->next=head;
    head->prev=newnode;
    return newnode;
}

Node* deleteHead(Node* head){
    if(head==NULL){return NULL;}
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    Node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
    return head;
}

Node* deleteLastNode(Node* head){
    if(head==NULL){return NULL;}
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    return head;
}

Node* insertAtEnd(Node* head,int val){
    if(head==NULL){
        auto newnode=new Node(val);
        return newnode;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=new Node(val);
    temp->next->prev=head;
    return head;
}

//print dll
void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
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
    head=insertAtBegin(head,84);
    printList(head);
    head=deleteHead(head);
    printList(head);
    head=deleteLastNode(head);
    printList(head);
    head=insertAtEnd(head,45);
    head=insertAtEnd(head,34);
    printList(head);
    return 0;
}