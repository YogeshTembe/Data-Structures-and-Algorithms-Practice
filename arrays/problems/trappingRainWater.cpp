#include<iostream>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

long long trappingWater(int a[], int n){
    //precompute lmax and rmax
    int lmax[n];
    int rmax[n];
    lmax[0]=a[0];
    //lmax
    for(int i=1;i<n;i++){
        lmax[i]=a[i]>lmax[i-1]?a[i]:lmax[i-1];
    }
    print(lmax,n);
    rmax[n-1]=a[n-1];
    //rmax
    for(int i=n-2;i>=0;i--){
        rmax[i]=a[i]>rmax[i+1]?a[i]:rmax[i+1];
    }
    print(rmax,n);
    int res=0;
    for(int i=0;i<n;i++){
        res=res+(lmax[i]<rmax[i]?lmax[i]:rmax[i])-a[i];
    }
    return res;
}

int main(){
    int a[]{6,9,9};
    cout<<trappingWater(a,3);
    return 0;
}