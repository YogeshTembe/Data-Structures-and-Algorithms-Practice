#include<iostream>
using namespace std;

int binarySearch(int arr[],int low, int high, int ele){
    int left=low;
    int right=high;
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

//Search in infinite array means the array size is not given or size is too high that it will exceed time limit
//Efficient solution then binary search as for infinite array binary search will give TLE
//Time complexity = O(log(position)), where position is the index at which element is present
int searchInInfinite(int arr[],int ele){
    if(arr[0]==ele){return 0;}
    int i=1;
    while(arr[i]<ele){
        i=i*2;//we double the index everytime
    }
    if(arr[i]==ele){return i;}
    return binarySearch(arr,(i/2)+1,i-1,ele);//we search in between the indexes
}

int main(){
    int arr[]{10,333,456,800,1000,1040};
    cout<<searchInInfinite(arr,800);
    return 0;
}