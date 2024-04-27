#include<iostream>
#include<vector>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    Node(int d):data(d),left(NULL),right(NULL){}
};

bool buildPath(Node *root, int ele,vector<int>&path){
    if(root==NULL){
        return false;
    }
    if(root->data==ele){
        return true;
    }
    bool leftcheck=false;
    if(root->left){
        leftcheck=buildPath(root->left,ele,path);
    }
    bool rightcheck=false;
    if(root->right){
        rightcheck=buildPath(root->right,ele,path);
    }
    if(leftcheck || rightcheck){
        path.push_back(root->data);
    }
    // else if(rightcheck){
    //     path.push_back(root->right->data);
    // }
    return leftcheck||rightcheck;
}

int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->left->left=new Node(60);
    vector<int>path;
    buildPath(root,60,path);
    //path.push_back(root->data);
    for(auto p:path){cout<<p<<" ";}
    return 0;
}