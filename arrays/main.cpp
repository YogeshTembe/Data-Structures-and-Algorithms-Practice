#include<iostream>
using namespace std;

void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void deleteFromArray(int a[],int n,int val){
    int pos=0;
    for(int i=0;i<n;i++){
        if(a[i]==val){
            pos=i;
            break;
        }
    }
    for(int i=pos;i<n;i++){
        a[i]=a[i+1];
    }
}

int main(){
    int a[]={1,3,4,7,8};
    printArray(a,5);
    deleteFromArray(a,5,3);
    printArray(a,5);
    return 0;
}