#include<iostream>
using namespace std;



void mergeFunc(int arr[],int n, int low,int mid, int high){
    int s1=low;
    int s2=mid+1;
    int temp=0;
    while(s1<=mid && s2<=high){
        while(s1<=mid && arr[s1]<=arr[s2]){
            s1++;
        }
        while(s2<=high && arr[s1]>arr[s2]){
            temp=arr[s2];
            int j=s2-1;
            while(j>=s1){
                arr[j+1]=arr[j];
                j--;
            }
            arr[s1]=temp;
            s2++;
        }
    }
    while(s2<=high && s1<=mid){
        if(arr[s1]>arr[s2]){
            temp=arr[s2];
            int j=s2-1;
            while(j>=s1){
                arr[j+1]=arr[j];
                j--;
            }
            arr[s1]=temp;
            s2++;
        }else{
            s1++;
        }
    }
    return;
}

int main(){
    int arr[]{10,15,20,40,8,10,11,55};
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeFunc(arr,8,0,3,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}