#include<iostream>
using namespace std;

const int ALPHABET_SIZE=26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
    TrieNode(){
        isLeaf=false;
        for(int i=0;i<ALPHABET_SIZE;i++){
            children[i]=nullptr;
        }
    }
};

void insert(TrieNode* root,string key){
    for(int i=0;i<key.length();i++){
        if(root->children[key[i]-'a']==nullptr){
            root->children[key[i]-'a']=new TrieNode();
        }
        root=root->children[key[i]-'a'];
    }
    root->isLeaf=true;
}

bool search(TrieNode* root,string key){
    for(int i=0;i<key.length();i++){
        if(root->children[key[i]-'a']==nullptr){
            return false;
        }
        root=root->children[key[i]-'a'];
    }
    return root->isLeaf;
}

int main(){
    TrieNode* root=new TrieNode();
    insert(root,"the");
    insert(root,"a");
    insert(root,"there");
    insert(root,"answer");
    insert(root,"any");
    cout<<search(root,"there");
    return 0;
}