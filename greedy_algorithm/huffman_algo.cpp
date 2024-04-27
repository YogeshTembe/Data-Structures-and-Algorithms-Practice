#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <queue>
using namespace std;

struct node{
    char c;
    int freq;
    node* left;
    node* right;
    node(char c,int val):c(c),freq(val),left(nullptr),right(nullptr){}
};

struct comp{
    bool operator()(node* a,node*b){
        return a->freq>b->freq;
    }
};

void printCodes(node* root,string s){
    if(root==nullptr){return;}
    if(root->c!='$'){
        cout<<root->c<<" "<<root->freq<<" "<<s<<endl;
        return;
    }
    printCodes(root->left,s+"0");
    printCodes(root->right,s+"1");
}

void formBinaryTree(vector<char>chars,vector<int>freq){
    priority_queue<node*,vector<node*>,comp>h;
    for(int i=0;i<chars.size();i++){
        h.push(new node(chars[i],freq[i]));
    }

    while(h.size()>1){
        node* l=h.top();
        h.pop();
        node* r=h.top();
        h.pop();
        node* dollarnode=new node('$',l->freq+r->freq);
        dollarnode->left=l;
        dollarnode->right=r;
        h.push(dollarnode);
    }
    printCodes(h.top(),"");
}

void huffmanCoding(vector<char>chars,vector<int>freq){
    formBinaryTree(chars,freq);
}


int main(){
    vector<char>chars{'a','b','c','d','e','f'};
    vector<int>freq{32,16,8,4,2,2};
    huffmanCoding(chars,freq);
    return 0;
}