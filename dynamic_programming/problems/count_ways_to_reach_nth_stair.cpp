#include<iostream>
#include<vector>
using namespace std;

//recursive solution
int countWays(int n)
{
    // your code here
    if(n<0){return 0;}
    if(n==0){return 1;}
    return countWays(n-1)+countWays(n-2);
}

//dp solution
int countWays2(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    cout<<countWays2(5);
    return 0;
}