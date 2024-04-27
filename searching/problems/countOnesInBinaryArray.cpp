#include<iostream>
using namespace std;

int countOnes(int arr[], int N)
{
    // Your code here
    int left=0,right=N-1;
    int mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if((mid==0 && arr[mid]==0) || (arr[mid]==0 && arr[mid-1]==1)){
            return mid;
        }else if(arr[mid]>0){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return N;
}

int main(){
    int arr[]{1,1,1};
    cout<<countOnes(arr,3);
    return 0;
}