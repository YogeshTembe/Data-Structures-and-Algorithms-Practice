#include<iostream>
using namespace std;

void rotateArr(int arr[], int d, int n){
    // code here
    d=d%n;
    cout<<d<<endl;
    int temp=0;
    int arr2[d];
    for(int i=0;i<d;i++){
        arr2[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        //cout<<i-d-1<<endl;
        arr[i-d]=arr[i];
    }
    for(int i=0;i<d;i++){
        arr[n-d+i]=arr2[i];
    }
}

int main(){
    int arr[]{1,2,3,4,5};
    rotateArr(arr,8,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}