#include<iostream>
using namespace std;

int leftIndex(int N, int arr[], int X){
    // Your code here
    int left=0,right=N-1;
    int mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]>X){
            right=mid-1;
        }else if(arr[mid]<X){
            left=mid+1;
        }else{
            if(mid==0|| arr[mid]!=arr[mid-1]){
                return mid;
            }else{
                right=mid-1;
            }
        }
    }
    return -1;
}


int main(){
    int arr[]{1,1,2,2,3,4,5,5,6,7};
    int X=1;
    cout<<leftIndex(10,arr,2);
    return 0;
}