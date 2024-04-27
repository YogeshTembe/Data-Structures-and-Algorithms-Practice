#include<iostream>
#include<vector>
using namespace std;

void solve(int n,vector<int>&dp){
    //int sum=0;
    for(int i=0;i<n;i++){
        //cout<<"--"<<dp[i]*dp[n-i-1]<<endl;
        dp[n]+=dp[i]*dp[n-i-1];
    }
}

int countBsts(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        solve(i,dp);
        //cout<<dp[i]<<endl;
    }
    return dp[n];
}

int main(){
    cout<<countBsts(4)<<endl;
    cout<<countBsts(5)<<endl;
    return 0;
}