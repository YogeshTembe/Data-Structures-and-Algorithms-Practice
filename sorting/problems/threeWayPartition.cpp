#include<iostream>
#include<vector>
using namespace std;

void threeWayPartition(vector<int>& array,int a, int b)
{
    // code here 
    int left=0,mid=0,right=array.size()-1;
    while(mid<=right){
        if(array[mid]<a){
            swap(array[left],array[mid]);
            left++;
            mid++;
        }else if(array[mid]>=a && array[mid]<=b){
            mid++;
        }else if(array[mid]>b){
            swap(array[mid],array[right]);
            right--;
        }
    }
}

int main(){
    vector<int>arr={1, 2, 3};
    threeWayPartition(arr,1,3);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}