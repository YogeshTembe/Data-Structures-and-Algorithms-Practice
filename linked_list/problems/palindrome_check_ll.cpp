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

bool isPalindrome(Node *head)
{
    //Your code here
    Node *slow=head;
    Node *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
    Node *newlist=slow;
    newlist=reverse(newlist);
    printList(newlist);
    while(newlist!=NULL){
        if(newlist->data!=head->data){
            return false;
        }
        newlist=newlist->next;
        head=head->next;
    }
    return true;
}

int main(){
    Node* head=new Node(1);
    Node* temp1=new Node(2);
    Node* temp2=new Node(2);
    Node* temp3=new Node(1);
    //Node* temp4=new Node(1);
    //Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    //temp3->next=temp4;
    printList(head);
    cout<<isPalindrome(head)<<endl;
    return 0;
}