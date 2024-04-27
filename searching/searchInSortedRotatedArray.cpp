#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rightRotate(int arr[],int n,int d){
    int temp[d];
    cout<<d<<endl;
    for(int i=n-d;i<n;i++){
        cout<<arr[i]<<endl;
        temp[i-(n-d)]=arr[i];
    }
    print(temp,d);
    for(int i=n-d;i>=0;i--){
        arr[i+d]=arr[i];
    }
    for(int i=0;i<d;i++){
        arr[i]=temp[i];
    }
    print(arr,n);
}

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

//Naive solution
int searchInRotated(int arr[],int n,int ele){
    int minIndex=0;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[minIndex]){minIndex=i;}
    }
    if(minIndex!=0){
        cout<<minIndex<<endl;
        rightRotate(arr,n,n-minIndex);
    }
    int index=binarySearch(arr,n,ele);
    if(index-(n-minIndex) <= 0){
        return n-(index-(n-minIndex));
    }
    return index-(n-minIndex);
}

//Efficient solution
//Time complexity=O(logn)
int searchInRotated2(int arr[],int n,int ele){
    int low=0;
    int high=n-1;
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==ele){return mid;}
        if(arr[low]<arr[mid]){//left half is sorted
            if(arr[low]<=ele && arr[mid]>ele){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        else{//right half is sorted
            if(arr[mid]<ele && arr[high]>=ele){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;

}

int main(){
    int arr[]{10,20,30,40,8,9};
    cout<<searchInRotated2(arr,6,30);
    return 0;
}