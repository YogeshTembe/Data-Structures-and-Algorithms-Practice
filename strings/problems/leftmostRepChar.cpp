#include<iostream>
#include<vector>
using namespace std;

int repeatedCharacter (string s) 
{ 
    //Your code here
    vector<int>table(256,-1);
    int minIdx=INT_MAX;
    for(int i=0;i<s.length();i++){
        if(table[s[i]]==-1){
            table[s[i]]=i;
        }else{
            //cout<<table[s[i]]<<endl;
            minIdx=min(minIdx,table[s[i]]);
        }
    }
    //for(auto t:table){cout<<t<<" ";}
    //cout<<endl;
    if(minIdx==INT_MAX){return -1;}
    return minIdx;
} 

int main(){
    cout<<repeatedCharacter("geeksforgeeks")<<endl;
    cout<<repeatedCharacter("abcd")<<endl;
    return 0;
}