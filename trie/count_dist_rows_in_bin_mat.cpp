#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
    bool isEnd;
    TrieNode* child[2];
    TrieNode(){
        isEnd=false;
        child[0]=child[1]=nullptr;
    }
};

void insert(TrieNode* root,vector<int>& row){
    for(int i=0;i<row.size();i++){
        if(root->child[row[i]]==nullptr){
            root->child[row[i]]=new TrieNode();
        }
        root=root->child[row[i]];
    }
    root->isEnd=true;
}

void dfs(TrieNode* root,int& count){
    if(root==nullptr){return;}
    if(root->child[0]==nullptr && root->child[1]==nullptr && root->isEnd){
        count++;
        return;
    }
    dfs(root->child[0],count);
    dfs(root->child[1],count);
}

int distinctRows(vector<vector<int>>& matrix){
    TrieNode* root=new TrieNode();
    for(int i=0;i<matrix.size();i++){
        insert(root,matrix[i]);
    }
    int res=0;
    dfs(root,res);
    return res;
}

int main(){
    vector<vector<int>>matrix{{1,0,0},{1,1,0},{1,0,0},{1,0,0}};
    cout<<distinctRows(matrix);
    return 0;
}