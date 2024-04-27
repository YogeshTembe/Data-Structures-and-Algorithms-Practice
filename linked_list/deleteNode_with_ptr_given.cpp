#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d):data(d),next(NULL){}
};

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

void deleteNodeWithPtr(Node* tobedeleted){
    while(tobedeleted->next && tobedeleted->next->next){
        tobedeleted->data=tobedeleted->next->data;
        tobedeleted=tobedeleted->next;
    }
    if(tobedeleted->next!=NULL){
        tobedeleted->data=tobedeleted->next->data;
    }
    tobedeleted->next=NULL;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    Node* temp3=new Node(40);
    Node* temp4=new Node(50);
    Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    cout<<temp5->next<<endl;
    printList(head);
    deleteNodeWithPtr(temp5);
    printList(head);
    return 0;
}