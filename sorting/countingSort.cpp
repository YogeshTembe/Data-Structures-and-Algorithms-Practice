#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> countingSort(vector<int>arr,int k){
    map<int,int>nums;
    for(int i=0;i<=k;i++){
        nums[i]=0;
    }
    for(int i=0;i<arr.size();i++){
        nums[arr[i]]=nums[arr[i]]+1;
    }
    vector<int>res;
    for(int i=0;i<nums.size();i++){
        for(int j=1;j<=nums[i];j++){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    vector<int>arr{1,4,4,1,0,1};
    auto res=countingSort(arr,5);
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}