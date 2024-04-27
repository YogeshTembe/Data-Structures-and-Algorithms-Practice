#include<iostream>
#include<algorithm>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    // code here 
    int i=n-1;
    int j=0;
    while(i>=0 && j<m){
        if(arr1[i]>arr2[j]){
            int temp=arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
            i--;
            j++;
        }else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
} 

int main(){
    int n = 4;
    long long arr1[] = {1,3,5,7}; 
    int m = 5;
    long long arr2[] = {0,2,6,8,9};
    merge(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<m;j++){
        cout<<arr2[j]<<" ";
    }
    cout<<endl;
    return 0;
}