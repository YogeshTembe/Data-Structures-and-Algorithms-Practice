#include<iostream>
using namespace std;

int lomutoPartition(int arr[],int l,int h){
    int i=l-1;
    int pivot=arr[h];
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}

int kthSmallest(int arr[], int n, int k)
{
    // Your code here
    int low=0;
    int high=n-1;
    while(low<=high){
        int p=lomutoPartition(arr,low,high);
        for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
        cout<<endl;
        if(p==k-1){
            return arr[p];
        }
        else if(p>(k-1)){
            high=p-1;
        }else{
            low=p+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={3,5,4,2,9};
    cout<<kthSmallest(arr,5,4);
    return 0;
}