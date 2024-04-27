#include<iostream>
#include<vector>
using namespace std;

//recursive solution
long long solve(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    if(n==2){
        return max(arr[0],arr[1]);
    }
    return max(arr[n-1]+solve(arr,n-2),solve(arr,n-1));
}

//dp solution
long long solve2(int arr[],int n){
    vector<long long>dp(n,0);
    if(n==0){return 0;}
    if(n==1){return arr[0];}
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[n-1];
}

long long maximumSum(int arr[], int sizeOfArray)
{
    //Your code here
    return solve2(arr,sizeOfArray);
}

int main(){
    int arr[]={4,5,6,7,8};
    cout<<maximumSum(arr,5);
    return 0;
}