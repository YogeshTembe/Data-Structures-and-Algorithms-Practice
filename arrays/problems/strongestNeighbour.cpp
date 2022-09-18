#include<iostream>
using namespace std;

void maximumAdjacent(int sizeOfArray, int arr[]){
    for(int i=0;i<sizeOfArray-1;i++){
        //cout<<arr[i]<<" "<<arr[i+1]<<endl;
        if(arr[i]<=arr[i+1]){
            cout<<arr[i+1]<<" ";
        }else{
            cout<<arr[i]<<" ";
        }
        //cout<<arr[i]<<endl;
    }
    return;
}

int main(){
    //int arr[]{1,8,3,2,4,5};
    int arr[]{78,77,45};
    maximumAdjacent(3,arr);
    // for(int i=0;i<3;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}