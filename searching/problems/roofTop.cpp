#include<iostream>
using namespace std;

int maxStep(int A[], int N)
{
    //Your code here
    int max=INT_MIN;
    int count=0;
    for(int i=0;i<N-1;i++){
        if(A[i+1]<=A[i]){
            if(count>max){
                max=count;
            }
            count=0;
        }else{
            cout<<A[i+1]<<" "<<A[i]<<" "<<count<<endl;
            count++;
        }
    }
    if(count>max){
        max=count;
    }
    return max;
}

int main(){
    //int arr[]{6,9,2,7,5,4,1,9};
    //int arr[]{1,2,2,3,2};
    int arr[]{5,7};
    cout<<maxStep(arr,2);
    return 0;
}