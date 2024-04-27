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

void pairwiseSwap(Node* head){
    while(head && head->next){
        int temp=head->data;
        head->data=head->next->data;
        head->next->data=temp;
        head=head->next->next;
    }
}

Node* pairwiseSwap2(Node* head){
    bool isFirstSwap=true;
    Node* newhead=NULL;
    Node* curr=head;
    Node* nextnode=NULL;
    Node* prevnode=NULL;
    while(curr && curr->next){
        nextnode=curr->next;
        curr->next=curr->next->next;
        nextnode->next=curr;
        if(isFirstSwap){
            newhead=nextnode;
            //cout<<temp->data<<endl;
            isFirstSwap=false;
        }
        if(prevnode){
            prevnode->next=nextnode;
        }
        prevnode=curr;
        curr=curr->next;
    }
    return newhead;
}

int main(){
    Node* head=new Node(1);
    Node* temp1=new Node(2);
    Node* temp2=new Node(3);
    Node* temp3=new Node(4);
    Node* temp4=new Node(5);
    Node* temp5=new Node(6);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    printList(head);
    head=pairwiseSwap2(head);
    printList(head);
    return 0;
}