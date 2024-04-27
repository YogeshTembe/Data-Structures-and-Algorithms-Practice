#include<iostream>
using namespace std;

int closer(int arr[],int n, int x)
{
    //Your code here
    // for(int i=0;i<n-1;i++){
    //     if(arr[i]>arr[i+1]){
    //         int temp=arr[i];
    //         arr[i]=arr[i+1];
    //         arr[i+1]=temp;
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    int left=0;
    int right=n-1;
    while(left<right){
        int mid=(left+right)/2;
        cout<<left<<" "<<right<<" "<<mid<<endl;
        if(arr[mid]==x){
            return mid;
        }
        else if(mid!=0 && arr[mid-1]==x){
            return mid-1;
        }else if(mid!=n-1 && arr[mid+1]==x){
            return mid+1;
        }        
        else if(arr[mid]>x){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;
}

int main(){
    //int arr[]={2,1,4,3};
    int arr[]={3,2,10,4,40};
    cout<<closer(arr,5,40);
    return 0;
}