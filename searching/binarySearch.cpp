#include<iostream>
using namespace std;

//iterative solution
int binarySearch(int arr[],int n, int ele){
    int left=0;
    int right=n-1;
    int mid=(left+right)/2;
    while(left<=right){
        if(arr[mid]==ele){return mid;}
        if(arr[mid]>ele){
            right=mid-1;
            mid=(left+right)/2;
        }
        if(arr[mid]<ele){
            left=mid+1;
            mid=(left+right)/2;
        }
    }
    return -1;
}

//recursive solution
int binarySearch2(int arr[],int n, int ele, int mid, int left, int right){
    if(left>right){
        return -1;
    }
    if(arr[mid]==ele){
        return mid;
    }
    if(arr[mid]>ele){
        return binarySearch2(arr,n,ele,(left+mid-1)/2,mid-1,right);
    }
    if(arr[mid]<ele){
        return binarySearch2(arr,n,ele,(right+mid+1)/2,left,mid+1);
    }
    return -1;
}

int main(){
    int a[]{10,20,30,40,50};
    cout<<binarySearch(a,5,40)<<endl;
    cout<<binarySearch2(a,5,40,2,0,4)<<endl;
    return 0;
}