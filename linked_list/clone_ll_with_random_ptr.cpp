#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node* randomPtr;
    Node(int d):data(d),next(NULL),randomPtr(NULL){}
};

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

//Naive solution
//Time complexity=tita(n), Aux.space=tita(n)
Node* cloneLL(Node* head){
    //*(newhead)=*(head);
    unordered_map<Node*,Node*>mp;
    Node* curr=head;
    while(curr){
        mp[curr]=new Node(curr->data);
        curr=curr->next;
    }
    Node* curr2=head;
    while(curr2){
        mp[curr2]->next=mp[curr2->next];
        mp[curr2]->randomPtr=mp[curr2->randomPtr];
        curr2=curr2->next;
    }
    return mp[head];
}

Node* cloneLL2(Node* head){
    Node* curr=head;
    while(curr){
        Node* temp=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=temp;
        curr=curr->next->next;
    }
    Node* curr2=head;
    while(curr2){
        curr2->next->randomPtr=curr2->randomPtr->next;
        curr2=curr2->next->next;
    }
    //cout<<head->next->randomPtr->data<<endl;
    Node* newhead=head->next;
    Node* p1=head;
    Node* p2=newhead;
    while(p1 && p1->next && p2 && p2->next){
        Node* temp=p2->next;
        p2->next=p2->next->next;
        p1->next=temp;
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=NULL;
    printList(head);
    printList(newhead);
    return newhead;
}

Node* cloneLL3(Node *h1){
    Node *curr=h1;
    while(curr!=NULL){
        Node *temp=curr->next;
        curr->next=new Node(curr->data);
        curr->next->next=temp;
        curr=temp;
    }

    for(Node *curr=h1;curr!=NULL;curr=curr->next->next){
        curr->next->randomPtr=(curr->randomPtr)?(curr->randomPtr->next):NULL;
    }

    Node *h2=h1->next;
    Node *clone=h2;
    for(Node *curr=h1;curr!=NULL;curr=curr->next){
        curr->next=curr->next->next;
        clone->next=clone->next?clone->next->next:NULL;
        clone=clone->next;
    }
    return h2;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(5);
    Node* temp2=new Node(20);
    Node* temp3=new Node(15);
    Node* temp4=new Node(20);
    head->next=temp1;
    head->randomPtr=temp2;
    temp1->next=temp2;
    temp1->randomPtr=temp3;
    temp2->next=temp3;
    temp2->randomPtr=head;
    temp3->next=temp4;
    temp3->randomPtr=temp4;
    temp4->randomPtr=temp3;
    printList(head);
    
    Node* newhead=cloneLL3(head);
    // printList(newhead);
    cout<<"---------"<<endl;
    newhead->next->data=55;
    printList(newhead);
    printList(head);
    return 0;
}