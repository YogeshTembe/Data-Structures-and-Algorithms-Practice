#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int d):val(d),next(NULL){}
};

void printList(Node* head){
    Node* temp=head;
    cout<<head->val<<" ";
    head=head->next;
    while(temp!=head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* insertAtBegin(Node* head,int newval){
    if(head==NULL){
        Node* newnode=new Node(newval);
        newnode->next=newnode;
        return newnode;
    }
    int temp=head->val;
    Node* tempnext=head->next;
    head->val=newval;
    Node* newnode=new Node(temp);
    newnode->next=tempnext;
    head->next=newnode;
    return head;
}

Node* insertAtEnd(Node* head,int newval){
    Node* newnode=new Node(newval);
    if(head==NULL){
        newnode->next=newnode;
        return newnode;
    }
    newnode->val=head->val;
    head->val=newval;
    Node* tempnext=head->next;
    head->next=newnode;
    newnode->next=tempnext;
    return newnode;
}

Node* deleteHead(Node* head){
    if(head==NULL){return NULL;}
    if(head->next==head){
        delete(head);//deallocate memory
        return NULL;
    }
    Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    delete(head);
    return temp->next;
}

Node* deleteKthNode(Node* head,int k){
    if(head==NULL){return NULL;}
    if(head->next==head){
        delete(head);
        return NULL;
    }
    if(k==1){
        return deleteHead(head);
    }
    int count=1;
    Node* curr=head;
    while(count<k-1){
        cout<<curr->val<<" "<<count<<endl; 
        curr=curr->next;
        count++;
    }
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete(temp);
    return head;
}

int main(){
    Node* head=new Node(23);
    Node* temp=new Node(34);
    Node* temp2=new Node(67);
    head->next=temp;
    temp->next=temp2;
    temp2->next=head;
    printList(head);
    head=insertAtBegin(head,33);
    printList(head);
    head=insertAtBegin(head,10);
    printList(head);
    head=insertAtEnd(head,88);
    printList(head);
    head=insertAtEnd(head,17);
    printList(head);
    head=deleteHead(head);
    printList(head);
    head=deleteKthNode(head,4);
    printList(head);
    return 0;
}