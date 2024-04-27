#include<iostream>
#include<vector>
using namespace std;

int findFloor(vector<long long> v, long long n, long long x){
    // Your code here
    int left=0;
    int right=n-1;
    int mid1=(left+right)/2;
    int mid2=mid1+1;
    while(left<right){
        if(v[mid1]==x){return mid1;}
        if(v[mid2]==x){return mid2;}
        if(v[mid1]<=x && v[mid2]>=x){
            return mid1;
        }else if(v[mid1]>x && v[mid2]>x){
            right=mid1;
        }else if(v[mid1]<x && v[mid2]<x){
            left=mid2;
        }
        mid1=(left+right)/2;
        mid2=mid1+1;
    }
    return -1;
}

int findFloor2(vector<long long> v, long long n, long long x){
    int left=0;
    int right=n-1;
    int mid=(left+right)/2;
    while(left<=right){
        mid=(left+right)/2;
        cout<<mid<<endl;
        if((v[mid]<=x && v[mid+1]>x)||(mid==n-1 && v[mid]<=x)){
            return mid;
        }else if(v[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<long long>nums{1,2,8,10,11,12,19};
    cout<<findFloor2(nums,7,9);
    return 0;
}