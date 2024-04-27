#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> separateChaining(int hashSize,int arr[],int sizeOfArray)
{
    //Your code here
    vector<vector<int>>res(hashSize,vector<int> (1, 0));
    for(int i=0;i<sizeOfArray;i++){
        res[(arr[i]%hashSize)-1].push_back(arr[i]);
    }

    for(int i=0;i<res.size();i++){
        auto it=res[i].begin()+i;
        res[i].erase(it);
    } 
    return res;
}

int main(){
    int arr[]={92,4,14,24,44,91};
    auto res=separateChaining(10,arr,6);
    return 0;
}