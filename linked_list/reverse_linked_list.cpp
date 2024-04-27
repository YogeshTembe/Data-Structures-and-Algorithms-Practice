#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){}
};

Node* reverse(Node* head){
    Node* curr=head;
    Node* prevnode=NULL;
    Node* nextnode=NULL;
    while(curr!=NULL){
        //cout<<curr->data<<" ";
        nextnode=curr->next;
        curr->next=prevnode;
        prevnode=curr;
        curr=nextnode;
    }
    //cout<<endl;
    head=prevnode;
    return head;
}

//Recursive method-1
Node* reverse1(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    Node* rest_head=reverse1(head->next);
    Node* rest_tail=head->next;
    head->next=NULL;
    rest_tail->next=head;
    return rest_head;
}

//Recursive method-2
Node* reverse2(Node* head,Node* prevnode){
    if(head==NULL){
        return NULL;
    }
    //cout<<head->data<<endl;
    if(head->next==NULL){
        head->next=prevnode;
        return head;
    }
    Node *nextnode=head->next;
    head->next=prevnode;
    return reverse2(nextnode,head);
}

//Print all nodes of linked list using iteration
void printNode2(Node* head){
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
    Node* temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    printNode2(head);
    // head=reverse(head);
    // printNode2(head);
    // head=reverse1(head);
    // printNode2(head);
    head=reverse2(head,NULL);
    printNode2(head);
    return 0;
}