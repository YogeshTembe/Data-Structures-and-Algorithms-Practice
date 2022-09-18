#include<iostream>
using namespace std;

void leftRotate(int *a,int n,int d){
    int b[n];
    for(int i=0;i<n;i++){
        if((i-d)<0){
            b[n-(d-i)]=a[i];
            continue;
        }
        b[i-d]=a[i];
    }
    for(int j=0;j<5;j++){
        cout<<b[j]<<" ";
    }
    cout<<endl;
}

void leftRotate2(int *a,int n){
    int temp=a[0];
    for(int i=1;i<n;i++){
        int pos=i-1;
        a[pos]=a[i];
    }
    a[n-1]=temp;
}

int main(){
    int a[]={2,3,4,5,6};
    //leftRotate(a,5,3);
    leftRotate2(a,5);
    for(int j=0;j<5;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}