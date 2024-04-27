#include<iostream>
using namespace std;

//Naive solution
//Time complexity=O(n2)
bool findSum(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                return true;
            }
        }
    }
    return false;
}

//Efficient solution-Two pointer approach
//since we are given sorted array so we should make use of that fact
//Time Complexity=O(n)
bool findSum2(int arr[],int n,int sum){
    int i=0;
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

int main(){
    int arr[]{2,5,8,12,20};
    cout<<findSum2(arr,5,17);
    return 0;
}