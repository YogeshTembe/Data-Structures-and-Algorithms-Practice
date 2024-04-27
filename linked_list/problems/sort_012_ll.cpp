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

//Our solution
//Time complexity=o(n), auxiliary space=o(1)
Node* segregate(Node *head) {
        
    // Add code here
    int c0=0;
    int c1=0;
    int c2=0;
    Node *curr=head;
    while(curr){
        if(curr->data==0){c0++;}
        else if(curr->data==1){c1++;}
        else{c2++;}
        curr=curr->next;
    }
    Node *curr0=head;
    while(c0-- && curr0){
        curr0->data=0;
        curr0=curr0->next;
    }
    while(c1-- && curr0){
        curr0->data=1;
        curr0=curr0->next;
    }
    while(c2-- && curr0){
        curr0->data=2;
        curr0=curr0->next;
    }
    return head;   
}


//Editorial solution
//Time complexity=o(n), Auxiliary space=o(n)
Node* segregate2(Node *head) {
    if (!head || !(head->next))
        return head;
    Node *zeroD=new Node(0);
    Node *oneD=new Node(0);
    Node *twoD=new Node(0);

    Node *zero=zeroD;
    Node *one=oneD;
    Node *two=twoD;
    Node *curr=head;
    while(curr){
        if(curr->data==0){
            zero->next=curr;
            zero=zero->next;
        }
        else if(curr->data==1){
            one->next=curr;
            one=one->next;
        }
        else if(curr->data==2){
            two->next=curr;
            two=two->next;
        }
        curr=curr->next;
    }
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
    head=zeroD->next;
    //deleting dummy nodes.
    delete zeroD; 
    delete oneD; 
    delete twoD; 
    return head;
}

int main(){
    Node *head=new Node(1);
    Node *temp1=new Node(0);
    Node *temp2=new Node(2);
    Node *temp3=new Node(0);
    //Node *temp4=new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    head=segregate2(head);
    printList(head);
    return 0;
}