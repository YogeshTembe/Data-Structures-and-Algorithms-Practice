#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    // Your code here
    bool isSwapped=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                isSwapped=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(!isSwapped){break;}
    }
}

int main(){
    int arr[5]={4, 1, 3, 9, 7};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}