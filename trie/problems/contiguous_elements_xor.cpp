#include<iostream>
using namespace std;

const int bits=32;

struct TrieNode{
    int val;
    TrieNode* children[2];
    TrieNode(){
        val=0;
        children[0]=nullptr;
        children[1]=nullptr;
    }
};

void insert(TrieNode* root,int px){
    for(int i=bits-1;i>=0;i--){
        bool curr=px&(1<<i);
        if(root->children[curr]==nullptr){
            root->children[curr]=new TrieNode();
        }
        root=root->children[curr];
    }
    root->val=px;
}

int query(TrieNode* root,int px){
    for(int i=bits-1;i>=0;i--){
        bool curr=px&(1<<i);
        if(root->children[1-curr]!=nullptr){
            root=root->children[1-curr];
        }else if(root->children[curr]!=nullptr){
            root=root->children[curr];
        }
    }
    return (root->val)^px;
}

int maxSubarrayXOR(int arr[], int n)
{
    //code here
    TrieNode* root=new TrieNode();
    int res=INT_MIN;
    int px=0;
    insert(root,0);
    for(int i=0;i<n;i++){
        px=px^arr[i];
        insert(root,px);
        res=max(res,query(root,px));
    }
    return res;
}

int main(){
    int arr[]{8,1,2,12};
    cout<<maxSubarrayXOR(arr,4);
    return 0;
}