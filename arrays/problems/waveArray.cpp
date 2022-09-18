#include<iostream>
#include<vector>
using namespace std;

void convertToWave(int n, vector<int>& arr){    
    // Your code here
    int temp=0;
    for(int i=0;i<n-1;i=i+2){
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    return;
}

int main(){
    vector<int>arr{2,4,7,8,9,10};
    convertToWave(arr.size(),arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}