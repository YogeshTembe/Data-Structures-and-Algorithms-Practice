#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){}
};

int lenOfLinkedList(Node* head){
    int len=0;
    while(head){
        head=head->next;
        len++;
    }
    return len;
}

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

//Naive solution- reuires two traversals of linked list
int nthNodeFromEnd(Node* head,int n){
    if(head==NULL){return -1;}
    int len=lenOfLinkedList(head);
    if(n>len){
        return -1;
    }
    int count=0;
    while(count<(len-n)){
        head=head->next;
        count++;
    }
    return head->data;
}

//Efficient solution- requires one traversal of linked list
int nthNodeFromEnd2(Node* head,int n){
    if(head==NULL){return -1;}
    Node* second=head;
    Node* first=head;
    int i=0;
    while(i<n && first){
        first=first->next;
        i++;
    }
    //cout<<i<<endl;
    if(i<n){return -1;}
    while(first){
        first=first->next;
        second=second->next;
    }
    return second->data;
}

int main(){
    Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    //Node* temp3=new Node(40);
    head->next=temp;
    temp->next=temp2;
    //temp2->next=temp3;
    printList(head);
    cout<<nthNodeFromEnd2(head,3);
    return 0;
}