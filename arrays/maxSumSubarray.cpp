#include<iostream>
using namespace std;

//maximum sum from a subarray of consecutive elements
int maxSumSubarray(int a[],int n){
    int max=-1000;
    int res=0;
    for(int i=0;i<n;i++){
        res=0;
        if(a[i]>max){max=a[i];}
        for(int j=i;j<n;j++){
            res=res+a[j];
        }
        if(res>max){
            max=res;
        }
    }
    return max;
}

//efficient solution
int maxSumSubarray2(int a[],int n){
    int max[n];
    max[0]=a[0];
    int d=0;
    for(int i=1;i<n;i++){
        if((max[i-1]+a[i])>a[i]){
            max[i]=max[i-1]+a[i];
        }else{
            max[i]=a[i];
        }
        //cout<<a[i]<<" "<<max[i]<<endl;
    }
    int res=-1000;
    for(int i=0;i<n;i++){
        if(max[i]>res){
            res=max[i];
        }
    }
    return res;
}

int main(){
    int a[]={2,3,-8,7,-1,2,3};
    //int a[]={-6,-1,-8};
    cout<<maxSumSubarray2(a,7);
    return 0;
}