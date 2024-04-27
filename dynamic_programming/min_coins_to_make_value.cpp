#include<iostream>
#include<vector>
using namespace std;

int countCoins(int val,int n,vector<int>&coins){
    if(n<0){return -1;}
    //cout<<val<<" "<<coins[n]<<endl;
    if(val==0){return 0;}
    if(val<0){return -1;}

    int res1=countCoins(val-coins[n],n,coins);
    int res2=countCoins(val,n-1,coins);

    if(res1==-1){
        return res2;
    }
    if(res2==-1){
        return 1+res1;
    }
    return min(1+res1,res2);
}

int countCoins2(int val,int n,vector<int>&coins){
    vector<vector<int>>dp(n+1,vector<int>(val+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=val;j++){
            if((j-coins[i-1])==0){
                dp[i][j]=1; continue;
            }
            if(coins[i-1]>j){dp[i][j]=-1; continue;}
            if(dp[i-1][j]==-1){dp[i][j]=1+dp[i][j-coins[i-1]];continue;}
            if(dp[i][j-coins[i-1]]==-1){dp[i][j]=dp[i-1][j];continue;}
            dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
        }
    }
    return dp[n][val];
}

int main(){
    vector<int>coins{25,10,5};
    cout<<countCoins(30,2,coins)<<endl;
    cout<<countCoins2(30,2,coins)<<endl;
    vector<int>coins2{9,6,5,1};
    cout<<countCoins(16,3,coins2)<<endl;
    cout<<countCoins2(16,3,coins2)<<endl;
    return 0;
}