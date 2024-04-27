#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(string s1,string s2){
    unordered_map<int,int>mp;
    for(int i=0;i<s1.length();i++){
        mp[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        if(mp.find(s2[i])!=mp.end()){
            mp[s2[i]]--;
            if(mp[s2[i]]<=0){
                mp.erase(s2[i]);
            }
        }else{
            return false;
        }
    }
    return mp.size()==0;
}

int main(){
    cout<<isAnagram("aab","bab")<<endl;
    return 0;
}