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

int intersectionPoint(Node* h1,Node* h2){
    Node* temp=new Node(0);
    while(h1){
        Node* nextNode=h1->next;
        h1->next=temp;
        h1=nextNode;
    }
    while(h2){
        if(h2->next==temp){
            return h2->data;
        }
        h2=h2->next;
    }
    return -1;
}

int main(){
    Node* head=new Node(5);
    Node* temp1=new Node(8);
    Node* temp2=new Node(7);
    Node* temp3=new Node(10);
    Node* temp4=new Node(12);
    Node* temp5=new Node(15);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;

    Node* head2=new Node(9);
    head2->next=temp3;

    cout<<intersectionPoint(head,head2);
    return 0;
}