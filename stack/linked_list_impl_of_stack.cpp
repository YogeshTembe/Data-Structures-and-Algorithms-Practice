#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d):data(d),next(NULL){}
};

void printList(Node *head){
    while(head){
        cout<<head->data<<" ";
    }
    cout<<endl;
}

struct MyStack{
    int cap;
    Node *head;
    int size;
    MyStack(int c){
        cap=c;
        head=NULL;
        size=0;
    }
    void push(int x){
        if(size==cap){
            return;
        }
        if(head==NULL){
            head=new Node(x);
            head->next=NULL;
        }else{
            Node *newnode=new Node(x);
            newnode->next=head;
            head=newnode;
        }
        size++;
    }
    int pop(){
        if(head==NULL){return -1;}
        int data=head->data;
        Node *temp=head;
        head=head->next;
        delete(temp);
        size--;
        return data;
    }
    bool isEmpty(){
        return (size==0);
    }
    int peek(){
        return head->data;
    }
    int sizeOfStack(){
        return size;
    }
    void print(){
        Node *curr=head;
        while(curr){
            cout<<curr->data<<" ";
        }
        cout<<endl;
    }

};

int main(){
    MyStack ms(3);
    ms.push(23);
    ms.push(34);
    cout<<ms.peek()<<endl;
    //ms.print();
    ms.push(56);
    cout<<ms.peek()<<endl;
    ms.pop();
    cout<<ms.peek()<<endl;
    return 0;
}