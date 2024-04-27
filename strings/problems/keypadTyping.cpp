#include<iostream>
#include<vector>
#include<string>
using namespace std;

string printNumber(string s, int n) 
{
    //code here
    vector<int>table{2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    string res;
    for(int i=0;i<s.length();i++){
        res=res+to_string(table[s[i]-'a']);
    }
    return res;
}

int main(){
    cout<<printNumber("geeksquiz",9)<<endl;
    return 0;
}