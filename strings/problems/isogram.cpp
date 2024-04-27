#include<iostream>
#include<unordered_set>
using namespace std;

bool isIsogram(string s)
{
    //Your code here
    unordered_set<char>uchar;
    for(int i=0;i<s.length();i++){
        uchar.insert(s[i]);
    }
    return uchar.size()==s.length();
}

int main(){
    cout<<isIsogram("machine")<<endl;
    cout<<isIsogram("gfg")<<endl;
    return 0;
}