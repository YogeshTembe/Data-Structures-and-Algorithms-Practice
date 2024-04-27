#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int i, vector<int>& A,int B,vector<int>& curr,vector<vector<int>>& ans){
    //cout<<i<<" "<<B<<endl;
    if(i>=A.size() || B<=0){
        if(B==0){ans.push_back(curr);}
        return;
    }
    if(A[i]<=B){
        curr.push_back(A[i]);
        solve(i,A,B-A[i],curr,ans);
        curr.pop_back();
    }
    solve(i+1,A,B,curr,ans);
}

vector<vector<int>> combinationSum(vector<int> &A, int B) {
    // Your code here
    sort(A.begin(),A.end());
    vector<int>curr;
    vector<vector<int>>ans;
    cout<<"here"<<endl;
    solve(0,A,B,curr,ans);
    return ans;
}

int main(){
    /*
    5
8 1 8 6 8
12
    */
    vector<int>A{2,6,5,7};
    auto res=combinationSum(A,16);
    for(auto a:res){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}