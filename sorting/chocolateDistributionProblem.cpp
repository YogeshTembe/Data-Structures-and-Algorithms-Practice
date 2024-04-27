#include<iostream>
#include<algorithm>
using namespace std;

int minDiffChocolates(int arr[],int n,int m){
    sort(arr,arr+n);
    int l=0,h=m-1;
    int minDiff=INT_MAX;
    for(int i=0;i<n-m;i++){
        if((arr[h]-arr[i])<minDiff){
            minDiff=(arr[h]-arr[i]);
            cout<<i<<" "<<h<<" "<<minDiff<<endl;
        }
        h++;
    }
    return minDiff;
}

int main(){
    //int arr[]{7,3,2,4,9,12,56};
    int arr[]{3,4,1,9,56,7,9,12};
    cout<<minDiffChocolates(arr,8,5);
    return 0;
}