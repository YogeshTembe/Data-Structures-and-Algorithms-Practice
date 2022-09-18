#include<iostream>
using namespace std;

int longestEvenOddSubarray(int a[],int n){
    int res=1;
    int max=0;
    for(int i=1;i<n;i++){
        if(a[i-1]%2==0 && a[i]%2!=0){
            res++;
        }
        else if(a[i-1]%2!=0 && a[i]%2==0){
            res++;
        }
        else{
            if(res>max){
                max=res;
            }
            res=1;
        }
        cout<<a[i]<<" "<<res<<endl;
    }
    if(res>max){
        max=res;
    }
    return max;
}

int main(){
    //int a[]={7,10,13,14};
    //int a[]={10,1,2,3,4,3,3,2,3,4};
    int a[]={5,10,20,6,3,8};
    cout<<longestEvenOddSubarray(a,6);
    return 0;
}