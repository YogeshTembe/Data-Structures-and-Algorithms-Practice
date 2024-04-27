#include<iostream>
#include<unordered_set>
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

Node * removeDuplicates( Node *head) 
{
    // your code goes here
    unordered_set<int>elems;
    Node *curr=head;
    elems.insert(curr->data);
    while(curr && curr->next){
        //cout<<curr->data<<"-"<<elems.count(curr->next->data)<<endl;
        if(elems.find(curr->next->data)!=elems.end()){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }else{
            elems.insert(curr->next->data);
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node *head=new Node(2);
    Node *temp1=new Node(2);
    Node *temp2=new Node(2);
    Node *temp3=new Node(2);
    Node *temp4=new Node(2);
    Node *temp5=new Node(2);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    head=removeDuplicates(head);
    printList(head);
    return 0;
}