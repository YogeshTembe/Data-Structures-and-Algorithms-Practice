#include<iostream>
#include<vector>
using namespace std;

char getMaxOccuringChar(string str)
{
    // Your code here
    vector<int>t(256,0);
    for(int i=0;i<str.length();i++){
        t[str[i]]++;
    }
    int mx=INT_MIN;
    int idx=-1;
    for(int i=255;i>=0;i--){
        //cout<<t[i]<<" ";
        if(t[i]>=mx){
            //cout<<i<<" "<<t[i]<<endl;
            mx=t[i];
            idx=i;
        }
    }
    //cout<<endl;
    return char(idx);
}

int main(){
    cout<<getMaxOccuringChar("testsample")<<endl;
    return 0;
}