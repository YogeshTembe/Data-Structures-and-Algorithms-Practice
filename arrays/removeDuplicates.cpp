#include<iostream>
using namespace std;

int removeDuplicates(int *a,int n){
    int res=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[res-1]){
            a[res]=a[i];
            res++;
        }
    }
    return res;
}

int main(){
    int a[]={1,2,2,3,3,3,4};
    cout<<removeDuplicates(a,7)<<endl;
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}