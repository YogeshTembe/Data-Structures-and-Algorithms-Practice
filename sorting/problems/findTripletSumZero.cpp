#include<iostream>
#include<algorithm>
using namespace std;

bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int left,right;
    for(int i=0;i<n-2;i++){
        left=i+1;
        right=n-1;
        while(left<right){
            int res=arr[i]+arr[left]+arr[right];
            if(res==0){
                return true;
            }else if(res<0){
                left++;
            }else{
                right--;
            }
        }
    }
    return false;
}

int main(){
    int arr[]={4,-16,43,4,7,-36,18};
    cout<<findTriplets(arr,7);
    return 0;
}