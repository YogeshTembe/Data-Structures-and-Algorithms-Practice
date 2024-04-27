#include<iostream>
#include<vector>
#include<string>  
using namespace std;

struct TrieNode{
    int isend;
    TrieNode* children[26];
    TrieNode(){
        isend=-1;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

string getRes(TrieNode* root,string key){
    int idx=-1;
    for(int i=0;i<key.length();i++){
        if(root->children[key[i]-'a']==nullptr){
            if(idx==-1){idx=i;}
            root->children[key[i]-'a']=new TrieNode();
        }
        root=root->children[key[i]-'a'];
    }
    //cout<<key<<" "<<idx<<endl;
    if(idx==-1 && root->isend>=0){
        root->isend++;
        return (key+" "+to_string(root->isend+1));
    }else{
        root->isend++;
        //cout<<"here-"<<key<<endl;
        if(idx==-1){return key;}
        return key.substr(0,idx+1);
    }
}

void check(string *arr, int n){
    //code here
    TrieNode* root=new TrieNode();
    for(int i=0;i<n;i++){
        cout<<getRes(root,arr[i])<<endl;
    }
}


int main(){
    string arr[]{"shimla","shimka","jammu","jammu","delhi","j","dehradun"};
    check(arr,7);
    return 0;
}