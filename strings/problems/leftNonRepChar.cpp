#include<iostream>
#include<vector>
using namespace std;

char nonrepeatingCharacter(string s)
{
    //Your code here
    vector<int>table(256,-1);
    int minIdx=INT_MAX;
    for(int i=0;i<s.length();i++){
        if(table[s[i]]==-1){
            table[s[i]]=i;
        }else{
            table[s[i]]=-2;
        }
    }
    for(int i=0;i<table.size();i++){
        if(table[i]>=0){
            minIdx=min(minIdx,table[i]);
        }
    }
    if(minIdx==INT_MAX){return '$';}
    return s[minIdx];
}

int main(){
    cout<<nonrepeatingCharacter("hello")<<endl;
    cout<<nonrepeatingCharacter("zxvczbtxyzvy")<<endl;
    cout<<nonrepeatingCharacter("iioopp")<<endl;
    return 0;
}