#include<iostream>
#include<vector>
using namespace std;

string concatenatedString(string s1, string s2) 
{ 
    // Your code here
    vector<int>table(256,0);
    string temp="";
    for(int i=0;i<s1.length();i++){
        table[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        if(table[s2[i]]==0){
            temp+=s2[i];
        }else{
            table[s2[i]]=-1;
        }
    }
    string temp2="";
    for(int i=0;i<s1.length();i++){
        if(table[s1[i]]!=-1){
            temp2+=s1[i];
        }
    }
    return temp2+temp;
}


int main(){
    cout<<concatenatedString("aacdb","gafd")<<endl;
    cout<<concatenatedString("abcs","cxzca")<<endl;
    return 0;
}