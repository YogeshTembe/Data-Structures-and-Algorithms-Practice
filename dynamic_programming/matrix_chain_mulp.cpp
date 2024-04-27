#include<iostream>
#include<vector>
using namespace std;

int solve(int start,int end,vector<int>& arr){
    if(end-start==2){
        return arr[start]*arr[start+1]*arr[end];
    }
    if(end-start==1){
        return 1;
    }
    int sum=0;
    for(int j=start+2;j<=end;j++){
        sum=min(sum,solve(start,j,arr)+solve(j,end,arr));
    }
    return sum;
}

int minMatrixChainMulp(vector<int>arr){
    int res=INT_MAX;
    for(int i=1;i<arr.size();i++){
        res=min(res,solve(0,i,arr)+solve(i,arr.size()-1,arr));
    }
    return res;
}

int main(){
    vector<int>arr{2,1,3,4};
    cout<<minMatrixChainMulp(arr)<<endl;
    return 0;
}