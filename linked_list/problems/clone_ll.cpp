#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node* arb;
    Node(int d):data(d),next(NULL),arb(NULL){}
};

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

Node *copyList(Node *head)
{
    //Write your code here
    Node *curr=head;
    while(curr){
        Node *newnode=new Node(curr->data);
        Node *nextnode=curr->next;
        curr->next=newnode;
        newnode->next=nextnode;
        curr=nextnode;
    }
    Node *curr2=head;
    while(curr2){
        curr2->next->arb=(curr2->arb!=NULL)?curr2->arb->next:NULL;
        curr2=curr2->next->next;
    }
    Node *newhead=head->next;
    curr=head;
    curr2=head->next;
    while(curr){
        curr->next=curr->next->next;
        curr2->next=curr2->next ? curr2->next->next:NULL;
        curr=curr->next;
        curr2=curr2->next;
    }
    //curr->next=NULL;
    return newhead;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(5);
    Node* temp2=new Node(20);
    Node* temp3=new Node(15);
    Node* temp4=new Node(20);
    head->next=temp1;
    head->arb=temp2;
    temp1->next=temp2;
    temp1->arb=temp3;
    temp2->next=temp3;
    temp2->arb=head;
    temp3->next=temp4;
    temp3->arb=temp4;
    temp4->arb=temp3;
    printList(head);
    
    Node* newhead=copyList(head);
    // printList(newhead);
    cout<<"---------"<<endl;
    newhead->next->data=55;
    printList(newhead);
    printList(head);
    return 0;
}