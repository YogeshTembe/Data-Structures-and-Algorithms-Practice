#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
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

Node* mergeTwoSortedLists(Node *head1,Node * head2){
    Node *ptr1=head1;
    Node *ptr2=head2;
    if(head1==NULL){return ptr2;}
    if(head2==NULL){return ptr1;}
    Node *head;
    if(ptr1->data < ptr2->data){
        head=ptr1;
        ptr1=ptr1->next;
    }else{
        head=ptr2;
        ptr2=ptr2->next;
    }
    head->prev=NULL;
    Node *curr=head;
    while(ptr1 && ptr2){
        if(ptr1->data < ptr2->data){
            curr->next=ptr1;
            ptr1->prev=curr;
            curr=curr->next;
            ptr1=ptr1->next;
        }else{
            curr->next=ptr2;
            ptr2->prev=curr;
            curr=curr->next;
            ptr2=ptr2->next;
        }
    }

    while(ptr1){
        curr->next=ptr1;
        ptr1->prev=curr;
        curr=curr->next;
        ptr1=ptr1->next;
    }
    while(ptr2){
       curr->next=ptr2;
        ptr2->prev=curr;
        curr=curr->next;
        ptr2=ptr2->next; 
    }
    return head;
}

struct Node *sortDoubly(struct Node *head)
{
	// Your code here
    if(head!=NULL && head->next!=NULL){
        Node *slow=head;
        Node *fast=head;
        while(fast && fast->next){
            fast=fast->next;
            if(fast->next){
            fast=fast->next;
            slow=slow->next;
            }
        }
        //mid is slow
        Node *nodeaftermid=slow->next;
        //to seperate first list from second
        nodeaftermid->prev=NULL;
        slow->next=NULL;
        cout<<"----"<<endl;
        printList(head);
        printList(nodeaftermid);
        Node *newhead1=sortDoubly(head);
        Node *newhead2=sortDoubly(nodeaftermid);
        return mergeTwoSortedLists(newhead1,newhead2);
    }else{
        return head;
    }
}


int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(50);
    head->prev=NULL;
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;

    Node* head2=new Node(5);
    Node* temp21=new Node(15);
    Node* temp22=new Node(34);
    Node* temp23=new Node(50);
    head2->prev=NULL;
    head2->next=temp21;
    temp21->prev=head2;
    temp21->next=temp22;
    temp22->prev=temp21;
    temp22->next=temp23;
    temp23->prev=temp22;
    temp23->next=NULL;
    printList(head);
    printList(head2);
    //To check merge fn
    Node *newhead=mergeTwoSortedLists(head,head2);
    printList(newhead);

    //To check merge sort
    Node* head3=new Node(54);
    Node* temp31=new Node(1);
    Node* temp32=new Node(23);
    Node* temp33=new Node(2);
    Node *temp34=new Node(12);
    head3->prev=NULL;
    head3->next=temp31;
    temp31->prev=head3;
    temp31->next=temp32;
    temp32->prev=temp31;
    temp32->next=temp33;
    temp33->prev=temp32;
    temp33->next=temp34;
    temp34->prev=temp33;
    temp34->next=NULL;
    printList(head3);
    Node *res=sortDoubly(head3);
    printList(res);
    return 0;
}