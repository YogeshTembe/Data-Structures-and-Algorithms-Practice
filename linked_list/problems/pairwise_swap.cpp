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

struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *newhead=head->next;
    Node *p1=head;
    Node *p2=head->next;
    Node *prevnode=NULL;
    while(p1 && p2){
        cout<<p1->data<<" "<<p2->data<<endl;
        Node *nextnode=p2->next;
        p2->next=p1;
        p1->next=nextnode;
        if(prevnode){
            prevnode->next=p2;
        }
        prevnode=p1;
        p1=p1->next;
        if(p1){
        p2=p1->next;
        }
    }
    //cout<<p1->data<<" "<<p2->data<<endl;
    return newhead;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    Node* temp3=new Node(40);
    Node* temp4=new Node(50);
   // Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    //temp4->next=temp5;
    printList(head);
    head=pairwise_swap(head);
    printList(head);
    return 0;
}