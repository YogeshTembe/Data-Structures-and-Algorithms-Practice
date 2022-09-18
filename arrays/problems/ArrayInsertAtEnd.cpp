#include<iostream>
using namespace std;

void insertAtEnd(int arr[],int sizeOfArray,int element)
{
    //Your code here
    arr[sizeOfArray-1]=element;
}

int main(){
    int arr[]{1,2,3,4,5};
    insertAtEnd(arr,6,90);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}