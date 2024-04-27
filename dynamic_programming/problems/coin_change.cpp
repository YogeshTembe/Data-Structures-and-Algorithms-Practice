#include<iostream>
#include<vector>
using namespace std;

//recursive solution
long long numberOfWays(int coins[],int numberOfCoins,int value)
{
    if(value==0){return 1;}
    if(value<0){return 0;}
    if(numberOfCoins==0){return 0;}
    return numberOfWays(coins,numberOfCoins,value-coins[numberOfCoins-1])+numberOfWays(coins,numberOfCoins-1,value);
}

//dp solution
long long numberOfWays2(int coins[],int numberOfCoins,int value){
    vector<vector<long long>>dp(numberOfCoins+1,vector<long long>(value+1,0));
    for(int i=0;i<=numberOfCoins;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=value;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=numberOfCoins;i++){
        for(int j=1;j<=value;j++){
            dp[i][j]=dp[i-1][j];
            if(coins[i-1]<=j){
                dp[i][j]+=dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[numberOfCoins][value];
}

int main(){
    int coins[]{2,5,3,6};
    cout<<numberOfWays2(coins,4,10);
    return 0;
}