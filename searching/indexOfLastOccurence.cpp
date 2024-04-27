#include<iostream>
using namespace std;

int indexOfLastOccurence(int arr[],int n,int ele){
    int low=0;
    int high=n-1;
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>ele){
            high=mid-1;
        }
        else if(arr[mid]<ele){
            low=mid+1;
        }
        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1]){return mid;}
            else{
                low=mid+1;
            }
        }
        //cout<<mid<<endl;
    }
    return -1;
}

int main(){
    int a[]{10,10,10,10,20,30,40};
    cout<<indexOfLastOccurence(a,7,20);
    return 0;
}