#include<iostream>
using namespace std;

bool isFeasible(int arr[],int n,int studentsGiven,int ans){
    int studentsReq=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if((sum+arr[i])>ans){
            sum=arr[i];
            studentsReq++;
        }else{
            sum=sum+arr[i];
        }
    }
    return (studentsReq<=studentsGiven);
}

int findPages(int A[], int N, int M) 
{
    //code here
    if(N<M){
        return -1;
    }
    int max=INT_MIN;
    int sum=0;
    int res=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
        if(A[i]>max){max=A[i];}
    }
    int left=max;
    int right=sum;
    while(left<=right){
        int mid=(left+right)/2;
        cout<<mid<<endl;
        if(isFeasible(A,N,M,mid)){
            res=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return res;
}

int main(){
    int arr[]{15,10,19,10};
    cout<<findPages(arr,4,5);
    return 0;
}