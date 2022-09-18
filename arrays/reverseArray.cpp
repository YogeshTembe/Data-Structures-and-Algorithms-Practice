#include<iostream>
using namespace std;

void reverseArray(int *a,int n){
    int temp=0;
    for(int i=0;i<(n/2);i++){
        temp=a[i];
        cout<<i<<" "<<n-1-i<<" "<<temp<<" "<<a[n-1-i]<<endl;
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    return;
}

int main(){
    int a[]={1,4,2,5,6};
    reverseArray(a,5);
    for(int i=0;i<5;i++){cout<<"t-"<<a[i]<<endl;}
    return 0;
}