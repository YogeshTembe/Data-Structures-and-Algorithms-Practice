#include<iostream>
using namespace std;

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

//naive solution
int indexOfFirstOccurence(int arr[],int n,int ele){
    int index=binarySearch(arr,n,ele);
    //cout<<index<<endl;
    if(index!=-1){
        int i;
        for(i=index;i>=0;i--){
            //cout<<arr[i]<<endl;
            if(arr[i]!=ele){
                return i+1;
            }
        }
        return i+1;
    }else{ return -1; }
}

//Efficient recursive solution
int indexOfFirstOccurence2(int arr[],int low,int high,int ele){
    if(low>high){return -1;}
    int mid=(low+high)/2;
    if(arr[mid]<ele){return indexOfFirstOccurence2(arr,mid+1,high,ele);}
    else if(arr[mid]>ele){return indexOfFirstOccurence2(arr,low,mid-1,ele);}
    else{
        //mid==0 is to handle {10,10,10,10} such cases
        if(mid==0 || arr[mid]!=arr[mid-1]){
            return mid;
        }else{
            return indexOfFirstOccurence2(arr,low,mid-1,ele);
        }
    }
}

//Efficient iterative solution
int indexOfFirstOccurence3(int arr[],int n,int ele){
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

int main(){
    int a[]{10,10,10,10};
    cout<<indexOfFirstOccurence3(a,3,10);
    return 0;
}