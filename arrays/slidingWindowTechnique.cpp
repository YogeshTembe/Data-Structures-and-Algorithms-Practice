#include<iostream>
using namespace std;

int maximumSumOfKElements(int a[],int n,int k){
    int max=0;
    int sum=0;
    for(int i=0;i<n-k;i++){
        sum=0;
        for(int j=i;j<(i+k);j++){
            sum=sum+a[j];
        }
        if(sum>max){max=sum;}
    }
    return max;
}

//Efficient solution
int maximumSumOfKElements2(int a[],int n,int k){
    int max=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(i<=k-1){
            sum=sum+a[i];
        }
        if(i>k-1){
            sum=sum-a[i-k];
            sum=sum+a[i];
            if(sum>max){max=sum;}
        }
        cout<<a[i]<<" "<<sum<<endl;
    }
    return max;
}

int main(){
    int a[]={1,8,30,-5,20,7};
    cout<<maximumSumOfKElements2(a,6,3);
    // int a[]={5,-10,6,90,3};
    // cout<<maximumSumOfKElements2(a,5,2);
    return 0;
}