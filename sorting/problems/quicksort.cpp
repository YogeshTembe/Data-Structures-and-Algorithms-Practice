#include<iostream>
using namespace std;

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

int partition (int arr[], int low, int high)
{
    // Your code here
    //Hoare's partition
    int i=low-1;
    int j=high+1;
    int pivot=arr[low];
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j){
            return j;
        }
        //swap(arr[i],arr[j]);
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

void quickSort(int arr[], int low, int high)
{
    // code here
    if(low<high){
        int p=partition(arr,low,high);
        quickSort(arr,low,p);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int arr[5]={4, 1, 3, 9, 7};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}