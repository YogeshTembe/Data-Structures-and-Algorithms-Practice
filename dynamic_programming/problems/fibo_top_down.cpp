#include<iostream>
using namespace std;

long long findNthFibonacci(int number, long long int dp[])
{
    // Your Code Here
    //cout<<number<<" "<<dp[number]<<endl;
    if(dp[number]!=0){
        return dp[number];
    }
    if(number==1 || number==2){
        dp[number]=1;
    }else{
        dp[number]=findNthFibonacci(number-1,dp)+findNthFibonacci(number-2,dp);
    }
    return dp[number];
}

int main(){
    int number=7;
    long long int dp[8];
    for(int i=0;i<=7;i++){
        dp[i]=0;
    }
    cout<<findNthFibonacci(number,dp);
    return 0;
}