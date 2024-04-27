#include<iostream>
using namespace std;

long long kSum(int a[],int n, int k)
{
    //Your code here
    long long sum=0;
    for(int i=0;i<k;i++){
        int min_indx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_indx]){
                min_indx=j;
            }
        }
        sum=sum+a[min_indx];
        swap(a[i],a[min_indx]);
    }
    //cout<<"--"<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return sum;
}

int main(){
    int arr[]{1,3,4,1,3,8};
    cout<<kSum(arr,6,2)<<endl;

    int arr2[]{5,5};
    cout<<kSum(arr2,2,2)<<endl;
    return 0;
}