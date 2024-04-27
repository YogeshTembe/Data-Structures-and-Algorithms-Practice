#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
    int isend;
    int startidx;
    TrieNode* children[26];
    TrieNode(){
        isend=-1;
        startidx=-1;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

pair<int,int> insert(TrieNode* root,string key,int idx){
    for(int i=0;i<key.length();i++){
        if(root->children[key[i]-'a']==nullptr){
            root->children[key[i]-'a']=new TrieNode();
        }
        root=root->children[key[i]-'a'];
    }
    root->isend++;
    if(root->startidx==-1){root->startidx=idx;}
    return {root->isend,root->startidx};
}

string mostFrequentWord(string arr[], int n) 
{
    // code here
    TrieNode* root=new TrieNode();
    int mx=INT_MIN;
    string res="";
    int mxstartidx=INT_MIN;
    for(int i=0;i<n;i++){
        //cout<<arr[i]<<endl;
        auto curr=insert(root,arr[i],i);
        cout<<arr[i]<<" "<<curr.first<<" "<<curr.second<<endl;
        if(curr.first>=mx){
            if(curr.first==mx){
                if(curr.second>=mxstartidx){
                    res=arr[i];
                    mx=curr.first;
                    mxstartidx=curr.second;
                }
            }else{
                res=arr[i];
                mx=curr.first;
                mxstartidx=curr.second;
            }
        }
    }
    return res;
}

int main(){
    string arr[]{"geeks","for","for","geeks"};
    cout<<mostFrequentWord(arr,2);
    return 0;
}