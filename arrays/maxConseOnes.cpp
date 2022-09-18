#include<iostream>
using namespace std;

int maxConsecutiveOnes(int a[],int n){
    int res=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            res++;
        }
        if(a[i]==0 && res>max){
            max=res;
            res=0;
        }
    }
    return max;
}

int main(){
    int a[]={1,0,1,1,1,0,0,1,1,1,1,0};
    cout<<maxConsecutiveOnes(a,12);
    return 0;
}