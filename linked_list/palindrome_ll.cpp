#include<iostream>
#include<stack>
using namespace std;

struct Node{
    char data;
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
//time complexity=O(n) and aux.space=O(1)
bool isPalindrome(Node *head){
    if(head==NULL || head->next==NULL){
        return false;
    }
    stack<char>st;
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        st.push(curr->data);
    }
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        if(st.top()!=curr->data){
            return false;
        }
        st.pop();
    }
    return true;
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

//Efficient solution
bool isPalindrome2(Node *head){
    if(head==NULL){
        return true;
    }
    //find mid
    Node *slow=head;
    Node *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *rev=reverse(slow->next);
    Node *curr=head;
    printList(rev);
    while(rev!=NULL){
        if(curr->data!=rev->data){
            return false;
        }
        rev=rev->next;
        curr=curr->next;
    }
    printList(head);
    return true;
}

int main(){
    Node *head=new Node('r');
    Node *temp1=new Node('a');
    Node *temp2=new Node('d');
    Node *temp3=new Node('a');
    Node *temp4=new Node('r');
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    printList(head);
    cout<<isPalindrome2(head);
    return 0;
}