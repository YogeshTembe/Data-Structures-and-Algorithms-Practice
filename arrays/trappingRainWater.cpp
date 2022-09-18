#include<iostream>
using namespace std;

int trappedRainWater(int a[],int n){
    int lmax=0;
    int rmax=0;
    int water=0;
    int pillar=0;
    for(int i=1;i<n-1;i++){
        lmax=0;
        rmax=0;
        for(int j=i-1;j>=0;j--){
            if(a[j]>lmax){
                lmax=a[j];
            }
        }
        for(int k=i+1;k<n;k++){
            if(a[k]>rmax){
                rmax=a[k];
            }
        }
        pillar=(lmax<rmax?lmax:rmax);
        cout<<pillar<<endl;
        if(a[i]<pillar){
            water=water+(pillar-a[i]);
        }
        cout<<a[i]<<water<<endl;
    }
    return water;
}


int trappedRainWater2(int a[],int n){
    int res=0;
    int lmax[n];
    int rmax[n];
    int pillar=0;
    lmax[0]=a[0];
    for(int i=1;i<n;i++){
        lmax[i]=(a[i]>lmax[i-1])?a[i]:lmax[i-1];
    }
    rmax[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=(a[i]>rmax[i+1])?a[i]:rmax[i+1];
    }
    
    for(int j=0;j<n;j++){
        cout<<lmax[j]<<" ";
        cout<<rmax[j]<<endl;
    }

    for(int i=1;i<n-1;i++){
        pillar=(lmax[i]<rmax[i])?lmax[i]:rmax[i];
        res=res+(pillar-a[i]);
    }
    return res;
    
}

int main(){
    int a[]={5,0,6,2,3};
    cout<<trappedRainWater2(a,5);
    return 0;
}