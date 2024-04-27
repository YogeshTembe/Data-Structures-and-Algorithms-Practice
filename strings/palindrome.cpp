#include<iostream>
using namespace std;

bool isPalindrome(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<isPalindrome("ABCDCBA")<<endl;
    cout<<isPalindrome("ABBA")<<endl;
    cout<<isPalindrome("geek")<<endl;
    return 0;
}