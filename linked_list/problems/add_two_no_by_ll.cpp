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

Node* reverse(Node* head){
    Node* curr=head;
    Node* prevnode=NULL;
    Node* nextnode=NULL;
    while(curr!=NULL){
        //cout<<curr->data<<" ";
        nextnode=curr->next;
        curr->next=prevnode;
        prevnode=curr;
        curr=nextnode;
    }
    //cout<<endl;
    head=prevnode;
    return head;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    first=reverse(first);
    second=reverse(second);

    // printList(first);
    // printList(second);
    Node *p1=first;
    Node *p2=second;
    Node *res=new Node(0);
    int carry=0;
    int headsum=p1->data+p2->data;
    if(headsum>9){
        carry=headsum/10;
    }
    res->data=headsum%10;
    //cout<<"h-"<<(headsum)<<endl;
    p1=p1->next;
    p2=p2->next;
    Node *newhead=res;
    //res=res->next;
    while(p1 && p2){
        headsum=p1->data+p2->data+carry;
        if(headsum>9){
            carry=headsum/10;
        }else{
            carry=0;
        }
        //cout<<(headsum%10)<<endl;
        Node *newnode=new Node(headsum%10);
        res->next=newnode;
        res=res->next;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1){
        headsum=p1->data+carry;
        if(headsum>9){
            carry=headsum/10;
        }else{
            carry=0;
        }
        Node *newnode=new Node(headsum%10);
        res->next=newnode;
        res=res->next;
        p1=p1->next;
    }
    while(p2){
        headsum=p2->data+carry;
        if(headsum>9){
            carry=headsum/10;
        }else{
            carry=0;
        }
        Node *newnode=new Node(headsum%10);
        res->next=newnode;
        res=res->next;
        p2=p2->next;
    }
    if(carry!=0){
        Node *newnode=new Node(carry);
        res->next=newnode;
    }
    newhead=reverse(newhead);
    return newhead;
}

int main(){
    Node *head=new Node(9);
    Node *temp1=new Node(9);
    Node *temp2=new Node(9);

    head->next=temp1;
    temp1->next=temp2;
    //temp2->next=temp3;
    //temp3->next=temp4;

    Node *head2=new Node(9);
    Node *temp21=new Node(9);
    
    head2->next=temp21;
    // printList(head);
    // printList(head2);
    Node *res=addTwoLists(head2,head);
    printList(res);
    return 0;
}