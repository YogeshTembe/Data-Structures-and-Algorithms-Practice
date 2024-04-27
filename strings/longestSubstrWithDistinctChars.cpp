#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubstr(string s){
    unordered_map<char,int>lastCharIdx;
    int maxlen=0;
    int st=-1;
    for(int i=0;i<s.length();i++){
        if(lastCharIdx.find(s[i])!=lastCharIdx.end()){
            st=max(st,lastCharIdx[s[i]]);
        }
        maxlen=max(maxlen,(i-st));
        //cout<<s[i]<<" "<<(i-st)<<endl;
        lastCharIdx[s[i]]=i;
    }
    return maxlen;
}

int longestSubstr2(string str){
    int n=str.length();
    int res=0;
    vector<int>prev(256,-1);
    int i=0;
    for(int j=0;j<n;j++){
        i=max(i,prev[str[j]]+1);
        int maxEnd=j-i+1;
        res=max(res,maxEnd);
        cout<<"j-"<<j<<" i-"<<i<<" maxEnd-"<<maxEnd<<endl;
        prev[str[j]]=j;
    }
    return res;
}

int main(){
    cout<<longestSubstr2("abcadba")<<endl;
    //cout<<longestSubstr2("aaa")<<endl;
    return 0;
}