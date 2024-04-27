#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> printNonRepeated(int arr[],int n)
{
    //Your code here
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    vector<int>res;
    for(int i=0;i<n;i++){
        if(m[arr[i]]==1){
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main(){
    return 0;
}