#include<iostream>
#include<vector>
using namespace std;

int leftmostRepeatingChar(string s){
    vector<int>count(26,0);
    for(int i=0;i<s.length();i++){
        count[int(s[i]-'a')]++;
    }
    for(int i=0;i<s.length();i++){
        if(count[int(s[i]-'0')]>1){
            return i;
        }
    }
    return -1;
}

int main(){
    cout<<leftmostRepeatingChar("geeksforgeeks")<<endl;
    return 0;
}