#include<iostream>
#include<vector>
using namespace std;

int indexOfLeftMostNonRepChar(string s){
    vector<int>freq(s.length(),0);
    int res=-1;
    for(int i=s.length()-1;i>=0;i--){
        if(freq[int(s[i]-'a')]==0){
            res=i;
        }
        freq[int(s[i]-'a')]++;
    }
    return res;
}

int main(){
    cout<<indexOfLeftMostNonRepChar("geeksforgeeks")<<endl;
    return 0;
}