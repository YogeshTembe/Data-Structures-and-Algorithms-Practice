#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d):data(d),next(NULL){}
};

int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    //cout<<slow->data<<" "<<fast->data<<endl;
    if(slow!=fast){
        return 0;
    }
    slow=slow->next;
    int count=1;
    while(slow!=fast){
        count++;
        slow=slow->next;
    }
    return count;
}

int main(){
    Node *head=new Node(1);
    Node *temp1=new Node(2);
    Node *temp2=new Node(3);
    Node *temp3=new Node(4);
    Node *temp4=new Node(5);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp1;

    cout<<countNodesinLoop(head);
    return 0;
}