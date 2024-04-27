#include<iostream>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a,ll b){
    if(a==0 || b==0){return 0;}
    return (a*b)/__gcd(a,b);
}

int getMid(int ss,int se){
    return ss+(se-ss)/2;
}

ll constructSTHelper(int *arr,ll *st,int n,int ss,int se,int si){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid=(ss+se)/2;
    st[si]=lcm(constructSTHelper(arr,st,n,ss,mid,2*si+1),constructSTHelper(arr,st,n,mid+1,se,2*si+2));
    return st[si];
}

ll *constructST(int *arr,int n){
    int height = (int) (ceil(log2(n)));
    int size = 2 * (int) pow(2, height) - 1;
    ll *st = new ll[size];
    constructSTHelper(arr,st,n,0,n-1,0);
    return st;
}

ll getLCMHelper(ll *st,int *arr,int n,int qs,int qe,int ss,int se,int si){
    if(qs>se || qe<ss){ //outside
        return 1;
    }
    if(qs<=ss && qe>=se){
        return st[si];
    }
    int mid=getMid(ss,se);
    int val1=getLCMHelper(st,arr,n,qs,qe,ss,mid,2*si+1);
    int val2=getLCMHelper(st,arr,n,qs,qe,mid+1,se,2*si+2);
    return lcm(val1,val2);
}

//Function to find LCM of given range.
ll getLCM(ll *st, int *arr, int n, int qs, int qe) 
{
    // Code here
    return getLCMHelper(st,arr,n,qs,qe,0,n-1,0);
}

void updateValueHelper(int *arr,ll *st,int index,int new_val,int ss,int se,int si){
    if(index<ss || index>se){return;}
    if(index==ss && index==se){
        st[si]=new_val;
        return;
    }
    if(se>ss){
        cout<<ss<<" "<<si<<" "<<se<<endl;
        int mid=getMid(ss,se);
        cout<<mid<<endl;
        updateValueHelper(arr,st,index,new_val,ss,mid,2*si+1);
        updateValueHelper(arr,st,index,new_val,mid+1,se,2*si+2);
        cout<<"--here "<<si<<" "<<st[2*si+1]<<" "<<st[2*si+2]<<endl;
        st[si]=lcm(st[2*si+1],st[2*si+2]);
        cout<<"--after"<<endl;
    }
}

//Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    // Code here
    arr[index]=new_val;
    updateValueHelper(arr,st,index,new_val,0,n-1,0);
}

int main(){
    int arr[]={69,47,76,29,68,5,28,30,13,11,71,47,7,90,60,47,70,15,61,34,12,13,41,99,91,48,11,56,72,43};
    
    int n=30;
    ll *st=constructST(arr,n);
    cout<<getLCM(st,arr,n,1,2)<<endl;
    updateValue(arr,st,n,12,27);
    cout<<"---"<<endl;
    updateValue(arr,st,n,13,67);
    // cout<<getLCM(st,arr,n,1,2)<<endl;
    return 0;
}