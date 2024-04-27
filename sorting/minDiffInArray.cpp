#include<iostream>
#include<algorithm>
using namespace std;

int getMinDiff(int arr[],int n){
    sort(arr,arr+n);
    int min=INT_MAX;
    for(int i=0;i<n-1;i++){
        if(min>(arr[i+1]-arr[i])){
            min=arr[i+1]-arr[i];
        }
    }
    return min;
}

int main(){
    int arr[]{1,8,12,5,18};
    cout<<getMinDiff(arr,5);
    return 0;
}