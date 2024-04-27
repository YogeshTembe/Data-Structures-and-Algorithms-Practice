#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findRepeatingElement(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]++;
    }
    print(arr,n);
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]<0){
            return abs(arr[i])-1;
        }
        arr[abs(arr[i])]=0-arr[abs(arr[i])];
        print(arr,n);
    }
    return -1;
}

int main(){
    int arr[]{1,2,3,0,3,4,5};
    cout<<findRepeatingElement(arr,7);
    return 0;
}