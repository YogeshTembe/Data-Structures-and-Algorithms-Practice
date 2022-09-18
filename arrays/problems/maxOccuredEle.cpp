#include<iostream>
using namespace std;

int maxOccured(int L[], int R[], int n, int maxx){
    // Your code here
    
    int temp[maxx+1];
    for(int i=0;i<=maxx;i++){
        temp[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=L[i];j<=R[i];j++){
            temp[j]+=1;
        }
    }
    int max=0;
    int res=0;
    for(int i=maxx;i>=0;i--){
        //cout<<temp[i]<<endl;
        if(temp[i]>=max){max=temp[i];res=i;}
    }
    return res;
}

int main(){
    // int n = 2;
    // int L[] = {0,0};
    // int R[] = {1,1};
    int n = 5;
    int L[] = {1,5,9,13,21};
    int R[] = {15,8,12,20,30};
    cout<<maxOccured(L,R,n,30);
    return 0;
}