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

Node* rotate(Node* head, int k)
{
    // Your code here
    Node *curr=head;
    int count=0;
    while(curr && count<k-1){
        curr=curr->next;
        count++;
    }
    if(curr->next==NULL){//here k==n
        return head;
    }
    cout<<curr->data<<endl;
    Node *newhead=curr->next;
    curr->next=NULL;
    Node *curr2=newhead;
    while(curr2->next){
        curr2=curr2->next;
    }
    curr2->next=head;
    return newhead;
}

int main(){
    Node *head=new Node(2);
    Node *temp1=new Node(4);
    Node *temp2=new Node(7);
    Node *temp3=new Node(8);
    Node *temp4=new Node(9);
    //Node *temp5=new Node(2);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    //temp4->next=temp5;
    printList(head);
    head=rotate(head,5);
    printList(head);
    return 0;
}