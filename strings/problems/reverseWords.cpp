#include<iostream>
#include<vector>
using namespace std;

string reverseWords(string s) 
{ 
    // code here 
    vector<string>words;
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            words.push_back(temp);
            temp="";
        }else{
            temp+=s[i];
        }
    }
    words.push_back(temp);
    temp=words[words.size()-1];
    for(int i=words.size()-2;i>=0;i--){
        temp=temp+"."+words[i];
    }
    return temp;
} 

int main(){
    cout<<reverseWords("i.like.this.program.very.much");
    return 0;
}