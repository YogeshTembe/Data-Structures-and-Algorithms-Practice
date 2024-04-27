#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(string a, string b){    
    // Your code here
    if(a.length()!=b.length()){return false;}
    unordered_map<char,int>table;
    for(int i=0;i<a.length();i++){
        table[a[i]]++;
    }
    for(int i=0;i<b.length();i++){
        if(table.find(b[i])==table.end()){
            return false;
        }
        table[b[i]]--;
    }
    for(auto t:table){
        if(t.second!=0){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<isAnagram("geeksforgeeks","forgeeksgeeks")<<endl;
    cout<<isAnagram("allergy","allergic")<<endl;
    return 0;
}