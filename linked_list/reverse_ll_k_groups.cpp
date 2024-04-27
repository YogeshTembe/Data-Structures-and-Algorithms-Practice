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

// Node* reverse(Node* head,Node* prevnode,int k){
//     Node* curr=head;
//     Node* nextnode=NULL;
//     while(k-- && curr){
//         nextnode=curr->next;
//         curr->next=prevnode;
//         prevnode=curr;
//         curr=nextnode;
//     }
//     return prevnode;
// }

//Recursive solution
Node* reverseInKGroups(Node* head,int k){
    if(head==NULL){return NULL;}
    Node* curr=head;
    Node* prevnode=NULL;
    Node* nextnode=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        nextnode=curr->next;
        curr->next=prevnode;
        prevnode=curr;
        curr=nextnode;
        count++;
    }
    printList(head);
    //if(nextnode!=NULL){
        Node* rest_head=reverseInKGroups(nextnode,k);
        //cout<<rest_head->data<<endl;
        //cout<<head->data<<endl;
        head->next=rest_head;
    //}
    //cout<<"p-"<<prevnode->data<<endl;
    return prevnode;
}

//Iterative solution
// Node* reverseInKGroups2(Node* head,int k){
//    if(head==NULL){return NULL;}
//     Node* curr=head;
//     Node* prevnode=NULL;
//     Node* nextnode=NULL;
//     // while()
//     int count=0;
//     while(curr!=NULL && count<k){
//         nextnode=curr->next;
//         curr->next=prevnode;
//         prevnode=curr;
//         curr=nextnode;
//         count++;
//     }
//     printList(head);
//     //if(nextnode!=NULL){
//         Node* rest_head=reverseInKGroups(nextnode,k);
//         //cout<<rest_head->data<<endl;
//         //cout<<head->data<<endl;
//         head->next=rest_head;
//     //}
//     //cout<<"p-"<<prevnode->data<<endl;
//     return prevnode; 
// }

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    Node* temp3=new Node(40);
    Node* temp4=new Node(50);
    Node* temp5=new Node(60);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    printList(head);
    head=reverseInKGroups(head,3);
    printList(head);
    return 0;
}