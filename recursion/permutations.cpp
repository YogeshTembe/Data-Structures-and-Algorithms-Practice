#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void permute(string s, int i){
    if(s.length()==i){
       cout<<"res-"<<s<<" "<<endl;
       return;
    }
    for(int j=i;j<s.length();j++){
        cout<<i<<s[i]<<s[j]<<endl;
        std::swap(s[i],s[j]);
        permute(s,i+1);
        std::swap(s[i],s[j]);
    }
}

void permute2(string s , string answer)
{
    if(s.length() == 0)
    {
        cout<<answer<<"  ";
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        //cout<<ch<<endl;
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute2(rest , answer+ch);
    }
  
}

int main(){
    //permute("ABC",0);
    permute2("ABC","");
    return 0;
}