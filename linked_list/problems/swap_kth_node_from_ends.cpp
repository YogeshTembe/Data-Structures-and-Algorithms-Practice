#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) {
    data = x;
    next = NULL;
}
};

void printList(Node* head){
    Node* node=head;
    while(node){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(K>num){
        return head;
    }
    Node *first=head;
    Node *second=head;
    int count=0;
    while(count<K-2){
        first=first->next;
        count++;
    }
    Node *swap1prev=first;
    Node *swap1=first->next;
    if(K==1){
        swap1prev=NULL;
        swap1=head;
    }
    //cout<<swap1prev->data<<" "<<swap1->data<<endl;
    count=0;
    while(count<(num-K-1)){
        second=second->next;
        count++;
    }
    Node *swap2prev=second;
    Node *swap2=second->next;
    if(num==K){
        swap2prev=NULL;
        swap2=head;
    }
    // cout<<swap2prev->data<<" "<<swap2->data<<endl;

    Node* temp=swap1->next;
    if(swap1prev){
        swap1prev->next=swap2;
    }
    if(swap2prev && swap2prev!=swap1){
        swap2prev->next=swap1;
    }
    swap1->next=swap2->next;
    if(swap2!=temp){
        swap2->next=temp;
    }else{
        swap2->next=swap1;
    }

    if(num==K){
        return swap1;
    }else if(K==1){
        return swap2;
    }

    return head;
}

int main(){
    Node *head=new Node(1);
    Node *temp1=new Node(2);
    Node *temp2=new Node(3);
    Node *temp3=new Node(4);
    //Node *temp4=new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    //temp3->next=temp4;
    Node *res=swapkthnode(head,4,4);
    printList(res);
    return 0;
}