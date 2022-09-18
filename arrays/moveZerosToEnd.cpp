#include<iostream>
using namespace std;

void moveZerosToEnd(int *a,int n){
    int temp;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<a[i]<<endl;
        if(a[i]==0){
            for(int j=i+1;j<n;j++){
                cout<<a[j]<<endl;
                if(a[j]!=0){
                    cout<<"swap"<<i<<" "<<j<<endl;
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;  
                    break;
                } 
            }
        }
        for(int j=0;j<10;j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    return;
}

//efficient solution
void moveZerosToEnd2(int *a,int n){
    int count=0;
    int temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            temp=a[i];
            a[i]=a[count];
            a[count]=temp;
            count++;
        }
    }
    return;
}
int main(){
    int a[]={0,2,3,0,6,0,1,0,0,0,7};
    moveZerosToEnd2(a,11);
    for(int j=0;j<10;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}