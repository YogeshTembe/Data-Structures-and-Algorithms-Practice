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

Node* mergeLL(Node *a,Node *b){
    if(a==NULL && b==NULL){
        return NULL;
    }else if(a==NULL){
        return b;
    }else if(b==NULL){
        return a;
    }

    Node *head=NULL;
    Node *tail=NULL;
    if(a->data<=b->data){
        head=a;
        tail=a;
        a=a->next;
    }else{
        head=b;
        tail=b;
        b=b->next;
    }
    while(a && b){
        cout<<a->data<<" "<<b->data<<endl;
        if((a->data)<=(b->data)){
            tail->next=a;
            tail=a;
            a=a->next;
        }else{
            tail->next=b;
            tail=b;
            b=b->next;
        }
        //tail=tail->next;
    }
    cout<<a->data<<endl;
    cout<<tail->data<<endl;
    if(a==NULL){
        tail->next=b;
    }
    else{
        tail->next=a;
    }
    return head;
}

int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    Node *temp3=new Node(40);
    Node *temp4=new Node(80);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    Node *head2=new Node(5);
    Node *temp12=new Node(15);
    Node *temp22=new Node(17);
    Node *temp32=new Node(18);
    //Node *temp42=new Node(35);
    head2->next=temp12;
    temp12->next=temp22;
    temp22->next=temp32;
    //temp32->next=temp42;

    printList(head);
    printList(head2);

    Node *newhead=mergeLL(head,head2);
    printList(newhead);

    return 0;
}