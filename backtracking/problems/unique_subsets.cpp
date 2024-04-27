#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int idx,vector<int>& arr,vector<int>& res,vector<vector<int>>& ans){
    ans.push_back(res);
    for(int i=idx;i<arr.size();i++){
        if(i!=idx && arr[i]==arr[i-1]){continue;}
        res.push_back(arr[i]);
        solve(i+1,arr,res,ans);
        res.pop_back();
    }
}

vector<vector<int>> AllSubsets(vector<int> arr, int n){
    // code here 
    vector<vector<int>>ans;
    vector<int>res;
    sort(arr.begin(),arr.end());
    solve(0,arr,res,ans);
    return ans;
}

int main(){
    vector<int>arr{2,1,2};
    auto res=AllSubsets(arr,3);
    for(auto a:res){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}