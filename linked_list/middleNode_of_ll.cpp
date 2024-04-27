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

//Naive solution- this requires two traversals of linked list
int midNode(Node* head){
    if(head==NULL){return -1;}
    if(head->next==NULL){return head->data;}
    int len=lenOfLinkedList(head);
    cout<<len<<endl;
    if(len==2){
        return head->next->data;
    }
    int count=0;
    while(count<len/2){
        head=head->next;
        count++;
    }
    return head->data;
}

//Efficient solution- this requires one traversal of linked list
int midNode2(Node* head){
    if(head==NULL){return -1;}
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        //cout<<slow->data<<" "<<fast->data<<endl;
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
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
    cout<<midNode2(head);
    return 0;
}