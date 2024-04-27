#include<iostream>
using namespace std;

int peakElement(int arr[], int n)
{
    // Your code here
    int left=0,right=n-1,mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(arr[mid-1]>arr[mid]){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
}

int main(){
    return 0;
}