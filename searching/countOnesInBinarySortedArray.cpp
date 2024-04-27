#include<iostream>
using namespace std;

//First Occurence
int indexOfFirstOccurence(int arr[],int n,int ele){
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<ele){low=mid+1;}
        else if(arr[mid]>ele){high=mid-1;}
        else{
            if(mid==0 || arr[mid]!=arr[mid-1]){return mid;} //here we found the element
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int countOccuBin(int arr[],int n, int ele){
    int first=indexOfFirstOccurence(arr,n,1);
    if(first==-1){
        return 0;
    }
    return n-first;
}

int main(){
    int arr[]{0,0,0,1,1,1,1};
    cout<<countOccuBin(arr,7,1);
}