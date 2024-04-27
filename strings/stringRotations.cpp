#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateString(string& s,int i){
    reverse(s.begin(), s.begin()+i);
    reverse(s.begin()+i, s.end());
    reverse(s.begin(), s.end());
}

//Naive Solution
bool isSameStrRotated(string s1,string s2){
    for(int i=0;i<s1.length();i++){
        rotateString(s1,1);
        if(s1==s2){
            return true;
        }
    }
    return false;
}

//Efficient solution - find s2 in s1+s1

int main(){
    cout<<isSameStrRotated("ABCD","CADB");
    return 0;
}