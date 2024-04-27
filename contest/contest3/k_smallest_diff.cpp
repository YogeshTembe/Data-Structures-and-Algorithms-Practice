#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(int arr[],int l,int m,int h){
    //cout<<l<<" "<<m<<" "<<h<<endl;
    const int n1=m-l+1;
    const int n2=h-m;
    int *arr1=new int[n1];//left
    int *arr2=new int[n2];//right
    //cout<<"arr1"<<endl;
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
        //cout<<arr1[i];
    }
    // cout<<endl;
    // cout<<"arr2"<<endl;
    for(int i=0;i<n2;i++){
        arr2[i]=arr[m+i+1];
        //cout<<arr2[i];
    }
    //cout<<endl;

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;
        }else{
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k]=arr1[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=arr2[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[],int l,int h){
    if(l<h){
        int m=l+(h-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

int countPairs(int arr[],int n,int mid){
    int res=0;
    for(int i=0;i<n;i++){
        res=res+(upper_bound(arr+i,arr+n,arr[i]+mid)-(arr+i+1));
    }
    return res;
}

int kthDiff(int arr[], int n, int k) 
{ 
   //Your code here
    merge_sort(arr,0,n-1);
    int low = arr[1] - arr[0];
    for (int i = 1; i <= n-2; ++i)
        low = min(low, arr[i+1] - arr[i]);
    
    int high=arr[n-1]-arr[0];

    while(low<high){
        int mid=(low+high)>>1;
        if(countPairs(arr,n,mid)<k){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return low;
}

int main(){
    int arr[]{1,3,4,1,3,8};
    cout<<kthDiff(arr,6,2)<<endl;

    int arr2[]{8,9};
    cout<<kthDiff(arr2,2,1)<<endl;
    return 0;
}