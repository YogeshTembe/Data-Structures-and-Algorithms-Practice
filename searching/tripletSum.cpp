#include<iostream>
using namespace std;


bool findSum2(int arr[],int start,int n,int sum){
    int i=start;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==sum){return true;}
        if(arr[i]+arr[j]>sum){
            j=j-1;//move 2nd pointer 
        }else{
            i=i+1;//move first pointer
        }
    }
    return false;
}

bool tripletSum(int arr[],int n,int sum){
   for(int i=0;i<n-2;i++){
        bool res=findSum2(arr,i+1,n,sum-arr[i]);
        if(res){
            return true;
        }
   } 
   return false;
}

int main(){
    int arr[]{2,3,4,8,9,20,40};
    cout<<tripletSum(arr,7,32);
    return 0;
}