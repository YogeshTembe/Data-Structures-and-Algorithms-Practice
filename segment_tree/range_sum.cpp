#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int getMid(int ss,int se){
    return (ss)+(se-ss)/2;
}

int constructSTHelper(int *arr,ll *st,int ss,int se,int si){
    if(ss==se){//base case
        st[si]=arr[ss];
        return st[si];
    }
    int mid=getMid(ss,se);
    st[si]=constructSTHelper(arr,st,ss,mid,2*si+1)+constructSTHelper(arr,st,mid+1,se,2*si+2);
    return st[si];
}

ll *constructST(int *arr,int n){
    int height = (int) (ceil(log2(n)));
    int size = 2 * (int) pow(2, height) - 1;
    ll *st = new ll[size];
    constructSTHelper(arr, st, 0, n - 1, 0);
    return st;
}

ll getRangeSum(ll *st,int qs,int qe,int ss,int se,int si){
    if(qs>se || qe<ss){
        return 0;
    }
    if(ss<=qs && se<=qe){
        return st[si];
    }
    int mid=getMid(ss,se);
    return getRangeSum(st,qs,qe,ss,mid,2*si+1)+getRangeSum(st,qs,qe,mid+1,se,2*si+2);
}

ll getsum(ll *st, int n, int l, int r)
{
    // add code here
    return getRangeSum(st,l,r,0,n-1,0);
}

void updateValueHelper(ll *st,int ss,int se,int si,int index,int diff){
    if(index<ss || index>se){
        return;
    }
    st[si]+=diff;
    if(se>ss){
        int mid=getMid(ss,se);
        updateValueHelper(st,ss,mid,2*si+1,index,diff);
        updateValueHelper(st,mid+1,se,2*si+2,index,diff);
    }
}

void updateValue(int *arr, ll *st, int n, int index, int new_val) 
{
    // add code here
    updateValueHelper(st,0,n-1,0,index,new_val-arr[index]);
    arr[index]=new_val;
}

int main(){
    int arr[]={1,3,5,7,9,11};
    int n=6;
    ll *st=constructST(arr,n);
    cout<<getsum(st,n,0,2)<<endl;
    cout<<getsum(st,n,0,5)<<endl;
    updateValue(arr,st,n,3,2);
    cout<<getsum(st,n,0,5)<<endl;    
    return 0;
}