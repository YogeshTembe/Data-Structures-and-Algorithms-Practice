#include<iostream>
using namespace std;

string countSort(string arr){
    string res;
    // code here
    int count[26];
    for(int i=0;i<26;i++){
        count[i]=0;
    }
    
    for(int i=0;i<arr.length();i++){
        count[int(arr[i]-'a')]++;
    }
    for(int i=0;i<26;i++){
        cout<<count[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<26;i++){
        for(int j=0;j<count[i];j++){
            res=res+char(i+97);
        }
    }
    return res;
}

int main(){
    string arr="geeksforgeeks";
    cout<<countSort(arr);
    return 0;
}