#include<iostream>
using namespace std;

int secondLargestElement(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[max]){
            max=i;
        }
    }

    arr[max]=-1;

    for(int i=0;i<n;i++){
        if(arr[i]>arr[max]){
            max=i;
        }
    }

    return max;
}

int main(){
    int a[]={1,3,6,2};
    cout<<secondLargestElement(a,4);
    return 0;
}