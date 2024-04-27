#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

struct TrieNode{
    bool isend;
    TrieNode* children[26];
    TrieNode(){
        isend=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

void insert(TrieNode* root,string key){
    for(int i=0;i<key.length();i++){
        if(root->children[key[i]-'A']==nullptr){
            root->children[key[i]-'A']=new TrieNode();
        }
        root=root->children[key[i]-'A'];
    }
    root->isend=true;
}

void printWordsWithPrefix(TrieNode* crawl,string prefix,vector<string>& res){
    //cout<<"p-"<<prefix<<endl;
    if(crawl->isend){
        res.push_back(prefix);
    }
    for(int i=0;i<26;i++){
        if(crawl->children[i]){
            char a=('A'+i);
            printWordsWithPrefix(crawl->children[i],prefix+a,res);
        }
    }
}

vector<string> searchPrefix(TrieNode* root,string prefix){
    TrieNode* crawl=root;
    for(int i=0;i<prefix.length();i++){
        if(crawl->children[prefix[i]-'A']==nullptr){
            return {};
        }
        crawl=crawl->children[prefix[i]-'A'];
    }
    vector<string>res;
    //cout<<"here-"<<prefix<<endl;
    printWordsWithPrefix(crawl,prefix,res);
    return res;
}

void findAllWords(vector<string> dict, string pattern) 
{
    //code here
    unordered_map<string,multiset<string>>mp;
    for(int i=0;i<dict.size();i++){
        string key;
        for(int j=0;j<dict[i].length();j++){
            if(dict[i][j]>=65 && dict[i][j]<=90){
                key.push_back(dict[i][j]);
            }
        }
        //cout<<key<<" "<<dict[i]<<endl;
        auto it=mp.find(key);
        if(it!=mp.end()){
            mp[key].insert(dict[i]);
        }else{
            multiset<string>s{dict[i]};
            mp.insert({key,s});
        }
    }

    TrieNode* root=new TrieNode();

    for(auto m:mp){
        insert(root,m.first);
    }

    auto res=searchPrefix(root,pattern);
    for(auto r:res){
        for(auto k:mp[r]){
            cout<<k<<" ";
        }
    }
}

int main(){
    vector<string>dict{"Hi","Hello","Hello","HelloWorld","HiTech","HiGeek","HiTechWorld","HiTechCity","HiTechLab"};
    findAllWords(dict,"H");
    return 0;
}