#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){}
};

Node* removeDuplicates(Node* head){
    if(head==NULL){return NULL;}
    Node* temp=head;
    while(head){
        Node* curr=head->next;
        while(curr && curr->data==head->data){
            curr=curr->next;
        }
        head->next=curr;
        head=head->next;
    }
    return temp;
}

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(20);
    Node* temp3=new Node(30);
    Node* temp4=new Node(30);
    Node* temp5=new Node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    printList(head);
    head=removeDuplicates(head);
    printList(head);
    return 0;
}