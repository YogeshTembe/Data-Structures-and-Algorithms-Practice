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

Node* mergeTwoLL(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL){return head2;}
    if(head2==NULL){return head1;}
    Node *p1=head1;
    Node *p2=head2;

    Node *newhead;
    Node *tail;
    if(p1->data<p2->data){
        newhead=p1;
        tail=p1;
        p1=p1->next;
    }else{
        newhead=p2;
        tail=p2;
        p2=p2->next;
    }
    while(p1 && p2){
        if(p1->data<p2->data){
            tail->next=p1;
            p1=p1->next;
            tail=tail->next;
        }else{
            tail->next=p2;
            p2=p2->next;
            tail=tail->next;
        }
    }
    if(p1){
        tail->next=p1;
    }
    if(p2){
        tail->next=p2;
    }
    return newhead;
}

Node* mergeSort(Node* head) {
    // your code here
    if(head!=NULL && head->next!=NULL){
        Node *slow=head;
        Node *fast=head;
        while(fast && fast->next){
            //cout<<slow->data<<" "<<fast->data<<endl;
            fast=fast->next;
            if(fast && fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            //cout<<slow->data<<" "<<fast->data<<endl;
        }
        cout<<slow->data<<endl;
        //mid is slow
        Node *nodeaftermid=slow->next;
        slow->next=NULL;
        cout<<"---head"<<endl;
        printList(head);
        cout<<"---nodeaftermid"<<endl;
        printList(nodeaftermid);
        Node *head3=mergeSort(head);
        Node *head4=mergeSort(nodeaftermid);
        Node *newll=mergeTwoLL(head3,head4);
        cout<<"---newll"<<endl;
        printList(newll);
        return newll;
    }else{
        return head;
    }
}

int main(){
    Node* head=new Node(3);
    Node* temp1=new Node(5);
    Node* temp2=new Node(2);
    Node* temp3=new Node(4);
    //Node* temp4=new Node(1);
    //Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    //temp3->next=temp4;
    printList(head);
    head=mergeSort(head);
    printList(head);
    return 0;
}