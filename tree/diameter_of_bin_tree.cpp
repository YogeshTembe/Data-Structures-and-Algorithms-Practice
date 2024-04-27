#include<iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    Node(int d):data(d),left(NULL),right(NULL){}
};

int maxdia=INT_MIN;

int diameterofbintree(Node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    maxdia=max(maxdia,1+diameterofbintree(root->left)+diameterofbintree(root->right));
    return 1+max(diameterofbintree(root->left),diameterofbintree(root->right));
}

int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->left->left=new Node(60);
    diameterofbintree(root);
    cout<<maxdia;
    return 0;
}