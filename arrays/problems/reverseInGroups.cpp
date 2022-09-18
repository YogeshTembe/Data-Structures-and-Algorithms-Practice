#include<iostream>
#include<vector>
using namespace std;

void reverseInGroups(vector<long long>& arr, int n, int k){
    // code here
    int left=0;
    int right=k-1;
    int temp=0;
    for(int i=0;i<n;i=i+k){
        left=i;
        right=i+k-1;
        if(right>n-1){right=n-1;}
        while(left<right){
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
    }
    return;
}

int main(){
    // vector<long long>arr{1,2,3,4,5,6,7,8,9,10,11,12};
    //vector<long long>arr{1,2,3,4,5};
    vector<long long>arr{5,6,8,9};
    reverseInGroups(arr,arr.size(),3);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}