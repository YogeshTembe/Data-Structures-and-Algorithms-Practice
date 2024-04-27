#include<iostream>
#include<cmath>
using namespace std;

// Function to find gcd of 2 numbers.
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

// get mid
int getMid(int s, int e) {
    return s + (e - s) / 2;
}

int constructST(int arr[], int st[], int ss, int se, int si) {
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid=getMid(ss,se);
    st[si] = gcd(constructST(arr,st,ss,mid,2*si+1),constructST(arr,st,mid+1,se,2*si+2));
    return st[si];
}

int *constructSegmentTree(int arr[], int n) {
    int height = (int) (ceil(log2(n)));
    int size = 2 * (int) pow(2, height) - 1;
    int *st = new int[size];
    constructST(arr, st, 0, n - 1, 0);
    return st;
}

int findRangeGcd2(int qs,int qe,int ss,int se,int si,int st[]){
    if(qs>se || qe<ss){ // outside
        return 0;
    }
    if(qs<=ss && qe>=se){ //inside
        return st[si];
    }
    int mid=getMid(ss,se);
    int val1=findRangeGcd2(qs,qe,ss,mid,2*si+1,st);
    int val2=findRangeGcd2(qs,qe,mid+1,se,2*si+2,st);
    if(val1==0){ return val2; }
    if(val2==0){ return val1; }
    return gcd(val1,val2);
}

//Function to find gcd of given range.
int findRangeGcd(int l, int r, int st[], int n) {
    // code here
    return findRangeGcd2(l,r,0,n-1,0,st);
}

void updateValue2(int ss,int se,int index,int si,int new_val,int st[],int *arr){
    if(index<ss || index>se){return;}
    if(ss==se && ss==index){
        st[si]=new_val;
        return;
    }
    if(ss<se){
        int mid=getMid(ss,se);
        updateValue2(ss,mid,index,2*si+1,new_val,st,arr);
        updateValue2(mid+1,se,index,2*si+2,new_val,st,arr);
        st[si]=gcd(st[2*si+1],st[2*si+2]);
    }
}
//Function to update a value in input array and segment tree.
void updateValue(int index, int new_val, int *arr, int st[], int n) {
    // code here
    updateValue2(0,n-1,index,0,new_val,st,arr);
}

int main(){
    int arr[] = {2,3,4,6,8,16};
    int n=6;
    int* st = constructSegmentTree(arr,n);
    int res = findRangeGcd(0,4,st,n);
    cout<<res<<endl;
    updateValue(3,8,arr,st,n);
    int res2 = findRangeGcd(2,5,st,n);
    cout<<res2<<endl;
    return 0;
}