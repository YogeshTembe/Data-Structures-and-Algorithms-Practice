#include<iostream>
#include<cmath>
using namespace std;

int minAdjDiff(int arr[], int n){    
    // Your code here
    int min=abs(arr[0]-arr[1]);
    for(int i=0;i<n-1;i++){
        if(abs(arr[i]-arr[i+1])<min){
            min=abs(arr[i]-arr[i+1]);
        }
    }
    if(abs(arr[0]-arr[n-1])<min){min=abs(arr[0]-arr[n-1]);}
    return min;
}

int main(){
    //int arr[]{8,-8,9,-9,10,-11,12};
    int arr[]{10,-3,-4,7,6,5,-4,-1};
    cout<<minAdjDiff(arr,8);
    return 0;
}