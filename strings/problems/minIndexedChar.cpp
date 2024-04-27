#include<iostream>
#include<vector>
using namespace std;

int minIndexChar(string str, string patt)
{
    // Your code here
    vector<int>table(256,-1);
    for(int i=0;i<patt.length();i++){
        table[patt[i]]=i;
    }
    for(int i=0;i<str.length();i++){
        if(table[str[i]]>=0){
            return i;
        }
    }
    return -1;
}

int main(){
    cout<<minIndexChar("geeksforgeeks","set")<<endl;
    cout<<minIndexChar("adcffaet","onkl")<<endl;
    return 0;
}