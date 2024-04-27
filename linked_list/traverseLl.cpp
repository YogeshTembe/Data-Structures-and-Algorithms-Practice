#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){}
};

//Print all nodes of linked list using recursion
void printNode(Node* node){
    if(!node){cout<<endl;return;}
    cout<<node->data<<" ";
    printNode(node->next);
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

//insert node at begining of linked list
Node* insertAtBegin(Node* head,int newdata){
    Node* newnode=new Node(newdata);
    newnode->next=head;
    return newnode;
}

//Insert node at the end of linked list
Node* insertAtEnd(Node* head,int newdata){
    Node* newnode=new Node(newdata);
    if(!head){return newnode;}
    Node* curr=head;
    while(curr->next){
        curr=curr->next;
    }
    curr->next=newnode;
    return head;
}

//delete first node of linked list
Node* deleteFirst(Node* head){
    if(!head){return NULL;}
    return head->next;
}

//delete last node of linked list
Node* deleteLast(Node* head){
    if(!head){return NULL;}
    if(head->next==NULL){return NULL;}
    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    return head;
}

//Insert at given position in linked in
Node* insertAt(Node* head,int pos,int data){
    Node* newnode=new Node(data);
    if(!head){
        return newnode;
    }
    if(pos==1){
        newnode->next=head;
        return newnode;
    }
    int currpos=1;
    Node* temp=head;
    while(temp && currpos<pos){
        temp=temp->next;
        currpos++;
    }
    if(currpos==pos-1){
        cout<<"here"<<endl;
        Node* temp2=temp->next;
        temp->next=newnode;
        newnode->next=temp2;
        return head;
    }else{
        return head;
    }
}

//search in linked list and return pos
int search(Node* head,int data){
    int pos=0;
    while(head){
        if(head->data==data){return pos;}
        head=head->next;
        pos++;
    }
    return -1;
}

int main(){
    Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    temp->next=temp2;
    printNode(head);
    //insert node at begining
    head=insertAtBegin(head,32);
    printNode(head);
    head=insertAtEnd(head,90);
    printNode(head);
    head=deleteFirst(head);
    printNode(head);
    head=deleteLast(head);
    printNode(head);
    head=insertAt(head,2,68);
    printNode(head);
    cout<<search(head,20);
    return 0;
}