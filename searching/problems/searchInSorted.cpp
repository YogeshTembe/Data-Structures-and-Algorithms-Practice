#include<iostream>
using namespace std;

int searchInSorted(int arr[], int N, int K) 
{ 
    // Your code here
    int left=0,right=N-1;
    int mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==K){
            return 1;
        }else if(arr[mid]>K){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[]{1,2,3,4,6};
    int K=6;
    cout<<searchInSorted(arr,6,K);
    return 0;
}