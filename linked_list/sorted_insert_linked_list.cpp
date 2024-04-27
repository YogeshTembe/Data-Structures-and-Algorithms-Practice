#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int d):val(d),next(NULL){}
};

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->val<<" ";
        node=node->next;
    }
    cout<<endl;
}

Node* insertInSortedWay(Node* head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        return newnode;
    }
    if(head->val >= data){
        newnode->next=head;
        return newnode;
    }
    Node* prevnode=head;
    Node* temp=head;
    temp=temp->next;
    while(temp){
        if(temp->val>data){
            break;
        }
        prevnode=temp;
        temp=temp->next;
    }
    
    Node *tempnext=prevnode->next;
    prevnode->next=newnode;
    newnode->next=tempnext;
    return head;
}

int main(){
    Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    temp->next=temp2;
    printList(head);
    head=insertInSortedWay(head,2);
    printList(head);
    return 0;
}