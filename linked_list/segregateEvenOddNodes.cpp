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

void segregateEvenOddNodes(Node* head){
    Node* even=head;
    Node* odd=head;
    Node* curr=head;
    while(true){
        while(even!=NULL && even->data%2!=0){
            even=even->next;
        }
        while(odd!=NULL && odd->data%2==0){
            odd=odd->next;
        }
        //cout<<even->data<<" "<<odd->data<<endl;
        if(even==NULL || odd==NULL){return;}
        int temp=even->data;
        even->data=odd->data;
        odd->data=temp;
    }
}

int main(){
    Node* head=new Node(5);
    Node* temp1=new Node(10);
    Node* temp2=new Node(7);
    // Node* temp3=new Node(11);
    // Node* temp4=new Node(5);
    //Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    //temp2->next=temp3;
    //temp3->next=temp4;
    //temp4->next=temp5;
    printList(head);
    segregateEvenOddNodes(head);
    printList(head);
    return 0;
}