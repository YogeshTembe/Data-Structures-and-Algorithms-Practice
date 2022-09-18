#include<iostream>
using namespace std;

// 5
// 7 7 1 1
// 3 3

void insertAtIndex(int arr[], int sizeOfArray, int index, int element){
    for(int i=sizeOfArray-1;i>index;i--){
        //cout<<i<<endl;
        arr[i]=arr[i-1];
    }
    arr[index]=element;
}

int main(){
    int a[5]={7,7,1,1};
    insertAtIndex(a,5,3,3);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}