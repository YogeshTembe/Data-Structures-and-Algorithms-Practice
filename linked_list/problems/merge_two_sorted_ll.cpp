#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
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

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL){return head2;}
    if(head2==NULL){return head1;}
    Node *p1=head1;
    Node *p2=head2;

    Node *newhead;
    Node *tail;
    if(p1->data<p2->data){
        newhead=p1;
        tail=p1;
        p1=p1->next;
    }else{
        newhead=p2;
        tail=p2;
        p2=p2->next;
    }
    while(p1 && p2){
        if(p1->data<p2->data){
            tail->next=p1;
            p1=p1->next;
            tail=tail->next;
        }else{
            tail->next=p2;
            p2=p2->next;
            tail=tail->next;
        }
    }
    if(p1){
        tail->next=p1;
    }
    if(p2){
        tail->next=p2;
    }
    return newhead;
} 

int main(){
    Node* head=new Node(5);
    Node* temp1=new Node(10);
    Node* temp2=new Node(15);
    Node* temp3=new Node(40);
    //Node* temp4=new Node(50);
   // Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;

    Node *head2=new Node(2);
    Node *temp21=new Node(3);
    Node *temp22=new Node(20);
    Node *temp23=new Node(30);
    head2->next=temp21;
    temp21->next=temp22;
    temp22->next=temp23;
    //temp3->next=temp4;
    //temp4->next=temp5;
    printList(head);
    printList(head2);
    Node *res=sortedMerge(head,head2);
    printList(res);
    return 0;
}