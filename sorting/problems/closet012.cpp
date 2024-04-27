#include<iostream>
using namespace std;

void segragate012(int arr[], int N)
{
    // Your Code Here
    int mid=0,left=0,right=N-1;
    while(mid<=right){
        if(arr[mid]==0){
            swap(arr[left],arr[mid]);
            mid++;
            left++;
        }else if(arr[mid]==2){
            swap(arr[right],arr[mid]);
            right--;
        }else{
            mid++;
        }
    }
}

int main(){
    int arr[]={0, 2, 1, 2, 0};
    segragate012(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}