#include<iostream>
#include<vector>
using namespace std;

string reverseWords(string s){
    vector<string>words;
    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            words.push_back(temp);
            temp="";
        }else{
            temp+=s[i];
        }
    }
    words.push_back(temp);
    //for(auto w:words){cout<<w<<endl;}
    string res=words[words.size()-1];
    for(int i=words.size()-2;i>=0;i--){
        //cout<<i<<" "<<words[i]<<endl;
        res=res+" "+words[i];
    }
    return res;
}

int main(){
    cout<<reverseWords("welcome to gfg");
    return 0;
}