#include<iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int value;
    Node(int v):value(v),left(NULL),right(NULL){}
};

bool childSumCheck(Node *root){
    if(root==NULL){
        return true;
    }
    if(root->left!=NULL && root->right!=NULL){
        return root->value==(root->left->value)+(root->right->value) && childSumCheck(root->left) && childSumCheck(root->right);
    }
    if(root->left!=NULL){
        return root->value==(root->left->value) && childSumCheck(root->left);
    }
    if(root->right!=NULL){
        return root->value==(root->right->value) && childSumCheck(root->right);
    }
    return true;
}

int main(){
    Node *root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(12);
    root->left->left=new Node(5);
    root->left->right=new Node(5);
    cout<<childSumCheck(root);
    return 0;
}