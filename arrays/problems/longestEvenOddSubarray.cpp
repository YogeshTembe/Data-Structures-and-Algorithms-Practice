#include<iostream>
using namespace std;

int maxEvenOdd(int arr[], int n) 
{ 
    //Your code here
    int len=0;
    int max=0;
    for(int i=0;i<n-1;i++){
        if((arr[i]%2==0 && arr[i+1]%2!=0) || (arr[i]%2!=0 && arr[i+1]%2==0)){
            len+=1;
        }
        if((arr[i]%2==0 && arr[i+1]%2==0) || (arr[i]%2!=0 && arr[i+1]%2!=0)){
            len+=1;
            if(len>max){max=len;}
            len=0;
        }
    }
    len++;
    if(len>max){max=len;}
    return max;
} 

int main(){
    int a[]{4,6,7,8,8,8,8,8,6,7,8,9};
    cout<<maxEvenOdd(a,12);
    return 0;
}