#include<iostream>
#include<vector>
using namespace std;

int minJumps(int idx,vector<int>arr){
    if(idx>=arr.size()){
        return INT_MAX;
    }
    //cout<<idx<<" "<<arr[idx]<<endl;
    if(idx==arr.size()-1){
        return 0;
    }
    
    int res=INT_MAX;
    for(int i=1;i<=arr[idx];i++){
        int temp=minJumps(idx+i,arr);
        if(temp!=INT_MAX){
            res=min(res,1+temp);
        }
    }
    return res;
}

int main(){
    vector<int>arr{3,4,2,1,2,1};
    cout<<minJumps(0,arr)<<endl;
    vector<int>arr2{4,1,5,3,1,3,2,1,8};
    cout<<minJumps(0,arr2)<<endl;
    return 0;
}