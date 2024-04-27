#include<iostream>
#include<vector>
using namespace std;

int solve(int i,vector<int>& arr){
    if(i==arr.size()-1){
        return arr[i];
    }
    int res=0;
    for(int j=i+2;j<arr.size();j++){
        res=max(res,solve(j,arr));
    }
    return res+arr[i];
}

int maxSum(vector<int>arr){
    int res=INT_MIN;
    for(int i=0;i<arr.size();i++){
        res=max(res,solve(i,arr));
    }
    return res;
}

int main(){
    vector<int>arr{8,7,6,10};
    cout<<maxSum(arr)<<endl;
    vector<int>arr2{10,5,15,20,2,30};
    cout<<maxSum(arr2)<<endl;
    vector<int>arr3{1,10,2};
    cout<<maxSum(arr3)<<endl;
    return 0;
}