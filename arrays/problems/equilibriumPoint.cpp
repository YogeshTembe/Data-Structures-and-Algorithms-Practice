#include<iostream>
using namespace std;

int equilibriumPoint(long long a[], int n) {
    // Your code here
    if(n==1){return 1;}
    long long max=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    long long curr=0;
    for(int i=0;i<n;i++){
        if(curr==(sum-curr-a[i])){
            return i+1;
        }
        curr+=a[i];
    }
    return -1;
}

int main(){
    long long arr[]{2,2,2,3};
    cout<<equilibriumPoint(arr,4); 
    return 0;
}